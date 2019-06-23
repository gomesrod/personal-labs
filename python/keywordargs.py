def myfun(arg1, arg2, arg3 = "default3"):
	print(arg1)
	print(arg2)
	print(arg3)
	print("-" * 20)

myfun(1, 2)
myfun(1000, 2000, 3000)
myfun(arg1 = "a", arg2 = "b")
myfun(arg2 = "A", arg1 = "B")
myfun(arg3 = "Z", arg2 = "Y", arg1 = "X")

