{-
-- EPITECH PROJECT, 2024
-- B-PDG-300-BDX-3-1-PDGRUSH1-marius.marolleau
-- File description:
-- ope
-}

module Ope (
    mySa,
    mySb,
    mySc,
    myPa,
    myPb,
    myRa,
    myRb,
    myRr,
    myRra,
    myRrb,
    myRrr,
    ) where

mySa :: ([a], [a]) -> ([a], [a])
mySa ([], []) = ([], [])
mySa ([], x : xs) = ([], x : xs)
mySa (x : xs, []) | length (x : xs) < 2 = (x :xs, [])
mySa (x : xs, y : ys) | length (x :xs) < 2 = (x :xs, y : ys)
mySa (x : y : xs, []) = (y : x : xs, [])
mySa (x : y : xs, z:zs) = (y : x : xs, z:zs)

mySb :: ([a], [a]) -> ([a], [a])
mySb ([], []) = ([], [])
mySb (x : xs, []) = (x : xs, [])
mySb ([], x : xs) | length (x : xs) < 2 = ([], x : xs)
mySb (x : xs, y : ys) | length (y : ys) < 2 = (x : xs, y : ys)
mySb ([], x : y : xs) = ([], y : x : xs)
mySb (x : xs, y : z : ys) = (x : xs, z : y : ys)

mySc :: ([a], [a]) -> ([a], [a])
mySc ([], []) = ([], [])
mySc ([], x : y : xs) = ([], y : x : xs)
mySc (x : y : xs, []) = (y : x : xs, [])
mySc ([], x : xs) | length (x : xs) < 2 = ([], x : xs)
mySc (x : xs, []) | length (x : xs) < 2 = (x :xs, [])
mySc (x :xs, y : z : ys) | length (x :xs) < 2 = (x : xs, z : y : ys)
mySc (x : a : xs, y : ys) | length (y : ys) < 2 = (a: x : xs, y : ys)
mySc (a : c : as, b : d : bs) = (c : a : as, d : b : bs)

myPa :: ([a], [a]) -> ([a], [a])
myPa ([], []) = ([], [])
myPa ([], b : bs) = ([b], bs)
myPa (a : as, []) = (a : as, [])
myPa (a : as, b : bs) = (b : a : as, bs)

myPb :: ([a], [a]) -> ([a], [a])
myPb ([], []) = ([], [])
myPb (x : xs, []) = (xs, [x])
myPb ([], b : bs) = ([], b :bs)
myPb (a :as, b : bs) = (as, a : b : bs)

myRa :: ([a], [a]) -> ([a], [a])
myRa ([], []) = ([], [])
myRa ([], b : bs) = ([], b : bs)
myRa (a : as, []) = (as ++ take 1 [a], [])
myRa (a :as , b : bs) = (as ++ take 1 [a], b : bs)

myRb :: ([a], [a]) -> ([a], [a])
myRb ([], []) = ([], [])
myRb (a : as, []) = (a : as, [])
myRb ([], a : as) = ([], as ++ take 1 [a])
myRb (a : as , b : bs) = (a : as, bs ++ take 1 [b])

myRr :: ([a], [a]) -> ([a], [a])
myRr ([], []) = ([], [])
myRr ([], b : bs) = ([], bs ++ take 1 [b])
myRr (a : as , []) = (as ++ take 1 [a], [])
myRr (a :as, b : bs) = (as ++ take 1 [a], bs ++ take 1 [b])

myRra :: ([a], [a]) -> ([a], [a])
myRra ([], []) = ([], [])
myRra (a : as, []) |  length (a : as) < 2 = (a : as, [])
myRra (a : as, []) = (moveLast (a :as), [])
myRra ([], b : bs) = ([], b : bs)
myRra (a : as, b : bs) | length (a : as) < 2 = (a : as, b : bs)
myRra (a : as , b : bs) = (moveLast (a :as), b : bs)

myRrb :: ([a], [a]) -> ([a], [a])
myRrb ([], []) = ([], [])
myRrb ([], b : bs) | length (b : bs) < 2 = ([], b : bs)
myRrb ([], b : bs) = ([], moveLast (b :bs))
myRrb (a : as, []) = (a : as, [])
myRrb (a : as, b : bs) | length (b : bs) < 2 = (a : as, b : bs)
myRrb (a : as , b : bs) = (a : as, moveLast (b : bs))

myRrr :: ([a], [a]) -> ([a], [a])
myRrr ([], []) = ([], [])
myRrr (a : as, []) = (moveLast (a :as), [])
myRrr ([], b : bs) = ([], moveLast (b : bs))
myRrr (a : as, b : bs) | length (a : as) < 2 = (a : as, b : bs)
myRrr (a : as, b : bs) | length (b : bs) < 2 = (a : as, b : bs)
myRrr (a :as , b : bs) = (moveLast (a :as), moveLast (b : bs))

takeLast :: [a] -> [a]
takeLast (a :as) = drop (length (a :as ) - 1) (a :as)

removeLast :: [a] -> [a]
removeLast (a :as) = take (length (a : as) - 1) (a :as)

moveLast :: [a] -> [a]
moveLast(a : as) = takeLast (a : as) ++ removeLast (a : as)