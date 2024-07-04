/*
** EPITECH PROJECT, 2024
** rush3
** File description:
** FileParser
*/

#include "FileParser.hpp"

#include <fstream>
#include <utility>

FileParser::FileParser(std::string path, char delimiter, bool valueHasQuotes,
                       bool stripKey, bool stripValue)
    : _path(std::move(path)),
      _delimiter(delimiter),
      _valueHasQuotes(valueHasQuotes),
      _stripKey(stripKey),
      _stripValue(stripValue) {
    parseFile();
}

void FileParser::parseFile() {
    std::ifstream file(_path);
    std::string line;

    while (std::getline(file, line)) {
        size_t delimiterPos = line.find(_delimiter);
        std::string key = line.substr(0, delimiterPos);
        std::string value = line.substr(delimiterPos + 1);

        if (_stripKey) {
            key = stripBeginEnd(key, ' ');
            key = stripBeginEnd(key, '\t');
        }
        if (_stripValue) {
            value = stripBeginEnd(value, ' ');
            value = stripBeginEnd(value, '\t');
        }
        if (_valueHasQuotes) {
            value = stripBeginEnd(value, '"');
        }

        _map[key] = value;
    }
}

std::string FileParser::stripBeginEnd(const std::string &str, char delimiter) {
    size_t begin = str.find_first_not_of(delimiter);
    size_t end = str.find_last_not_of(delimiter);

    if (begin == std::string::npos || end == std::string::npos) {
        return "";
    }

    return str.substr(begin, end - begin + 1);
}

FileParserBuilder::FileParserBuilder(std::string path)
    : _path(std::move(path)) {}

FileParser FileParserBuilder::parse() {
    return {_path, _delimiter, _valueHasQuotes, _stripKey, _stripValue};
}

FileParserBuilder &FileParserBuilder::setDelimiter(char delimiter) {
    _delimiter = delimiter;
    return *this;
}

FileParserBuilder &FileParserBuilder::valueHasQuotes(bool valueHasQuotes) {
    _valueHasQuotes = valueHasQuotes;
    return *this;
}

FileParserBuilder &FileParserBuilder::stripKey(bool stripKey) {
    _stripKey = stripKey;
    return *this;
}

FileParserBuilder &FileParserBuilder::stripValue(bool stripValue) {
    _stripValue = stripValue;
    return *this;
}
