#include <stdio.h>

int main() {
	int len;
	printf("Enter array length: "); scanf("%d", &len);
	int i;
	int arr[len];
	printf("Enter array elements: ");
	for (i = 0; i<len; i++) {
		scanf("%d ", &arr[i]);
	}
	int sum = 0;
	for (i = 0; i<len; i++) {
		sum += arr[i];
	}
	printf("The sum is %d\n", sum);
	return 0;
}
