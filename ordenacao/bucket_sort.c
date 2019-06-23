#include "sort_test_defs.h"
#include "int_vector.h"

#define NUMBER_OF_BUCKETS 20

struct bucket
{
	int ubound;
	struct int_vector* vector;
};

struct bucket buckets[NUMBER_OF_BUCKETS];

void populate_buckets()
{
	int i,j;

	// Prepara os buckets
	for (i = 0; i < NUMBER_OF_BUCKETS; ++i) {
		buckets[i].vector = create_int_vector(array_size);

		buckets[i].ubound = (int)(((float)ARRAY_UPPER_BOUND / NUMBER_OF_BUCKETS) * (i+1));
	}

	// Localiza o bucket adequado para cada valor
	for (i = 0; i < array_size; ++i) {
		for (j = 0; j < NUMBER_OF_BUCKETS; ++j) {
			if (array[i] < buckets[j].ubound) {
				add_to_vector(buckets[j].vector, array[i]);
				break;
			}
		}
	}
}

void selection_sort(int* arr, int sz)
{
	int i,j,min_index,tmp;

	for (i = 0; i < sz; ++i) {

		min_index = i;
		for (j = i+1; j < sz; ++j) {
			if (arr[min_index] > arr[j]) {
				min_index = j;
			}
		}

		tmp = arr[i];
		arr[i] = arr[min_index];
		arr[min_index] = tmp;
	}
}

void sort_buckets()
{
	int bucket_index;

	for (bucket_index = 0; bucket_index < NUMBER_OF_BUCKETS; ++bucket_index) {
		selection_sort(buckets[bucket_index].vector->values,
					buckets[bucket_index].vector->size);
	}
}


int main()
{
	int i,j;
	int global_index;

	print_array();

	populate_buckets();
	
	printf("Buckets: \n");
	for (i = 0; i < NUMBER_OF_BUCKETS; ++i) {
		print_vector(buckets[i].vector);
	}

	sort_buckets();

	printf("Sorted Buckets: \n");
	for (i = 0; i < NUMBER_OF_BUCKETS; ++i) {
		print_vector(buckets[i].vector);
	}

	global_index = -1;

	for (i = 0; i < NUMBER_OF_BUCKETS; ++i) {
		for (j = 0; j < buckets[i].vector->size; ++j) {
			array[++global_index] = buckets[i].vector->values[j];
		}

		destroy_vector(buckets[i].vector);
	}

	print_array();
	return 0;
}
