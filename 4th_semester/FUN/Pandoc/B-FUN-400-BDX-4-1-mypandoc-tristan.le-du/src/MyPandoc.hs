{-
-- EPITECH PROJECT, 2024
-- B-FUN-400-BDX-4-1-mypandoc-tristan.le-du
-- File description:
-- MyPandoc
-}

module MyPandoc (mainAlgo) where

import DataPandoc (Document(..), Segment(..))
import Utils (parseTag)
import ParseHeaderXML (titleParse)
import ParseParagraphXML (parseParagraph)
import ParserSegments (titleSection, parseCodeBlock, parseList)

tagsTwo :: ((String, String), String) -> Document -> IO (Document, String)
tagsTwo (("list", _), str) doc = do
    (list, newStr) <- parseList str (List [])
    return (doc {docContent = docContent doc ++ [list]}, newStr)
tagsTwo (("codeblock", _), str) doc = do
    (code, newStr) <- parseCodeBlock str (CodeBlock [])
    return (doc {docContent = docContent doc ++ [code]}, newStr)
tagsTwo (_, str) doc = return (doc, str)

segmentsTags :: ((String, String), String) -> Document -> IO (Document, String)
segmentsTags (("header", xs), str) doc = do
    (h, newStr) <- titleParse xs str
    return (doc {docHeader = h}, newStr)
segmentsTags (("paragraph", _), str) doc = do
    (para, newStr) <-  parseParagraph str (Paragraph [])
    return (doc {docContent = docContent doc ++ [para]}, newStr)
segmentsTags (("section", xs), str) doc = do
    (sect, newStr) <- titleSection xs str
    return (doc {docContent = docContent doc ++ [sect]}, newStr)
segmentsTags tuple doc = tagsTwo tuple doc

mainAlgo :: String -> Document -> IO Document
mainAlgo [] document = return document
mainAlgo ('<':xs) document = do
    let (tags, newStr) = parseTag xs []
    (docu, str) <- segmentsTags (tags, newStr) document
    mainAlgo str docu
mainAlgo (_:xs) document = mainAlgo xs document