#include <stdio.h>

#include "sort_test_defs.h"

int main()
{
	int i,j,swap;

	print_array();

	BOOL sorted = FALSE;

	for (i = 2; i < array_size && !sorted ; ++i) {

		sorted = TRUE;

		for (j = 0; j < (array_size - i); ++j) {
			if(array[j] > array[j+1]) {

				sorted = FALSE;

				swap = array[j];
				array[j] = array[j+1];
				array[j+1] = swap;
			}
		}
	}

	print_array();
	
}
