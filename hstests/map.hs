dobraAll       :: [Integer] -> [Integer]
dobraAll lst   =  map ((*)2) lst

toString       :: [Integer] -> [String]
toString lst   =  map show lst

main = print $ (toString . dobraAll) [1,2,3,4,100]
