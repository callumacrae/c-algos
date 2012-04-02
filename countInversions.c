#include <stdio.h>
#include <math.h>

int main(int argv, char** args)
{
	int arr[] = {2, 5, 1, 3, 4};
	int n = 5; // length of array
	
	int count = 0, billions = 0;
	int i, j;
	
	for (i = 0; i < n - 1; i++) {
		for (j = i + 1; j < n; j++) {
			if (arr[i] > arr[j]) {
				if (count == 1000000000) {
					billions++;
					count = 0;
				}
				count++;
			}
		}
	}
	
	char text[] = "Number of inversions:";
	if (billions == 0) {
		printf("%s %d\n", text, count);
	} else {
		for (i = 8; count < pow(10, i); i--) {
			billions *= 10;
		}
		printf("%s: %d%d\n", text, billions, count);
	}

	return 0;
}