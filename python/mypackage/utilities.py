
def sumlists(lst1, lst2):
	"""
Soma um a um os elementos de duas listas, retornando uma terceira
lista com as somas
"""
	result = []
	for a,b in zip(lst1, lst2):
		result.append(a+b)
	
	return result


	
