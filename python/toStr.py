
class A:
	def __init__(self, name, description):
		self.name = name
		self.description = description
	def __str__(self):
		return self.name + " _ " + self.description


a = A("titulllu", "detallli")
print(a.name)
print(a.description)
print(a)

