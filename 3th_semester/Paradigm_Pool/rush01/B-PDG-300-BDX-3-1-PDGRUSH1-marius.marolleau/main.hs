{-
-- EPITECH PROJECT, 2024
-- B-PDG-300-BDX-3-1-PDGRUSH1-marius.marolleau
-- File description:
-- main function of the rush
-}

import System.Environment
import System.Exit
import OperationsSender
import Parsing (checkArgs, parseArgs, makeTupleArray, checkEmptyArray)

main :: IO ()
main = do
  args <- getArgs
  checkEmptyArray args
  checkArgs args
  let intArray = parseArgs args
  let tupleArray = makeTupleArray intArray
  operations <- getLine
  operationsSender tupleArray (words operations)