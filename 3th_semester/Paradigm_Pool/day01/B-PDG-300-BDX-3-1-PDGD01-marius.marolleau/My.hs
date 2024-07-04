{-
-- EPITECH PROJECT, 2024
-- B-PDG-300-BDX-3-1-PDGD01-marius.marolleau
-- File description:
-- My
-}

mySucc :: Int -> Int
mySucc x = x + 1

myIsNeg :: Int -> Bool
myIsNeg x = x < 0

myAbs :: Int -> Int
myAbs x | x < 0 = (-1) * x
        | otherwise  = x

myMin :: Int -> Int -> Int
myMin x y | x < y = x
        | otherwise = y

myMax :: Int -> Int -> Int
myMax x y | x > y = x
        | otherwise = y

myTuple :: a -> b -> (a, b)
myTuple a b = 
    (a, b)

myTruple :: a -> b -> c -> (a, b, c)
myTruple a b c = 
    (a, b, c)

myFst :: (x, y) -> x
myFst (x, y) =
    x

mySnd :: (x, y) -> y
mySnd (x, y) =
    y

mySwap :: (x, y) -> (y, x)
mySwap (x, y) =
    (y, x)

myHead :: [a] -> a
myHead [] = (error "List empty")
myHead (a:_) = a
 
myTail :: [a] -> [a]
myTail [] = (error "List empty")
myTail (_:a) = a

myLength :: [a] -> Int
myLength [] = 0
myLength (x:xs) = 1 + myLength xs

myNth :: [a] -> Int -> a
myNth [a] idx | idx < 0 = error "negative index" 
  | myLength [a] <= idx = error "invalid index"
myNth (x:xs) idx | idx == 0 = x
        | otherwise = myNth xs (idx - 1)

myTake :: Int -> [a] -> [a]
myTake nb [x] | nb > myLength [x] = [x]
    | nb < 0 = error "nb is negative"
myTake nb (x:xs) | nb == 1 = [x]
    | otherwise = x : myTake (nb - 1) xs

myDrop :: Int -> [a] -> [a]
myDrop nb [a] | nb > myLength [a] = [] | nb < 0 = error "Invalid N"
myDrop nb (x:xs) | nb == 1 = xs
    | otherwise = myDrop (nb - 1) xs

myAppend :: [a] -> [a] -> [a]
myAppend [] as = as
myAppend (x:xs) as = x : myAppend xs as

myReverse :: [a] -> [a]
myReverse [] = []
myReverse (x:xs) = myAppend (myReverse xs) [x]

myInit :: [a] -> [a]
myInit [] = error "Empty List"
myInit [a] = []
myInit (a:as) = a : myInit as

myLast :: [a] -> a
myLast (a:as) | (myLength as) == 0 = a
    | otherwise = myLast as

myZip :: [a] -> [b] -> [(a, b)]
myZip [a] [] = []
myZip (a:as) [] = []
myZip [] (b:bs) = []
myZip [] [b] = []
myZip [] [] = []
myZip (a:as) (b:bs) = myTuple a b : myZip (as) (bs)

myUnzip :: [(a, b)] -> ([a], [b])
myUnzip [] = ([], [])
myUnzip ((a, b):as) = myTuple(
    myAppend[a](myFst(
        myUnzip as)))(myAppend[b](mySnd(myUnzip as)))

myMap :: (a -> b) -> [a] -> [b]
myMap func [] = []
myMap func (a:as) = func a : myMap func as

myFilter :: (a -> Bool) -> [a] -> [a]
myFilter func [] = []
myFilter func (a:as) | func a == True = a : myFilter func as
    | otherwise = myFilter func as

myFilterFalse :: (a -> Bool) -> [a] -> [a]
myFilterFalse func [] = []
myFilterFalse func (a:as) | func a == False = a : myFilterFalse func as
    | otherwise = myFilterFalse func as

myFoldl :: (b -> a -> b) -> b -> [a] -> b
myFoldl func b [] = b
myFoldl func b (a:as) = myFoldl func (func b a) as

myFoldr :: (a -> b -> b) -> b -> [a] -> b
myFoldr func b [] = b
myFoldr func b (a:as) = func a (myFoldr func b as)

myPartition :: (a -> Bool) -> [a] -> ([a], [a]) 
myPartition func a = (myFilter func a, myFilterFalse func a)