{-
-- EPITECH PROJECT, 2024
-- B-FUN-400-BDX-4-1-mypandoc-tristan.le-du
-- File description:
-- Utils
-}

module Utils(parseTag, createText) where

import DataPandoc(TTypes(..))

findTag :: String -> String -> (String, String)
findTag [] tagType = (tagType, "")
findTag (' ':xs) tagType = (tagType, xs)
findTag (x:xs) tagType = findTag xs (tagType <> [x])

parseTag :: String -> String -> ((String, String), String)
parseTag ('>':xs) newStr = (findTag newStr [], xs)
parseTag (x:xs) newStr = parseTag xs (newStr <> [x])
parseTag _ _ = (([], []), [])

createText :: String -> String -> (TTypes, String)
createText [] str = (Text str, [])
createText ('<':xs) str = (Text str, '<':xs)
createText (x:xs) str = createText xs (str <> [x])