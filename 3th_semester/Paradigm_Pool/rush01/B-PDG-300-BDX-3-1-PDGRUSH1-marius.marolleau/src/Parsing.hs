{-
-- EPITECH PROJECT, 2024
-- B-PDG-300-BDX-3-1-PDGRUSH1-marius.marolleau
-- File description:
-- parsing
-}

module Parsing (
    parseArgs,
    makeTupleArray,
    checkArgs,
    checkEmptyArray
) where

import Data.Char (isDigit)
import System.Exit

parseArgs :: [String] -> [Int]
parseArgs [] = []
parseArgs (x:xs) = [(read x :: Int)] ++ parseArgs xs

makeTupleArray :: [a] -> ([a], [a])
makeTupleArray [] = ([], [])
makeTupleArray (x:xs) = ((x:xs), [])

checkString :: String -> Bool
checkString [] = True
checkString ('-':xs) = checkString xs
checkString (x:xs) | isDigit x = checkString xs
  | otherwise = False

checkArgs :: [String] -> IO ()
checkArgs [] = return ()
checkArgs (x:xs) | checkString x = checkArgs xs
  | otherwise = exitWith (ExitFailure 84)

checkEmptyArray :: [String] -> IO ()
checkEmptyArray [] = exitWith (ExitFailure 84)
checkEmptyArray array = return ()
