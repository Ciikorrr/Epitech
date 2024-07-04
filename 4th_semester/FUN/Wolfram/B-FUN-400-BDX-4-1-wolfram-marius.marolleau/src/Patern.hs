{-
-- EPITECH PROJECT, 2024
-- B-FUN-400-BDX-4-1-wolfram-marius.marolleau
-- File description:
-- Patern
-}
module Patern where

checkPatern30 :: (Int, Int, Int) -> Int
checkPatern30 (1,1,1) = 0
checkPatern30 (1,1,0) = 0
checkPatern30 (1,0,1) = 0
checkPatern30 (0,1,1) = 1
checkPatern30 (1,0,0) = 1
checkPatern30 (0,1,0) = 1
checkPatern30 (0,0,1) = 1
checkPatern30 (0,0,0) = 0

checkPatern90 :: (Int, Int, Int) -> Int
checkPatern90 (1,1,1) = 0
checkPatern90 (1,1,0) = 1
checkPatern90 (1,0,1) = 0
checkPatern90 (0,1,1) = 1
checkPatern90 (1,0,0) = 1
checkPatern90 (0,1,0) = 0
checkPatern90 (0,0,1) = 1
checkPatern90 (0,0,0) = 0

checkPatern110 :: (Int, Int, Int) -> Int
checkPatern110 (1,1,1) = 0
checkPatern110 (1,1,0) = 1
checkPatern110 (1,0,1) = 1
checkPatern110 (0,1,1) = 1
checkPatern110 (1,0,0) = 0
checkPatern110 (0,1,0) = 1
checkPatern110 (0,0,1) = 1
checkPatern110 (0,0,0) = 0