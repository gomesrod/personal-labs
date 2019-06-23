incrementor = lambda x: x + 1

def make_var_incrementor(delta):
	return lambda x: x + delta


print(incrementor(41))

incrementor2 = make_var_incrementor(10)

print(incrementor2(32))
