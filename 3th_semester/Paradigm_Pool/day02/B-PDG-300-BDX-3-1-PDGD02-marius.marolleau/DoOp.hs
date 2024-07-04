{-
-- EPITECH PROJECT, 2024
-- B-PDG-300-BDX-3-1-PDGD02-marius.marolleau
-- File description:
-- DoOp
-}

import Data.Char
import Control.Monad

myElem :: Eq a => a -> [a] -> Bool
myElem x [] = False
myElem x (a:as) | x == a = True
    | otherwise = myElem x as

safeDiv :: Int -> Int -> Maybe Int
safeDiv n1 0 = Nothing
safeDiv n1 n2 = Just(div n1 n2)

myLength :: [a] -> Int
myLength [] = 0
myLength (x:xs) = 1 + myLength xs

safeNth :: [a] -> Int -> Maybe a
safeNth [a] idx | idx < 0 = Nothing
    | myLength [a] <= idx = Nothing
safeNth (x:xs) idx | idx == 0 = Just x
    | otherwise = safeNth xs (idx - 1)

safeSucc :: Maybe Int -> Maybe Int
safeSucc Nothing = Nothing
safeSucc nb = fmap succ nb

myFst :: (x, y) -> x
myFst (x, y) =
    x

mySnd :: (x, y) -> y
mySnd (x, y) =
    y

myLookup :: Eq a => a -> [(a,b)] -> Maybe b
myLookup a [] = Nothing
myLookup a (x:xs) | a == myFst(x) = Just (mySnd(x))
    | otherwise = myLookup a xs

maybeDo :: (a -> b -> c) -> Maybe a -> Maybe b -> Maybe c
maybeDo func Nothing b = Nothing
maybeDo func a Nothing = Nothing
maybeDo func (Just a) (Just b) = Just (func a b)

readInt :: [Char] -> Maybe Int
readInt [] = Just 0
readInt (x:xs) = case (x == '-') of
    True -> case (all isDigit xs) of
        True -> Just (read (x:xs) :: Int)
        False -> Nothing
    False -> case (all isDigit (x:xs)) of
        True -> Just (read (x:xs) :: Int)
        False -> Nothing

getLineLength :: IO Int
getLineLength = getLine >>= return . length


printAndGetLength :: String -> IO Int
printAndGetLength line = 
    putStrLn line >>
    return (length line)

createTopBottom :: Int -> IO ()
createTopBottom nb = putStrLn ("+" ++ replicate(nb * 2 - 2) '-' ++ "+")

createLine :: Int -> IO ()
createLine nb = putStrLn ("|" ++ replicate(nb * 2 - 2) ' ' ++ "|")


printBox :: Int -> IO ()
printBox nb | nb <= 0 = return ()
printBox 1 = putStrLn "++"
printBox nb = createTopBottom nb >> replicateM_(nb - 2) (createLine nb) >>
    createTopBottom nb

concatLines :: Int -> IO String
concatLines nb | nb <= 0 = return ""
    | otherwise = do
        line <- getLine
        concatLines (nb - 1) >>= \line2 ->
            return (line ++ line2)

getInt :: IO (Maybe Int)
getInt = getLine >>= return . readInt