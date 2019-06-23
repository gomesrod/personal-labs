def bubblesort(arr):
	for i in range(len(arr)-2, 0, -1):
		for j in range(0, i):
			if arr[j+1] < arr[j]:
				temp = arr[j]
				arr[j] = arr[j+1]
				arr[j+1] = temp



a = [23, 1, 56, 98, 7, 3, 13, 22, 80, 29, 90, 4]

print(a)
bubblesort(a)
print(a)


