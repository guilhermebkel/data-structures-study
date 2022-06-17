#include <iostream>
 
using namespace std;

int *merge(int *valuesL, int *valuesR, int nl, int nr) {
	int *result = (int *)malloc((nl+nr) * sizeof(int));

	int i = 0,  j = 0, k = 0;

	while (i < nl && j < nr) {
		if (valuesL[i] < valuesR[j]) {
			result[k] = valuesL[i];
			i++;
		} else {
			result[k] = valuesR[j];
			j++;
		}

		k++;
	}

	if (k < nl + nr) {
		for(; i < nl; i++) {
			result[k] = valuesL[i];
			k++;
		}

		for(; j < nr; j++) {
			result[k] = valuesR[j];
			k++;
		}
	}

	return result;
}

void mergeSort(int *vector, int left, int right) {
	int mid;

	if (left < right) {
		mid = (left + right) / 2;

		mergeSort(vector, left, mid);
		mergeSort(vector, mid + 1, right);

		merge(vector, vector, left, right);
	}
}
 
int main() {
	int array[5] = { 0, 5, 4, 2, 1 };

	mergeSort(array, 0, 5);
 
	return 0;
}
