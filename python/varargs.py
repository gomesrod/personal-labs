def listStuff(message, *values):
	print(message, end=": ")
	for val in values:
		print(val, end=" / ")

def listDictionaryOfStuff(message, **items):
	print(message, end=": ")
	for key in items.keys():
		print(key,"=",items[key], end=" / ")


listStuff("Lista de compras", "Arroz", "Feijao", "Leite", "Ovos")
print()
listDictionaryOfStuff("Marcas preferidas", Arroz="Camil", \
		Feijao="Namorado", Leite="Parmalat", Ovos="De Galinha")

print()
print("\nDesempacotando lista e dicionario")

teams = ["Brasil", "Argentina", "Peru", "Uruguai"]
#Desempacota teams em lista de varargs
listStuff("Times participantes", *teams)

print()

situacao = {'Peru' : 1, 'Uruguai' : 2, 'Argentina' : 3, 'Brasil' : 4}
listDictionaryOfStuff("Posicao no campeonato", **situacao)
