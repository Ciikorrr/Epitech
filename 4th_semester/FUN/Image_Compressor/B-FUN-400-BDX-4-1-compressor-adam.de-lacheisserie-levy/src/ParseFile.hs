{-
-- EPITECH PROJECT, 2024
-- B-PDG-300-BDX-3-1-PDGD03-adam.de-lacheisserie-levy
-- File description:
-- haskell
-}

module ParseFile (
  parseContentFile
) where

import CompressorData(RGB(..))
import ImgCompressor (imgCompressor)
import Data.Char
import Data.Set (fromList, toList)
import System.Exit

checkIsEmpty :: [RGB] -> IO ()
checkIsEmpty [] = exitWith (ExitFailure 84)
checkIsEmpty _ = return ()

parseLine :: String -> String -> [String] -> [String]
parseLine [] [] finalStr = finalStr
parseLine [] stringInP finalStr = stringInP : finalStr
parseLine ('\n':xs) stringInP finalStr =
  parseLine xs [] (stringInP : finalStr)
parseLine (x:xs) stringInP finalStr = parseLine xs (stringInP <> [x]) finalStr

parsePoint :: String -> [Int] -> String -> [Int]
parsePoint [] intTab _ = intTab
parsePoint ('(':xs) intTab intInP = parsePoint xs intTab intInP
parsePoint (')':_) intTab intInP = intTab ++ [read intInP :: Int]
parsePoint (',':xs) intTab intInP
  | intInP /= [] = parsePoint xs (intTab ++ [read intInP :: Int]) []
  | otherwise = []
parsePoint (x:xs) intTab intInP
  | not (isDigit x) = []
  | otherwise = parsePoint xs intTab (intInP ++ [x])

parseRGB :: [String] -> [RGB] -> String -> [RGB]
parseRGB [] rgbTab _ = rgbTab
parseRGB ((' ':xs):y) rgbTab stringInP =
  parseRGB y
  (RGB (parsePoint stringInP [] []) (parsePoint xs [] []) : rgbTab) []
parseRGB ((x:xs):y) rgbTab stringInP =
  parseRGB (xs:y) rgbTab (stringInP ++ [x])
parseRGB _ _ _ = []

isBadColor :: [Int] -> Bool
isBadColor [] = False
isBadColor (x:xs) | x < 0 || x > 255 = True
  | otherwise = isBadColor xs

checkErrorRGB :: [RGB] -> IO ()
checkErrorRGB [] = return ()
checkErrorRGB ((RGB point rgb):y)
  | length point /= 2 ||
  length rgb /= 3 || isBadColor rgb = exitWith (ExitFailure 84)
  | otherwise = checkErrorRGB y

pixelToRGB :: RGB -> (Int, Int, Int)
pixelToRGB (RGB _ (x:y:z:_)) = (x,y,z)
pixelToRGB _ = (0, 0, 0)

arrayPixelToRGB :: [RGB] -> [(Int, Int, Int)]
arrayPixelToRGB = map pixelToRGB

listToSet :: [(Int, Int, Int)] -> [(Int, Int, Int)]
listToSet rgb = let set = fromList rgb
  in toList set

parseContentFile :: String -> Int -> Float -> IO ()
parseContentFile content colors convergence =
  let rgbTb = parseRGB (parseLine content [] []) [] []
      pixel = arrayPixelToRGB rgbTb
      pixels = listToSet pixel
  in checkIsEmpty rgbTb >>
  checkErrorRGB rgbTb >>
  imgCompressor rgbTb [] colors convergence pixels