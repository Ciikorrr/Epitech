{-
-- EPITECH PROJECT, 2024
-- B-PDG-300-BDX-3-1-PDGRUSH1-marius.marolleau
-- File description:
-- operationsSender
-}

module OperationsSender (
    operationsSender,
) where

import Ope
import Push_verif
import System.Exit

operationsSender :: Ord a => ([a], [a]) -> [String] -> IO ()
operationsSender tuple [] = checkLists tuple
operationsSender tuple (x:xs) = firstFunctionsHandler tuple (x:xs)

firstFunctionsHandler :: Ord a => ([a], [a]) -> [String] -> IO ()
firstFunctionsHandler tuple ("sa":xs) = operationsSender (mySa tuple) xs
firstFunctionsHandler tuple ("sb":xs) = operationsSender (mySb tuple) xs
firstFunctionsHandler tuple ("pa":xs) = operationsSender (myPa tuple) xs
firstFunctionsHandler tuple ("pb":xs) = operationsSender (myPb tuple) xs
firstFunctionsHandler tuple ("ra":xs) = operationsSender (myRa tuple) xs
firstFunctionsHandler tuple ("sc":xs) = operationsSender (mySc tuple) xs
firstFunctionsHandler tuple (x:xs) = secondFunctionsHandler tuple (x:xs)

secondFunctionsHandler :: Ord a => ([a], [a]) -> [String] -> IO ()
secondFunctionsHandler tuple ("rb":xs) = operationsSender (myRb tuple) xs
secondFunctionsHandler tuple ("rr":xs) = operationsSender (myRr tuple) xs
secondFunctionsHandler tuple ("rra":xs) = operationsSender (myRra tuple) xs
secondFunctionsHandler tuple ("rrb":xs) = operationsSender (myRrb tuple) xs
secondFunctionsHandler tuple ("rrr":xs) = operationsSender (myRrr tuple) xs
secondFunctionsHandler tuple (_:xs) = exitWith (ExitFailure 84)
