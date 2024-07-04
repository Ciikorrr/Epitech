{-
-- EPITECH PROJECT, 2024
-- B-FUN-400-BDX-4-1-mypandoc-tristan.le-du
-- File description:
-- DataPandoc
-}

module DataPandoc (
    Pandoc(..),
    Document(..),
    Header(..),
    TTypes(..),
    Segment(..)
 ) where

data Pandoc = Pandoc {
    ifile::String,
    oformat::String,
    ofile::String,
    iformat::String,
    fileParsed::[String]
} deriving (Show)

data TTypes = Text String
            | Bold TTypes
            | Italic TTypes
            | Code TTypes
            | Image String TTypes
            | Link String TTypes
            deriving (Show, Eq)

data Segment = Paragraph [TTypes]
            | CodeBlock [Segment]
            | Section (Maybe String) [Segment]
            | List [Segment]
            deriving (Show)

data Header = Header {
    title::String,
    author::Maybe String,
    date::Maybe String
} deriving (Show)

data Document = Document {
    docHeader::Header,
    docContent::[Segment]
} deriving (Show)
