{-
-- EPITECH PROJECT, 2024
-- B-FUN-400-BDX-4-1-bswolfram-marius.marolleau
-- File description:
-- bootstrap
-}
module Parser where
import System.Exit
import Data.Char (isDigit)
import Data.Maybe (fromJust)

data Zipper a = Zipper [Int] Int [Int] Int Int deriving (Show)

data Conf = Conf
    { rule :: Int,
      start :: Int,
      line :: Int,
      window ::Int,
      move :: Int,
      err :: Bool
    } deriving (Show)

epiFail :: IO ()
epiFail = exitWith $ ExitFailure 84

epiWin :: IO()
epiWin = exitSuccess

checkArg :: [String] -> IO ()
checkArg [] = epiFail
checkArg _ = return ()

stringIsNum :: String -> Bool
stringIsNum ('-':xs) = stringIsNum xs
stringIsNum (x:xs) | isDigit(x) == False = False 
  | otherwise = stringIsNum xs
stringIsNum [] = True

argsIsNum :: [String] -> IO ()
argsIsNum [] = return ()
argsIsNum ("--rules":y:xs) | stringIsNum(y) == False = epiFail
  | otherwise = argsIsNum xs
argsIsNum ("--start":y:xs) | stringIsNum(y) == False = epiFail
  | otherwise = argsIsNum xs
argsIsNum ("--lines":y:xs) | stringIsNum(y) == False = epiFail
  | otherwise = argsIsNum xs
argsIsNum ("--window":y:xs) | stringIsNum(y) == False = epiFail
  | otherwise = argsIsNum xs
argsIsNum ("--move":y:xs) | stringIsNum(y) == False = epiFail
  | otherwise = argsIsNum xs
argsIsNum (_:xs) = argsIsNum xs

defaultConf :: Conf
defaultConf = Conf{rule = 0, start = 0, line = -1, 
window = 80, move = 0, err = False}

getOpts :: Conf -> [String] -> Maybe Conf
getOpts conf [] = Just conf
getOpts conf ("--rule":y:xs) = 
  getOpts (updateConf conf "rule" (read y :: Int)) xs
getOpts conf ("--start":y:xs) = 
  getOpts (updateConf conf "start" (read y :: Int)) xs
getOpts conf ("--lines":y:xs) = 
  getOpts (updateConf conf "line" (read y :: Int)) xs
getOpts conf ("--window":y:xs) = 
  getOpts (updateConf conf "window" (read y :: Int)) xs
getOpts conf ("--move":y:xs) = 
  getOpts (updateConf conf "move" (read y :: Int)) xs
getOpts _ _ = Nothing

updateConf :: Conf -> String -> Int -> Conf
updateConf conf "rule" val | val /= 30 && val /= 90 && val /= 110 = 
  conf {err = True} | otherwise = conf {rule = val}
updateConf conf "start" val | val < 0 = 
  conf {err = True} | otherwise = conf {start = val}
updateConf conf "line" val | val < 0 = 
  conf {err = True} | otherwise =  conf {line = val}
updateConf conf "window" val | val < 0 = 
  conf {err = True} | otherwise = conf {window = val}
updateConf conf "move" val | val < 0 = conf {move = 0} | otherwise =
  conf {move = val}
updateConf conf _ _ = conf {err = True}

checkError :: Maybe Conf -> IO ()
checkError Nothing = epiFail
checkError conf | err (fromJust conf) = 
  epiFail | otherwise = return ()
