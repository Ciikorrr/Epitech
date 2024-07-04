{-
-- EPITECH PROJECT, 2024
-- B-FUN-400-BDX-4-1-compressor-adam.de-lacheisserie-levy
-- File description:
-- CheckConvergence
-}

module CheckConvergence (
  hasConverged,
) where

import CompressorData (Cluster(..))

getDistance :: (Int, Int, Int) -> (Int, Int, Int) -> Float
getDistance (a,b,c) (x,y,z) =
  sqrt (fromIntegral((a - x)^(2::Int) + (b - y)^(2::Int) + (c - z)^(2::Int)))

hasConverged :: [Cluster] -> Float -> Bool -> Bool
hasConverged [] _ bool = bool
hasConverged ((Cluster _ (-1,_,_) _):xs) conv bool = hasConverged xs conv bool
hasConverged ((Cluster new prev _):xs) conv _ | conv > getDistance new prev =
  hasConverged xs conv True
  | otherwise = False