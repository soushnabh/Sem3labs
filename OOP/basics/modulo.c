#include <stdio.h>

int modulo(int a, int b) {
	return a%b;
}

int main() {
	printf("Enter two numbers: ");
	int n1,n2;
	scanf("%d %d", &n1, &n2);
	int remainder = modulo(n1, n2);
	printf("The remainder is %d\n", remainder);
	return 0;
}
