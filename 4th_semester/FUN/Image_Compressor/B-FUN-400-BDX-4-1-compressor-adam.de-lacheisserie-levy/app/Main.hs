{-
-- EPITECH PROJECT, 2024
-- B-PDG-300-BDX-3-1-PDGD03-adam.de-lacheisserie-levy
-- File description:
-- haskell
-}

import System.Environment
import System.IO
import Data.Maybe (fromJust)

import Parsing (getFlags, defaultComp, checkError)
import ParseFile (parseContentFile)
import CompressorData(Compressor(..))

main :: IO ()
main = do
  args <- getArgs
  let maybeDataComp = getFlags defaultComp args
  checkError maybeDataComp
  let dataComp = fromJust maybeDataComp
  fd <- openFile (filePath dataComp) ReadMode
  content <- hGetContents fd
  parseContentFile content (colors dataComp) (convergence dataComp)