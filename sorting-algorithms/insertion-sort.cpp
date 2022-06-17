#include <iostream>
 
using namespace std;

void insertionSort (int *vector, int n) {
	int i, j;

	int aux;

	for (i = 1; i < n; i++) {
		aux = vector[i];
		j = i - 1;

		while (( j >= 0 ) && (aux < vector[j])) {
			vector[j + 1] = vector[j];
			j--;
		}

		vector[j + 1] = aux;
	}	
}
 
int main() {
	int array[5] = { 0, 5, 4, 2, 1 };

	insertionSort(array, 5);
 
	return 0;
}
