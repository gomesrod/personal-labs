import Data.Char
import Control.Monad

main = forever $ do
	putStr "Give me some input: "
	l <- getLine
	putStrLn $ map toUpper l

