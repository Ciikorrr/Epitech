{-
-- EPITECH PROJECT, 2024
-- B-PDG-300-BDX-3-1-PDGD03-marius.marolleau
-- File description:
-- Game
-}

data Item = Sword | Bow | MagicWand deriving Eq

instance Show Item where
    show Sword = "sword"
    show Bow = "bow"
    show MagicWand = "magic wand"

data Mob = Mummy | Skeleton Item | Witch (Maybe Item) deriving Eq

instance Show Mob where
    show Mummy = "mummy"
    show (Skeleton Bow) = "doomed archer"
    show (Skeleton Sword) = "dead knight"
    show (Skeleton item) = "skeleton holding a " ++ show item
    show (Witch Nothing)= "witch"
    show (Witch (Just MagicWand)) = "sorceress"
    show (Witch (Just item)) = "witch holding a " ++ show item

class HasItem a where
    getItem :: a -> Maybe Item
    hasItem :: a -> Bool
    hasItem mob = case getItem mob of
            Nothing -> False
            _ -> True

instance HasItem Mob where
    getItem Mummy = Nothing
    getItem (Skeleton item) = Just item
    getItem (Witch (Just item)) = Just item
    getItem (Witch Nothing) = Nothing
   

createMummy :: Mob
createMummy = Mummy

createArcher  :: Mob
createArcher = Skeleton Bow

createKnight :: Mob
createKnight = Skeleton Sword

createWitch :: Mob
createWitch = Witch Nothing

createSorceress :: Mob
createSorceress = Witch (Just MagicWand)

create :: String -> Maybe Mob
create mob = case mob of
    "mummy" -> Just createMummy
    "doomed archer" -> Just createArcher
    "dead knight" -> Just createKnight
    "witch" -> Just createWitch
    "sorceress" -> Just createSorceress
    _ -> Nothing

equip :: Item -> Mob -> Maybe Mob
equip item mob = case mob of
    Skeleton _ -> Just (Skeleton item)
    Witch _ -> Just (Witch (Just item))
    _ -> Nothing

