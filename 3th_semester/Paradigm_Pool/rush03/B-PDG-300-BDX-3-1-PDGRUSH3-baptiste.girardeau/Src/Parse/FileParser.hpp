/*
** EPITECH PROJECT, 2024
** rush3
** File description:
** Parser
*/

#pragma once

#include <functional>
#include <map>
#include <optional>
#include <string>

class FileParser {
   public:
    FileParser(std::string path, char delimiter, bool valueHasQuotes,
               bool stripKey, bool stripValue);

    std::optional<std::string> get(const std::string &key) {
        if (_map.find(key) == _map.end()) {
            return std::nullopt;
        }

        return _map[key];
    }

    template <typename T>
    std::optional<T> get(
        const std::string &key,
        std::function<std::optional<T>(const std::string&)> converter) {
        if (_map.find(key) == _map.end()) {
            return std::nullopt;
        }

        return converter(_map[key]);
    }

   private:
    void parseFile();
    static std::string stripBeginEnd(const std::string &str, char delimiter);

    std::map<std::string, std::string> _map;
    std::string _path;
    char _delimiter = '=';
    bool _valueHasQuotes = true;
    bool _stripKey = true;
    bool _stripValue = true;
};

class FileParserBuilder {
   public:
    FileParserBuilder(std::string path);
    FileParser parse();

    FileParserBuilder &setDelimiter(char delimiter);
    FileParserBuilder &valueHasQuotes(bool valueHasQuotes);
    FileParserBuilder &stripKey(bool stripKey);
    FileParserBuilder &stripValue(bool stripValue);

   private:
    std::string _path;
    char _delimiter = '=';
    bool _valueHasQuotes = false;
    bool _stripKey = true;
    bool _stripValue = true;
};
