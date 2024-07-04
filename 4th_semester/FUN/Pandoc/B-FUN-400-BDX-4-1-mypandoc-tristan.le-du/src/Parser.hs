{--
-- EPITECH PROJECT, 2024
-- BSPandoc
-- File description:
-- Parser
--}

module Parser (
    parseChar,
    parseSome,
    parseAnyChar,
    parseOr,
    parseAnd,
    parseAndWith,
    parseMany,
    parseUInt,
    parseInt,
    parseTuple,
) where

type Parser a = String -> Maybe (a, String)

parseChar :: Char -> Parser Char
parseChar c (x:xs) | c == x = Just (c, xs)
                   | otherwise = Nothing
parseChar _ _ = Nothing

parseAnyChar :: String -> Parser Char
parseAnyChar [] _ = Nothing
parseAnyChar (c:cs) input = case parseChar c input of
    Just result -> Just result
    Nothing -> parseAnyChar cs input

parseOr :: Parser a -> Parser a -> Parser a
parseOr p1 p2 input = case p1 input of
    Just result -> Just result
    Nothing -> p2 input

parseAnd :: Parser a -> Parser b -> Parser (a, b)
parseAnd p1 p2 input = case p1 input of
    Just (result1, rest) -> case p2 rest of
        Just (result2, newRest) -> Just ((result1, result2), newRest)
        Nothing -> Nothing
    Nothing -> Nothing

parseAndWith :: (a -> b -> c) -> Parser a -> Parser b -> Parser c
parseAndWith f p1 p2 input = case p1 input of
    Just (result1, rest) -> case p2 rest of
        Just (result2, newRest) -> Just (f result1 result2, newRest)
        Nothing -> Nothing
    Nothing -> Nothing

parseMany :: Parser a -> Parser [a]
parseMany p input = case p input of
    Just (result, rest) -> case parseMany p rest of
        Just (results, newRest) -> Just (result:results, newRest)
        Nothing -> Just ([result], rest)
    Nothing -> Just ([], input)

parseSome :: Parser a -> Parser [a]
parseSome p input = case parseAnd p (parseMany p) input of
    Just ((x, xs), rest) -> Just (x:xs, rest)
    Nothing -> Nothing

parseUInt :: Parser Int
parseUInt input = case parseSome (parseAnyChar "1234567890") input of
    Just (digits, rest) -> Just (read digits, rest)
    Nothing -> Nothing

parseInt :: Parser Int
parseInt input = case parseOr (parseChar '-') (parseAnyChar "1234567890") input of
    Just (sign, rest) -> case (if sign == '-'
        then parseUInt rest
        else parseUInt (sign:rest)) of
        Just (unsigned, rests) -> Just (if sign == '-'
            then (-unsigned)
            else unsigned, rests)
        Nothing -> Nothing
    Nothing -> Nothing

parseTuple :: Parser a -> Parser (a, a)
parseTuple p input = do
    (_, rest1) <- parseChar '(' input
    (first, rest2) <- p rest1
    (_, rest3) <- parseChar ',' rest2
    (second, rest4) <- p rest3
    (_, rest5) <- parseChar ')' rest4
    Just ((first, second), rest5)