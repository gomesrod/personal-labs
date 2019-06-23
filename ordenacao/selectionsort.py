def selectionsort(arr):
	for i in range(0, len(arr)):
		min_index = i
		for j in range(i+1, len(arr)):
			if arr[j] < arr[min_index]:
				min_index = j
		if min_index > i:
			temp = arr[i]
			arr[i] = arr[min_index]
			arr[min_index] = temp


a = [23, 1, 56, 98, 7, 3, 13, 22, 80, 29, 90, 4]
print(a)
selectionsort(a)
print(a)
