f = open("data.txt", "r")


print("Reading all:\n____________\n")
print(f.read())

f.seek(0)

print("Reading line by line:\n__________\n")

buf = "   "
while(buf != ""):
	buf = f.readline()
	if (buf != ""):
		print("LINE::::: {}".format(buf))


f.seek(0)

print("Iterating:\n__________\n")

for buf2 in f:
	print("ITER::::: {}".format(buf2))



