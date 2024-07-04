{-
-- EPITECH PROJECT, 2024
-- B-FUN-400-BDX-4-1-mypandoc-tristan.le-du
-- File description:
-- ParseHeaderXML
-}

module ParseHeaderXML (parseHeader, titleParse) where

import DataPandoc (Header(..), TTypes(..))
import Utils (parseTag, createText)
import Data.Maybe (fromJust)
import Parser (parseSome, parseAnyChar)

headersTags :: ((String, String), String) -> Header -> IO (Header, String)
headersTags (("author", _), str) header =
    let (Text text, newStr) = createText str []
    in return (header {author = Just text}, newStr)
headersTags (("/author", _), str) header = return (header, str)
headersTags (("date", _), str) header =
    let (Text text, newStr) = createText str []
    in return (header {date = Just text}, newStr)
headersTags (("/date", _), str) header = return (header, str)
headersTags (("/header", _), str) header =
    return (header {title = "NULL"}, str)
headersTags _ header = return (header, [])

parseHeader :: String -> Header -> IO (Header, String)
parseHeader ('<':xs) header = do
    let (tags, newStr) = parseTag xs []
    (h, str) <- headersTags (tags, newStr) header
    case title h of
        "NULL" -> return (header, str)
        _ -> parseHeader str h
parseHeader (_:xs) header = parseHeader xs header
parseHeader str header = return (header, str)

titleParse :: String -> String -> IO (Header, String)
titleParse args str = do
    let t =
            tail (init(snd (fromJust(parseSome (parseAnyChar "title=") args))))
    let header = Header {title = t,
    author = Nothing, date = Nothing}
    (h, newStr) <- parseHeader str header
    return (h, newStr)
