{-
-- EPITECH PROJECT, 2024
-- B-PDG-300-BDX-3-1-PDGD03-marius.marolleau
-- File description:
-- Tree
-}

data Tree a = Empty | Node (Tree a) a (Tree a) deriving (Show, Foldable)

instance Functor Tree where
    fmap func Empty = Empty
    fmap func (Node left val right) =
        Node (fmap func left) (func val) (fmap func right)

addInTree :: Ord a => a -> Tree a -> Tree a
addInTree a Empty = Node Empty a Empty
addInTree a (Node left val right) | a >= val =
    Node left val (addInTree a right)
    | otherwise = Node (addInTree a left) val right

listToTree :: Ord a => [a] -> Tree a
listToTree [] = Empty
listToTree (a:as) = addInTree a (listToTree as)

treeToList :: Tree a -> [a]
treeToList Empty = []
treeToList (Node left val right) =
    treeToList left ++ [val] ++ treeToList right

treeToListBis :: Tree a -> [a]
treeToListBis Empty = []
treeToListBis (Node left val right) =
    treeToListBis left ++ [val] ++ treeToListBis right

treeSort :: Ord a => [a] -> [a]
treeSort [] = []
treeSort (a:as) = treeToListBis (listToTree (a:as))
