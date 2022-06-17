#include <iostream>
 
using namespace std;

#define switchElements(A, B) { int c = A; A = B; B = c; }

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
 
int main() {
	int array[5] = { 0, 5, 4, 2, 1 };

	selectionSort(array, 5);
 
	return 0;
}
