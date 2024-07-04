{-
-- EPITECH PROJECT, 2024
-- B-FUN-400-BDX-4-1-mypandoc-tristan.le-du
-- File description:
-- ParserSegment
-}

module ParserSegments (
    titleSection,
    parseCodeBlock,
    parseList
) where
import Utils (parseTag)
import DataPandoc (Segment(..))
import ParseParagraphXML (parseParagraph)
import Data.Maybe (fromJust)
import Parser (parseSome, parseAnyChar)

sectionTags :: ((String, String), String) -> IO (Segment, String)
sectionTags (("paragraph", _), str) = parseParagraph str (Paragraph [])
sectionTags (("list", _), str) = parseList str (List [])
sectionTags (("codeblock", _), str) = parseCodeBlock str (CodeBlock [])
sectionTags (("section", xs), str) = titleSection xs str
sectionTags (("/section", _), str) = return (Paragraph [], str)
sectionTags ((_, _), str) = return (Paragraph [], str)

parseSection :: String -> Segment -> IO (Segment, String)
parseSection ('<':xs) (Section t tab) = do
    let (tags, newStr) = parseTag xs []
    (seg, str) <- sectionTags (tags, newStr)
    case seg of
        Paragraph [] -> return (Section t tab, str)
        _ -> parseSection str (Section t (tab ++ [seg]))
parseSection (_:xs) section = parseSection xs section
parseSection _ section = return (section, [])

titleSection :: String -> String -> IO (Segment, String)
titleSection args str = do
    let title =
            tail (init(snd (fromJust(parseSome (parseAnyChar "title=") args))))
    let section = Section (Just title) []
    (sect, newStr) <- parseSection str section
    return (sect, newStr)

codeTags :: ((String, String), String) -> IO (Segment, String)
codeTags (("paragraph", _), str) = parseParagraph str (Paragraph [])
codeTags (("section", xs), str) = titleSection xs str
codeTags (("list", _), str) = parseList str (List [])
codeTags (("/codeblock", _), str) = return (Paragraph [], str)
codeTags ((_, _), str) = return (Paragraph [], str)

parseCodeBlock :: String -> Segment -> IO (Segment, String)
parseCodeBlock ('<':xs) (CodeBlock tab) = do
    let (tags, newStr) = parseTag xs []
    (code, str) <- codeTags (tags, newStr)
    case code of
        Paragraph [] -> return (CodeBlock tab, str)
        _ -> parseCodeBlock str (CodeBlock (tab ++ [code]))
parseCodeBlock (_:xs) code = parseCodeBlock xs code
parseCodeBlock _ code = return (code, [])

listTags :: ((String, String), String) -> IO (Segment, String)
listTags (("paragraph", _), str) = parseParagraph str (Paragraph [])
listTags (("section", xs), str) = titleSection xs str
listTags (("codeblock", _), str) = parseCodeBlock str (CodeBlock [])
listTags (("list", _), str) = parseList str (List [])
listTags (("/list", _), str) = return (Paragraph [], str)
listTags ((_, _), str) = return (Paragraph [], str)

parseList :: String -> Segment -> IO (Segment, String)
parseList ('<':xs) (List tab) = do
    let (tags, newStr) = parseTag xs []
    (list, str) <- listTags (tags, newStr)
    case list of
        Paragraph [] -> return (List tab, str)
        _ -> parseList str (List (tab ++ [list]))
parseList (_:xs) list = parseList xs list
parseList _ list = return (list, [])