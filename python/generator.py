def variations(word):
	""" Generates some variations for the given word """
	yield word

	l = list(word)
	l.reverse()
	yield "".join(l)

	l = list(word)
	l.sort();
	yield "".join(l)

	yield word.upper()


for p in variations("python"):
	print(p)

