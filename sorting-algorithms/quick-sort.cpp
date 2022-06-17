#include <iostream>
 
using namespace std;

void partition(int left, int right, int *i, int *j, int *vector) {
	int x, w;

	*i = left;
	*j = right;

	x = vector[(*i + *j)/2];

	do {
		while (x > vector[*i]) {
			(*i)++;
		}

		while (x < vector[*j]) {
			(*j)--;
		}

		if (*i <= *j) {
			w = vector[*i];
			vector[*i] = vector[*j];
			vector[*j] = w;

			(*i)++;
			(*j)--;
		}

	} while (*i <= *j);
}

void order(int left, int right, int *vector) {
	int i, j;

	partition(left, right, &i, &j, vector);

	if (left < j) {
		order(left, j, vector);
	}

	if (i < right) {
		order(i, right, vector);
	}
}

void quickSort(int *vector, int n) {
	order(0, n-1, vector);
}
 
int main() {
	int array[5] = { 0, 5, 4, 2, 1 };

	quickSort(array, 5);
 
	return 0;
}
