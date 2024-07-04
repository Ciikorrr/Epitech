{--
-- EPITECH PROJECT, 2024
-- Untitled (Workspace)
-- File description:
-- ConvertFile
--}

module ConvertFile (
    headerToFormat,
    -- docContentToString,
    headerToMarkdown
) where

import DataPandoc (Header(..), Document(..))

documentToXML :: Document -> String
documentToXML document = concat
    [ "<document>\n"
    , headerToXML (docHeader document)
    , "\n</document>"
    ]

headerToXML :: Header -> String
headerToXML header = concat
    [ "<header title=\"" ++ title header ++ "\">\n"
    , case author header of
        Just auth -> "  <author>" ++ auth ++ "</author>\n"
        Nothing -> ""
    , case date header of
        Just da -> "  <date>" ++ da ++ "</date>\n"
        Nothing -> ""
    , "</header>"
    ]

removeTrailingComma :: String -> String
removeTrailingComma str
    | null str = str
    | last (filter (/=' ') str) == ',' = init str
    | otherwise = str

headerToJSON :: Header -> String
headerToJSON header =
    let headerStr = concat
            [ "\"title\": \"" ++ title header ++ "\""
            , case author header of
                Just auth -> ",\n\"author\": \"" ++ auth ++ "\""
                Nothing -> ""
            , case date header of
                Just da -> ",\n\"date\": \"" ++ da ++ "\""
                Nothing -> ""]
    in "{\n\"header\": {\n" ++ removeTrailingComma headerStr ++ "\n}\n}"

headerToMarkdown :: Header -> String
headerToMarkdown header = concat
    [ "---\n", "title: " ++ title header ++ "\n", case author header of
        Just auth -> "author: " ++ auth ++ "\n"
        Nothing -> ""
    , case date header of
        Just da -> "date: " ++ da ++ "\n"
        Nothing -> ""
    , "---\n\n"
    ]

headerToFormat :: Header -> String -> FilePath -> IO ()
headerToFormat header "markdown" "" = putStr (headerToMarkdown header)
headerToFormat header "xml" "" = putStr (headerToXML header)
headerToFormat header "json" "" = putStr (headerToJSON header)
headerToFormat header "xml" outFile = appendFile outFile (headerToXML header)
headerToFormat header "json" outFile = appendFile outFile (headerToJSON header)
headerToFormat header "markdown" outFile =
    writeFile outFile "" >> appendFile outFile (headerToMarkdown header)
headerToFormat _ _ _ = putStrLn "Unsupported format"