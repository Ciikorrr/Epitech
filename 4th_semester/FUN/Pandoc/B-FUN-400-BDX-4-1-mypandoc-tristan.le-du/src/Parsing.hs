{-
-- EPITECH PROJECT, 2024
-- B-FUN-400-BDX-4-1-mypandoc-tristan.le-du
-- File description:
-- Parsing
-}

module Parsing (
    getFlags,
    defaultPandoc,
    checkError,
) where

import DataPandoc (Pandoc(..))
import System.Exit

defaultPandoc :: Pandoc
defaultPandoc = Pandoc {
    ifile = "",
    oformat = "",
    ofile = "",
    iformat = "",
    fileParsed = []
    }

checkError :: Pandoc -> IO ()
checkError (Pandoc "" _ _ _ _ ) = exitWith (ExitFailure 84)
checkError (Pandoc _ "" _ _ _ ) = exitWith (ExitFailure 84)
checkError (Pandoc _ outputformat _ inputformat _)
  | (outputformat /= "xml" &&
  outputformat /= "json" &&
  outputformat /= "markdown") ||
  (inputformat /= "xml" &&
  inputformat /= "json" &&
  inputformat /= "markdown" &&
  inputformat /= "") = exitWith (ExitFailure 84)
  | otherwise = return ()

getFlags :: Pandoc -> [String] -> Pandoc
getFlags dataStruct [] = dataStruct
getFlags dataStruct ("-i":x1:xs) =
    getFlags (dataStruct {ifile = x1}) xs
getFlags dataStruct ("-f":x1:xs) =
    getFlags (dataStruct {oformat = x1}) xs
getFlags dataStruct ("-o":x1:xs) =
    getFlags (dataStruct {ofile = x1}) xs
getFlags dataStruct ("-e":x1:xs) =
    getFlags (dataStruct {iformat = x1}) xs
getFlags dataStruct _ = dataStruct
