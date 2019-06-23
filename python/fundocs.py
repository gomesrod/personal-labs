def do_nothing(x : "Param annotation") -> "Return annotation":
	"""	This function does nothing.

	I'm serious, it does not do anything.

	Parameters:
	x - Just pass anything you want
	"""
	pass


print(do_nothing.__doc__)

print()
print()

print(do_nothing.__annotations__)
