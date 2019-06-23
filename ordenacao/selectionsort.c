
#include "sort_test_defs.h"

int main()
{
	int i,j,min_index,tmp;

	print_array();

	for (i = 0; i < array_size; ++i) {
		min_index = i;

		for (j = i+1; j < array_size; ++j) {
			if (array[min_index] > array[j]) {
				min_index = j;
			}
		}

		if (min_index != i) {
			tmp = array[i];
			array[i] = array[min_index];
			array[min_index] = tmp;
		}
	}

	print_array();

}
