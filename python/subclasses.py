class Base:
	def __init__(self):
		print("__init__Base")
		self.val = 'b'
	def fun1(self):
		print("in fun1...")
	def getVal(self):
		return self.val

class Derived(Base):
	def __init__(self):
		print("__init__Derived")
		self.val = 'd'
	def fun2(self):
		print("in fun2...")

b = Base()
d = Derived()

b.fun1()
print(b.getVal())
d.fun1()
d.fun2()
print(d.getVal())

print(isinstance(b, Derived))
print(isinstance(d, Derived))
print(issubclass(Base, Derived))
print(issubclass(Derived, Base))

