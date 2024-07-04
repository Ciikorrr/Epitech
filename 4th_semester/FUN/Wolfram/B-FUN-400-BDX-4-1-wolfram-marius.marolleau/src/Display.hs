{-
-- EPITECH PROJECT, 2024
-- B-FUN-400-BDX-4-1-wolfram-marius.marolleau
-- File description:
-- Display
-}

module Display where
import Parser


moveDisplay :: Int -> IO ()
moveDisplay 0 = return ()
moveDisplay move = putStr " " >> moveDisplay (move - 1)

displayInt :: Int -> [Int] -> IO ()
displayInt window [] = return ()
displayInt 0 list = return ()
displayInt window (1:xs) = putStr "*" >> displayInt (window - 1) xs
displayInt window (0:xs) = putStr " " >> displayInt (window - 1) xs 

displayIndex :: Int -> Int -> Int -> [Int] -> IO()
displayIndex move window 0 list = 
  moveDisplay move >> displayInt window list >> putStrLn ""
displayIndex move window index (x:xs) = 
  displayIndex move window (index - 1) xs

display :: Int -> Int -> Int -> Int -> Zipper a -> IO ()
display move window zerodisplay 0 (Zipper ls x rs _ _) | zerodisplay >= 0 = 
  let newList = init (init rs) in
  moveDisplay move >> displayInt window (replicate (zerodisplay + 1) 0) >> 
  displayInt window newList >> 
  displayInt window (replicate (zerodisplay) 0) >> putStrLn "" 
  | otherwise = displayIndex move window (zerodisplay * (-1) - 1) rs
display _ _ _ start (Zipper ls x rs _ _) = return ()
