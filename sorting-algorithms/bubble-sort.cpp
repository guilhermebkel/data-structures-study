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
 
int main() {
	int array[5] = { 0, 5, 4, 2, 1 };

	bubbleSort(array, 5);
 
	return 0;
}
