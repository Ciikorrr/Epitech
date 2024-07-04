{-
-- EPITECH PROJECT, 2024
-- B-FUN-400-BDX-4-1-mypandoc-tristan.le-du
-- File description:
-- Display
-}

module Display (displayDocument) where
import Data.Maybe
import DataPandoc (TTypes(..), Segment(..))
import Control.Monad

displayText :: String -> String -> IO ()
displayText = displayFileOrNot

displayBold :: String -> String -> IO ()
displayBold str f = displayFileOrNot "**" f >> displayFileOrNot str f >>
  displayFileOrNot "**" f

displayItalic :: String -> String -> IO ()
displayItalic str f = displayFileOrNot "*" f >> displayFileOrNot str f >>
  displayFileOrNot "*" f

displayCode :: String -> String -> IO ()
displayCode str f = displayFileOrNot "`" f >> displayFileOrNot str f >>
  displayFileOrNot "`" f

displayFileOrNot :: String -> String -> IO ()
displayFileOrNot str [] = putStr str
displayFileOrNot str file = appendFile file str

displayFileOrNotLn :: String -> String -> IO ()
displayFileOrNotLn str [] = putStrLn str
displayFileOrNotLn str file = appendFile file str >> appendFile file "\n"

displayCdBlc :: [Segment] -> String -> Int -> IO ()
displayCdBlc [] _ _ = return ()
displayCdBlc ((Paragraph cnt):xs) f dpt = displayParagraph cnt f >>
  displayFileOrNotLn "" f >> displayCdBlc xs f dpt
displayCdBlc ((CodeBlock cnt):xs) f dpt = displayFileOrNot "```" f >>
  displayCdBlc cnt f dpt >> displayFileOrNot "```" f >> displayCdBlc xs f dpt
displayCdBlc ((Section (Just "") cnt):xs) f dpt = displaySct cnt f (dpt + 1) >> 
  replicateM_ 2 (displayFileOrNotLn "" f)
displayCdBlc ((Section title cnt):xs) f dpt = 
  replicateM_ dpt (displayFileOrNot "#" f)
  >> displayFileOrNot (fromJust title) f >> displayFileOrNotLn "" f
  >> displaySct cnt f (dpt + 1) >> replicateM_ 2 (displayFileOrNotLn "" f) >>
  displayCdBlc xs f dpt
displayCdBlc ((List cnt):xs) f dpt = displayList cnt f dpt
  >> displayCdBlc xs f dpt

displayList :: [Segment] -> String -> Int -> IO ()
displayList [] _ _ = return ()
displayList ((Paragraph cnt):xs) f dpt = displayFileOrNot "- " f >>
  displayParagraph cnt f >> displayFileOrNotLn "" f >> displayList xs f dpt
displayList ((CodeBlock cnt):xs) f dpt = displayFileOrNotLn "```" f >>
  displayCdBlc cnt f dpt >> displayFileOrNotLn "```" f >> displayList xs f dpt
displayList ((List cnt):xs) f dpt = displayList cnt f dpt >>
  replicateM_ 1 (displayFileOrNotLn "" f) >> displayList xs f dpt
displayList ((Section title cnt):xs) f dpt =
  replicateM_ dpt (displayFileOrNot "#" f)
  >> displayFileOrNot " " f >> displayFileOrNotLn (fromJust title) f >>
  displaySct cnt f (dpt + 1)
  >> replicateM_ 2 (displayFileOrNotLn "" f) >> displayList xs f dpt

displaySct :: [Segment] -> String -> Int -> IO ()
displaySct [] _ _ = return ()
displaySct ((Paragraph cnt):xs) f dpt = displayParagraph cnt f >>
  replicateM_ 2 (displayFileOrNotLn "" f) >> displaySct xs f dpt
displaySct ((CodeBlock cnt):xs) f dpt = displayFileOrNotLn "```" f
  >> displayCdBlc cnt f dpt >> displayFileOrNotLn "```" f >>
  displaySct xs f dpt
displaySct ((List cnt):xs) f dpt = displayList cnt f dpt >>
  replicateM_ 1 (displayFileOrNotLn "" f) >> displaySct xs f dpt
displaySct ((Section (Just"") cnt):xs) f dpt =
  displaySct cnt f (dpt + 1) >> displaySct xs f dpt
displaySct ((Section title cnt):xs) f dpt =
  replicateM_ dpt (displayFileOrNot "#" f) >> displayFileOrNot " " f >>
  displayFileOrNotLn (fromJust title) f >>
  displayFileOrNotLn "" f >> displaySct cnt f (dpt + 1) >> displaySct xs f dpt

displayParagraph :: [TTypes] -> String -> IO ()
displayParagraph [] _ = return ()
displayParagraph ((Italic (Text str)):xs) f = displayItalic str f >>
  displayParagraph xs f
displayParagraph ((Bold (Text str)):xs) f = displayBold str f >>
  displayParagraph xs f
displayParagraph ((Code (Text str)):xs) f = displayCode str f >>
  displayParagraph xs f
displayParagraph ((Text str):xs) f = displayText str f >>
  displayParagraph xs f
displayParagraph ((Link url (Text str)):xs) f = displayText "[" f >> 
  displayText str f >> displayText "]" f >> displayText "(" f
  >> displayText url f >> displayText ")" f >> displayParagraph xs f
displayParagraph ((Image url (Text str)):xs) f = displayText " ![" f >> 
  displayText str f >> displayText "]" f >> displayText "(" f
  >> displayText url f >> displayText ")" f >> displayParagraph xs f
displayParagraph _ _ = return ()

displayDocument :: [Segment] -> String -> IO ()
displayDocument [] _ = return ()
displayDocument ((Paragraph cnt):xs) f = displayParagraph cnt f >>
  replicateM_ 2 (displayFileOrNotLn "" f) >> displayDocument xs f
displayDocument ((CodeBlock cnt):xs) f = displayFileOrNotLn "```" f
  >> displayCdBlc cnt f 1 >> displayFileOrNotLn "```" f >> displayDocument xs f
displayDocument ((List cnt):xs) f = displayList cnt f 1 >>
  replicateM_ 1 (displayFileOrNotLn "" f) >> displayDocument xs f
displayDocument ((Section (Just "") cnt):xs) f = 
  displayFileOrNotLn "" f >> displaySct cnt f 2 >> displayDocument xs f
displayDocument ((Section title cnt):xs) f = 
  replicateM_ 1 (displayFileOrNot "#" f) >> displayFileOrNot " " f >>
  displayFileOrNotLn (fromJust title) f >>
  displayFileOrNotLn "" f >> displaySct cnt f 2 >> displayDocument xs f