{-
-- EPITECH PROJECT, 2024
-- B-FUN-400-BDX-4-1-compressor-adam.de-lacheisserie-levy
-- File description:
-- UpdateCentroid
-}

module UpdateCentroid (
    getTab,
    updateCentroid
) where

import CompressorData(RGB(..), Cluster(..))

updateCentroid :: Cluster -> (Int, Int, Int) -> Cluster
updateCentroid (Cluster (a,b,c) (_,_,_) rgb) (m0,m1,m2) =
  Cluster (m0,m1,m2) (a,b,c) rgb

calculateAverages :: [(Int, Int, Int)] -> (Int, Int, Int)
calculateAverages points =
  let (xSum, ySum, zSum) = foldl (\(x, y, z) (a, b, c) -> (x + a, y + b, z + c)) (0, 0, 0) points
      len = length points
  in (xSum `div` len, ySum `div` len, zSum `div` len)

getTab :: Cluster -> [Int] -> [Int] -> [Int] -> (Int, Int, Int)
getTab (Cluster _ _ []) list1 list2 list3 =
  calculateAverages $ zip3 list1 list2 list3
getTab (Cluster new prev (RGB _ (x:y:z:_):xs)) list1 list2 list3 =
  getTab (Cluster new prev xs) (x:list1) (y:list2) (z:list3)
getTab _ _ _ _ = (-1, -1, -1)
