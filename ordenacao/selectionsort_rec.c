
#include "sort_test_defs.h"

// SelectionSort - implementacao recursiva
void selSort(int* arr, int size, int i, int j, int min_index)
{
	int tmp;

	if (j == size) {
		return;
	}

	if (arr[min_index] > arr[j]) {
		min_index = j;
	}

	if (j == size - 1) {
		tmp = arr[i];
		arr[i] = arr[min_index];
		arr[min_index] = tmp;

		i++;
		j = i;
		min_index = i;
	}

	selSort(arr, size, i, j+1, min_index);
}

int main()
{
	print_array();
	selSort(array, array_size, 0, 1, 0);
	print_array();
}

