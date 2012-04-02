#include <stdio.h>

int choosePivot(int l, int r) {
	return l;
}

void swap(int *x, int *y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}

int test = 0;

void quicksort(int arr[], int left, int right) {
	test += (right - left - 1);

	int tmp;
	int l = left;
	int r = right;

	int pivot = choosePivot(l, r);
	
	do {
		while (arr[l] < arr[pivot]) {
			l++;
		}
		
		while (arr[r] > arr[pivot]) {
			r--;
		}
		
		if (l <= r) {
			tmp = arr[l];
			arr[l] = arr[r];
			arr[r] = tmp;
			
			l++;
			r--;
		}
	} while (l <= r);
	
	if (left < r) {
		quicksort(arr, left, r);
	}
	
	if (l < right) {
		quicksort(arr, l, right);
	}
}

int main(int argv, char** args) {
	int arr[] = {18,14,7,10,9,11,3,6,17,8,16,2,5,1,13,12,15,4};
	int n = 18;

	quicksort(arr, 0, n - 1);
	
	printf("%d\n", test);
	
	int i;
	for (i = 0; i < n; i++) {
		printf(" %d\n", arr[i]);
	}
	
	return 0;
}