{-
-- EPITECH PROJECT, 2024
-- B-PDG-300-BDX-3-1-PDGD03-adam.de-lacheisserie-levy
-- File description:
-- haskell
-}

module Parsing (
    getFlags,
    defaultComp,
    checkError
) where

import CompressorData (Compressor(..))
import Data.Char (isDigit)
import System.Exit
import Data.Maybe (fromJust)

defaultComp :: Compressor
defaultComp =
  Compressor{
    colors = -1,
    convergence = -1,
    filePath = ""
  }

checkError :: Maybe Compressor -> IO ()
checkError Nothing = exitWith (ExitFailure 84)
checkError con | (colors (fromJust con) == -1) ||
  (convergence (fromJust con) == -1) ||
  (filePath (fromJust con) == "") = exitWith (ExitFailure 84)
  | otherwise = return ()

isStringDigit :: String -> Bool
isStringDigit [] = True
isStringDigit (x:xs) | isDigit x = isStringDigit xs
  | otherwise = False

getFlags :: Compressor -> [String] -> Maybe Compressor
getFlags dataStruct [] = Just dataStruct
getFlags dataStruct ("-n":x1:xs) | isStringDigit x1 =
    getFlags (dataStruct {colors = read x1 :: Int}) xs
    | otherwise = Nothing
getFlags dataStruct ("-l":x1:xs) =
    getFlags (dataStruct {convergence = read x1 :: Float}) xs
getFlags dataStruct ("-f":x1:xs) =
    getFlags (dataStruct {filePath = x1}) xs
getFlags _ _ = Nothing