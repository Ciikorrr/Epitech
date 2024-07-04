{-
-- EPITECH PROJECT, 2024
-- B-FUN-400-BDX-4-1-wolfram-marius.marolleau
-- File description:
-- main
-}
module Main where
import System.Environment
import Data.Monoid (Last(Last))
import Data.Maybe (fromJust)
import Parser
import Patern
import Display
import Algo

main :: IO ()
main = do
  args <- getArgs
  checkArg args
  argsIsNum args
  let arg = getOpts defaultConf args
  checkError arg
  let zerodisplay = floor(fromIntegral((window (fromJust arg)) - 1) / 2)
  let newzipper = createZipperFromList [1] (window (fromJust arg))
  checkStart zerodisplay newzipper arg