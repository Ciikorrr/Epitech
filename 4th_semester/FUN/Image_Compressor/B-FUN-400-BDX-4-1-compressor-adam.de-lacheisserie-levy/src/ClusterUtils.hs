{-
-- EPITECH PROJECT, 2024
-- B-FUN-400-BDX-4-1-compressor-adam.de-lacheisserie-levy
-- File description:
-- ClusterUtils
-}

module ClusterUtils (
  assignToCluster
) where

import Data.List(sortOn)
import CompressorData(Cluster(..), RGB(..))

distance :: RGB -> Cluster -> Double
distance (RGB _ (x:y:z:_)) (Cluster (r, g, b) _ _) =
    sqrt (fromIntegral (
      (r - x)^(2::Int) + (g - y)^(2::Int) + (b - z)^(2::Int)))
distance _ _ = 0

addInCluster :: [Cluster] -> RGB -> [Cluster]
addInCluster ((Cluster clust tmp rgbTab):xs) pixel =
  Cluster clust tmp (pixel : rgbTab):xs
addInCluster _ _ = []

checkAllCluster::[Cluster]-> RGB -> [Cluster]
checkAllCluster cluster pixel =
  addInCluster (sortOn (distance pixel) cluster) pixel

assignToCluster :: [Cluster] -> [RGB] -> [Cluster]
assignToCluster = foldl checkAllCluster