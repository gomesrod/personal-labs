#include <stdlib.h>

struct int_vector
{
	int* values;
	int capacity;
	int size;
};

struct int_vector *create_int_vector(int capacity)
{
	struct int_vector* vector = malloc(sizeof(struct int_vector));
	vector->values = malloc(capacity * sizeof(int));
	vector->capacity = capacity;
	vector->size = 0;
	return vector;
}

void add_to_vector(struct int_vector *vector, int value)
{
	if (vector->size >= vector->capacity) {
		perror("int_vector capacity exceeded");
		exit(1);
	}

	vector->values[vector->size++] = value;
}

void destroy_vector(struct int_vector *vector)
{
	free(vector->values);
	free(vector);
}

void print_vector(struct int_vector *vector)
{
	int i;
	
	printf("[ ");
	for (i = 0; i < vector->size; ++i) {
		if (i < (vector->size - 1)) {
			printf("%d , ", vector->values[i]);
		} else {
			printf("%d ]\n", vector->values[i]);
		}
	}
}

