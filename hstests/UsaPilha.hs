module UsaPilhas where  
  
import Pilha
  
--lineariza pilha  
lineariza :: Pilha a -> [a]  
lineariza p  
   | ehvazia(p) = []  
   | otherwise = top(p):lineariza(pop(p))  


-- result = lineariza (pop . push 1 . push 5 . push 10 . push 15 . push 20 $ vazia)
result = lineariza (pop . push "CAI FORA" . push "PRIMEIRO" . push "SEGUNDO" . push "TERCEIRO" . push "QUARTO" $ vazia)

main = putStr $ show result
