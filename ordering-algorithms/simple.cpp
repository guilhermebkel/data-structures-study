#include <iostream>
 
using namespace std;

#define switchElements(A, B) { int c = A; A = B; B = c; }
 
void bubbleSort (int *vector, int n) {
	int i, j;

	for (i = 0; i < n - 1; i++) {
			for (j = 1; j < n - 1; j++) {
					if (vector[j] < vector[j - 1]) {
						switchElements(vector[j - 1], vector[j]);
					}
			}
	}
}

void selectionSort (int *vector, int n) {
	int i, j, Min;
	
	for (i = 0; i < n - 1; i++) {
		Min = i;
		
		for (j = i + 1 ; j < n; j++) {
			if (vector[j] < vector[Min]) {
				Min = j;
			}
	
		}

		switchElements(vector[i], vector[Min]);
	}
}

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
	
 
    return 0;
}

