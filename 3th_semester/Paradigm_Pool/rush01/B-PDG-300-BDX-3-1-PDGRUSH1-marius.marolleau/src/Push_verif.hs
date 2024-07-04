{-
-- EPITECH PROJECT, 2022
-- $PROJECT_NAME
-- File description:
-- $DESCRIPTION
-}

module Push_verif (
    checkLists,
) where

import System.Exit (exitWith, ExitCode(ExitFailure))
import System.IO
import GHC.IO
import GHC.IO.Exception

isSorted :: Ord a => [a] -> Bool
isSorted [] = True
isSorted [x] = True
isSorted (x:y:xs) = x <= y && isSorted (y:xs)

checkLists :: Ord a => ([a], [b]) -> IO ()
checkLists (_, _:_) =  putStrLn "KO" >> exitWith ExitSuccess
checkLists (lst1, [])
    | isSorted lst1 =  putStrLn "OK" >> exitWith ExitSuccess
    | otherwise     = putStrLn "KO" >> exitWith ExitSuccess
