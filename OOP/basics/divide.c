#include <stdio.h>

int divide(int a, int b) {
	return a/b;
}

int main() {
	printf("Enter two numbers: ");
	int n1,n2;
	scanf("%d %d", &n1, &n2);
	int quotient = divide(n1, n2);
	printf("The quotient is %d\n", quotient);
	return 0;
}
