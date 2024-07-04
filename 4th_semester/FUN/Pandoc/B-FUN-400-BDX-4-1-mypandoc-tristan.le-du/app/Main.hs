{-
-- EPITECH PROJECT, 2024
-- B-FUN-400-BDX-4-1-mypandoc-tristan.le-du
-- File description:
-- Main
-}

module Main (main) where

import System.IO

import DataPandoc(Pandoc(..), Document(..), Header(..))
import Display (displayDocument)
import Parsing (getFlags, defaultPandoc, checkError)
import System.Environment
import ConvertFile (headerToFormat)
import MyPandoc (mainAlgo)

setDocument :: Document
setDocument = Document {
  docHeader = Header {
    title = "",
    author = Nothing,
    date = Nothing
},
  docContent = []
}

main :: IO ()
main = do
  args <- getArgs
  let dataPandoc = getFlags defaultPandoc args
  checkError dataPandoc
  fd <- openFile (ifile dataPandoc) ReadMode
  content <- hGetContents fd
  let document = setDocument
  docu <- mainAlgo content document
  headerToFormat (docHeader docu) (oformat dataPandoc) (ofile dataPandoc) 
  displayDocument (docContent docu) (ofile dataPandoc)
