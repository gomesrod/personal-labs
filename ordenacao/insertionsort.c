#include "sort_test_defs.h"

int main()
{
	int i, j, pivot;

	print_array();

	for (i = 0; i < array_size; ++i) {
		pivot = array[i];

		for (j = i-1; (j >= 0) && (pivot < array[j]); --j) {
			array[j+1] = array[j];
		}
		array[j+1] = pivot;
	}

	print_array();

}
