#include <iostream>
 
using namespace std;

void remake(int left, int right, int *vector){
	int i, j;
	int x;

	i = left;
	j = i * 2;
	x = vector[i];

	while (j <= right) {
		if (j < right) {
			if (vector[j] < vector[j+1]) {
				j++;
			}
		}

		if (x >= vector[j]) {
			break;
		}

		vector[i] = vector[j];

		i = j;
		j = i *2;
	}

	vector[i] = x;
}

void build(int *vector, int n) {
	int left;
	
	left = n / 2 + 1;

	while (left > 1) {
		left--;
		remake(left, n, vector);
	}
}

void heapSort(int *vector, int n) {
	int left, right;
	int x;

	build(vector, n);

	left = 1;
	right = n;

	while (right > 1) {
		x = vector[1];
		vector[1] = vector[right];
		vector[right] = x;
		right--;

		remake(left, right, vector);
	}
}
 
int main() {
	int array[5] = { 0, 5, 4, 2, 1 };

	heapSort(array, 5);
 
	return 0;
}
