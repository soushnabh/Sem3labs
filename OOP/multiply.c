#include <stdio.h>

int multiply(int a, int b) {
	return a*b;
}

int main() {
	printf("Enter two numbers: ");
	int n1,n2;
	scanf("%d %d", &n1, &n2);
	int product = multiply(n1, n2);
	printf("The product is %d\n", product);
	return 0;
}
