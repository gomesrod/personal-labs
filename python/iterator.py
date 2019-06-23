class WordList:

	class Iterator:
		def __init__(self, lst):
			self._lst = lst
			self._curIndex = 0
		def __next__(self):
			if self._curIndex < len(self._lst):
				ret = self._lst[self._curIndex]
				self._curIndex = self._curIndex + 1
				return ret
			else:
				raise StopIteration

	def __iter__(self):
		words = ("Python", "Java", "C++", "C#", "Visual Basic")
		return self.Iterator(words)

############################
wl = WordList()

print("-----------------\nIteracao manual:")
it = iter(wl)
print(next(it))
print(next(it))
print(next(it))
print(next(it))
print(next(it))
try:
	print(next(it))
except Exception as e:
	print("xxx",repr(e))

print("-----------------\nIteracao FOR:")
for w in wl:
	print(w)

