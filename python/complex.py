class Complex:
	def __init__(self, realpart, imagpart):
		self.real = realpart
		self.imag = imagpart

	def print(self):
		print("({0}, {1})".format(self.real, self.imag))
	
	def add(self, other):
		return Complex(self.real + other.real, self.imag + other.imag);
#########################################################

x = Complex(3.0, -4.5)
y = Complex(10.0, 1.25)
z = x.add(y);

x.print()
y.print()
z.print()
