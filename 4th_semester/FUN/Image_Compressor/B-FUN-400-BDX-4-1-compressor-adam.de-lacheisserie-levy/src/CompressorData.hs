{-
-- EPITECH PROJECT, 2024
-- B-FUN-400-BDX-4-1-compressor-adam.de-lacheisserie-levy
-- File description:
-- CompressorData
-}

module CompressorData (
    Compressor(..),
    RGB(..),
    Cluster(..)
) where

data Compressor =
    Compressor {
        colors::Int,
        convergence::Float,
        filePath::String
    } deriving (Show)

data RGB = RGB [Int] [Int] deriving (Show)

data Cluster = Cluster (Int, Int, Int) (Int, Int, Int) [RGB] deriving (Show)
