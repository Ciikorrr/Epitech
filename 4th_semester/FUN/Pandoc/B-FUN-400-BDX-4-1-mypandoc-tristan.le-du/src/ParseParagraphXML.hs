{-
-- EPITECH PROJECT, 2024
-- B-FUN-400-BDX-4-1-mypandoc-tristan.le-du
-- File description:
-- PandocAlgo
-}

module ParseParagraphXML (parseParagraph) where
import DataPandoc(Segment(..), TTypes(..))
import Utils (parseTag, createText)
import Parser (parseSome, parseAnyChar)
import Data.Maybe (fromJust)

createBold :: String -> String -> IO (TTypes, String)
createBold [] str = return (Bold (Text str), [])
createBold ('<':xs) str = return (Bold (Text str), '<':xs)
createBold (x:xs) str = createBold xs (str <> [x])

createItalic :: String -> String -> IO (TTypes, String)
createItalic [] str = return (Italic (Text str), [])
createItalic ('<':xs) str = return (Italic (Text str), '<':xs)
createItalic (x:xs) str = createItalic xs (str <> [x])

createCode :: String -> String -> IO (TTypes, String)
createCode [] str = return (Code (Text str), [])
createCode ('<':xs) str = return (Code (Text str), '<':xs)
createCode (x:xs) str = createCode xs (str <> [x])

parseBold :: String -> IO (TTypes, String)
parseBold (x:xs) = createBold (x:xs) []
parseBold _ = return (Text [], [])

parseItalic :: String -> IO (TTypes, String)
parseItalic (x:xs) = createItalic (x:xs) []
parseItalic _ = return (Text [], [])

parseCode :: String -> IO (TTypes, String)
parseCode (x:xs) = createCode (x:xs) []
parseCode _ = return (Text [], [])

createImage :: String -> String -> String -> IO (TTypes, String)
createImage url [] str = return (Image url (Text str), [])
createImage url ('<':xs) str = return (Image url (Text str), '<':xs)
createImage url (x:xs) str = createImage url xs (str <> [x])

parseImage :: String -> String -> IO (TTypes, String)
parseImage args str = do
    let url =
            tail (init(snd (fromJust(parseSome (parseAnyChar "url=") args))))
    (image, newStr) <- createImage url str []
    return (image, newStr)

createLink :: String -> String -> String -> IO (TTypes, String)
createLink url [] str = return (Link url (Text str), [])
createLink url ('<':xs) str = return (Link url (Text str), '<':xs)
createLink url (x:xs) str = createLink url xs (str <> [x])

parseLink :: String -> String -> IO (TTypes, String)
parseLink args str = do
    let url =
            tail (init(snd (fromJust(parseSome (parseAnyChar "url=") args))))
    (image, newStr) <- createLink url str []
    return (image, newStr)

paragraphTagsTwo :: ((String, String), String) -> IO (TTypes, String)
paragraphTagsTwo (("code", _), str) = parseCode str
paragraphTagsTwo (("image", xs), str) = parseImage xs str
paragraphTagsTwo (("/image", _), str) = return (Text [], str)
paragraphTagsTwo (("link", xs), str) = parseLink xs str
paragraphTagsTwo (("/link", _), str) = return (Text [], str)
paragraphTagsTwo (("/paragraph", _), str) = return (Bold (Text []), str)
paragraphTagsTwo ((_, _), str) = return (Bold (Text []), str)

paragraphTags :: ((String, String), String) -> IO (TTypes, String)
paragraphTags (("bold", _), str) = parseBold str
paragraphTags (("italic", _), str) = parseItalic str
paragraphTags (("/italic", _), str) = return (Text [], str)
paragraphTags (("/code", _), str) = return (Text [], str)
paragraphTags (("/bold", _), str) = return (Text [], str)
paragraphTags tuple = paragraphTagsTwo tuple

parseParagraph :: String -> Segment -> IO (Segment, String)
parseParagraph ('<':xs) (Paragraph tab) = do
    let (tags, newStr) = parseTag xs []
    (tt, str) <- paragraphTags (tags, newStr)
    case tt of
        Text [] -> parseParagraph str (Paragraph tab)
        Bold (Text []) -> return (Paragraph tab, str)
        _ -> parseParagraph str (Paragraph (tab ++ [tt]))
parseParagraph (x:xs) (Paragraph tab)  =
    let (Text str, newStr) = createText (x:xs) []
    in parseParagraph newStr (Paragraph (tab ++ [Text str]))
parseParagraph _ _ = return (Paragraph [], [])
