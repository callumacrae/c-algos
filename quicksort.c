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

void quicksort(int list[], int l, int r) {
	if (r > l + 1) {
		test += (r - l - 1);

		int k = choosePivot(l, r);
		int pivot = list[k];

		int i = l + 1;
		int j = r;

		while (i <= j) {
			while ((i <= r) && (list[i] <= pivot))
				i++;
			while ((j >= l) && (list[j] > pivot))
				j--;
			if (i < j)
				swap(&list[i], &list[j]);
		}

		swap(&list[l], &list[i - 1]);

		quicksort(list, l, j - 1);
		quicksort(list, j + 1, r);
	}
}

int main(int argv, char** args) {
	int arr[] = {5,4,3,1,2};
	int n = 5;

	quicksort(arr, 0, n);
	
	printf("%d\n", test);
	
	int i;
	for (i = 0; i < n; i++) {
		printf(" %d\n", arr[i]);
	}
	
	return 0;
}