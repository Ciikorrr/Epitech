{-
-- EPITECH PROJECT, 2024
-- B-FUN-400-BDX-4-1-compressor-adam.de-lacheisserie-levy
-- File description:
-- ImgCompressor
-}

module ImgCompressor (
  imgCompressor
) where

import ClusterUtils (assignToCluster)
import UpdateCentroid (getTab, updateCentroid)
import CheckConvergence (hasConverged)
import CompressorData (RGB(..), Cluster(..))
import System.Random

printRGB :: [RGB] -> IO ()
printRGB [] = return ()
printRGB ((RGB (a:b:_) (x:y:z:_)):xs) =
  putStrLn ("(" <> show a <> "," <> show b <> ") " <>
  "(" <> show x <> "," <> show y <> "," <> show z <> ")") >>
  printRGB xs
printRGB _ = return ()

printClust :: [Cluster] -> IO ()
printClust [] = return ()
printClust ((Cluster _ _ []):xs) = printClust xs
printClust ((Cluster (r,g,b) _ rgbT):xs) =
  putStrLn "--" >>
  print (r,g,b) >>
  putStrLn "-" >>
  printRGB rgbT >>
  printClust xs

isCentroid :: [Cluster] -> RGB -> Bool
isCentroid [] _ = False
isCentroid ((Cluster (x,y,z) _ _):xs) (RGB point (r:g:b:bs))
  | x == r && y == g && z == b = True
  | otherwise = isCentroid xs (RGB point (r:g:b:bs))
isCentroid _ _ = True

addCentroid :: [RGB] -> [Cluster] -> Int -> Bool -> [(Int, Int, Int)] -> IO Int
addCentroid rgb [] _ _ _ = randomRIO (0, length rgb - 1)
addCentroid _ _ index False _ = return index
addCentroid rgb clust _ True pixels
  | length clust >= length pixels = randomRIO (0, length rgb - 1)
  | otherwise = do
    index <- randomRIO (0, length rgb - 1)
    addCentroid rgb clust index (isCentroid clust (rgb !! index)) pixels

imgCompressor :: [RGB] -> [Cluster] -> Int -> Float -> [(Int, Int, Int)]
  -> IO ()
imgCompressor rgb cluster 0 convergence _ =
  let clustTab = assignToCluster cluster rgb
  in kMeans clustTab convergence
imgCompressor rgb cluster colors convergence pixels = do
  index <- addCentroid rgb cluster 0 True pixels
  let RGB _ (r:g:b:_) = rgb !! index
  imgCompressor rgb (Cluster (r,g,b)
    (-1,-1,-1) [] : cluster) (colors - 1) convergence pixels

updCluster :: [Cluster] -> [Cluster] -> [Cluster]
updCluster [] tmp = tmp
updCluster ((Cluster (r,g,b) prev []):xs) tmp =
  updCluster xs (Cluster (r,g,b) prev [] : tmp)
updCluster (x:xs) tmp = updCluster xs
  (updateCentroid x (getTab x [] [] []) : tmp)

kMeans :: [Cluster] -> Float -> IO ()
kMeans [] _ = return ()
kMeans clustTb convergence
  | hasConverged clustTb convergence False = printClust clustTb
  | otherwise = kMeans (updCluster clustTb []) convergence
