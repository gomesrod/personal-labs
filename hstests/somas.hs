import Data.Char
import Control.Monad

split :: String -> [String]
split s = words s 

to_numbers :: [String] -> [Int]
to_numbers list = map read list

somar :: [Int] -> Int
somar [x]   = x
somar [x,y] = x + y
somar (x:ys) = x + (somar ys)


main = forever $ do
	l <- getLine
	let result = somar(to_numbers(split(l)))
	putStr $ l ++ "  = " ++ show result
	putStr "\n"
	
