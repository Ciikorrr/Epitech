{-
-- EPITECH PROJECT, 2024
-- B-FUN-400-BDX-4-1-wolfram-marius.marolleau
-- File description:
-- Algo
-}
module Algo where

import Data.Monoid (Last(Last))
import Data.Maybe (fromJust)
import Parser
import Patern
import Display

createListFromZipper :: Int -> Zipper a -> [Int] -> [Int]
createListFromZipper rule (Zipper ll nb (r:rl) idx len) list | 
    idx == len = list
  | otherwise =
    createListFromZipper rule (Zipper (ll ++ [nb]) r rl (idx+1) len) 
    (getNewCell rule (Zipper ll nb (r:rl) idx len) list)
createListFromZipper _ _ list = list

createZipperFromList :: [Int] -> Int -> Zipper a
createZipperFromList (x:xs) window = 
  Zipper [0] 0 ((x:xs) ++ [0, 0]) 0 (length (x:xs) + 2)

getNewCell :: Int -> Zipper a -> [Int] -> [Int]
getNewCell 30 (Zipper ll nb (x:xs) _ _) list = 
  checkPatern30 (last ll, nb, x) : list
getNewCell 90 (Zipper ll nb (x:xs) _ _) list = 
  checkPatern90 (last ll, nb, x) : list
getNewCell 110 (Zipper ll nb (x:xs) _ _) list = 
  checkPatern110 (last ll, nb, x) : list

doAlgo :: Int -> Int -> Int -> Zipper a -> Int -> Int -> IO ()
doAlgo move rule 0 zip window 0 = return ()
doAlgo move rule 0 zip window lines = 
    let newList = reverse (createListFromZipper rule zip [])
        newZipper = createZipperFromList newList window
        zerodisplay = floor(fromIntegral(window - length newList) / 2)
    in display move window zerodisplay 0 newZipper >> 
    doAlgo move rule 0 newZipper window (lines - 1)
doAlgo move rule start zip window lines = 
  let newList = reverse (createListFromZipper rule zip [])
      newZipper = createZipperFromList newList window
  in doAlgo move rule (start - 1) newZipper window lines

checkStart :: Int -> Zipper a-> Maybe Conf -> IO()
checkStart zerodisplay newzipper arg | (start (fromJust arg)) == 0 =
  display (move (fromJust arg)) (window (fromJust arg)) 
  zerodisplay (start (fromJust arg)) newzipper
  >> doAlgo (move (fromJust arg)) (rule (fromJust arg)) 
  (start (fromJust arg)) newzipper (window (fromJust arg)) 
  (line (fromJust arg) - 1) | otherwise = display (move (fromJust arg)) 
  (window (fromJust arg)) zerodisplay (start (fromJust arg)) newzipper
  >> doAlgo (move (fromJust arg)) (rule (fromJust arg)) 
  (start (fromJust arg) - 1) newzipper (window (fromJust arg)) 
  (line (fromJust arg))