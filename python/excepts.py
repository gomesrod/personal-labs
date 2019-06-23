def doSomethingWrong():
	raise Exception("Excepdata1", 2)


lst = ['A', 'B', 'C']

while True:
	try:
		print(lst.pop())
	except IndexError as err:
		print("Fim da Lista!")
		print(err)
		break

print()
print()

try:
	num = int(input("Digite um numero: "))
except ValueError:
	print("Numero invalido!")
except KeyboardInterrupt:
	print("Cancelou!")
else:
	# Executa quando nao cai em except
	print("O numero {0:d} eh Valido!".format(num))
finally:
	print("__FINALLY__")

print()
print()

print("Chamando funcao com excecao personalizada")
try:
	doSomethingWrong()
except Exception as e:
	print(e)
	print(e.args)
	print(e.args[0])
	print(e.args[1])


print()
print()

print("Dividindo por zero...")
try:
	i = num/0
except KeyboardInterrupt:
	print("Numca vai cair aqui")
except:
	print("Except geral. Relancando...")
	raise

