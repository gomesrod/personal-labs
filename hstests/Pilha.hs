--TAD Pilha Exportacao Explicita,as operações listadas estaram visiveis  
module Pilha(Pilha,vazia,pop,top,push,ehvazia)where  
--data Pilha a = Pvazia|P1 (a,Pilha,a)  
data Pilha a = Pvazia | P1 a (Pilha a)
   deriving(Show)  
  
top :: Pilha a -> a  
top Pvazia = error "pilha vazia"  
top (P1 a p) = a  
  
pop :: Pilha a -> Pilha a  
pop Pvazia = error "pilha vazia"  
pop (P1 a p) = p  
  
push :: a -> Pilha a -> Pilha a  
push a p = P1 a p
  
ehvazia :: Pilha a -> Bool  
ehvazia Pvazia = True  
ehvazia _ = False  
  
vazia :: Pilha a  
vazia = Pvazia  
