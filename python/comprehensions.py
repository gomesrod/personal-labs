lst = [x**2 for x in range(11)]
print(lst)

#Equivalent to
square = lambda x: x**2
lst = list(map(square, range(11)))
print(lst)

####################

lst = [(x,y) for x in [1,2,3] for y in [3,1,4] if x != y]
print(lst)


## Flattening a list
vec = [["A","B","C"], ["d","e","f"], ["G","H","I"]]
lst = [letter for elem in vec for letter in elem]
print(lst)


# Nested comprehension
print()
print()

matrix = [
	[1, 2, 3, 4],
	[5, 6, 7, 8],
	[9, 10, 11, 12]
]

lst = [[row[i] for row in matrix] for i in range(4)]
print(lst)

# Equivalent to
lst = []
for i in range(4):
	lst.append([row[i] for row in matrix])

print(lst)

# which is in turn equivalent to...
lst = []
for i in range(4):
	transposed_row = []
	for row in matrix:
		transposed_row.append(row[i])
	lst.append(transposed_row)

print(lst)
