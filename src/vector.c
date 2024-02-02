#include <pinelibs/vector.h>
#include <stdlib.h>

struct Vector {int* array; int size; int capacity;};

Vector newVector(int capacity) {
	Vector v;
	v.array = (int*) malloc(sizeof(int) * capacity);
	if (v.array == NULL) {
		exit(EXIT_FAILURE);
	}
	v.size = 0;
	v.capacity = capacity;
	return v;
}

void vectorInsert(Vector* v, int value) {
	while (v->capacity <= v->size) {
		int* a = (int*) malloc(sizeof(int) * v->capacity * 2);
		if (a == NULL) {
			exit(EXIT_FAILURE);
		}
		for (int i=0; i<v->capacity; i++) {
			a[i] = v->array[i];
		}
		free(v->array);
		v->array = a;
	}
	v->array[v->size++] = value;
}
