#include <stdio.h>

int subtract(int a, int b) {
	return a-b;
}

int main() {
	printf("Enter two numbers: ");
	int n1,n2;
	scanf("%d %d", &n1, &n2);
	int diff = subtract(n1, n2);
	printf("The difference is %d\n", diff);
	return 0;
}
