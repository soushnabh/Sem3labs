#include <stdio.h>

int add(int a, int b) {
	return a+b;
}

int main() {
	printf("Enter two numbers: ");
	int n1,n2;
	scanf("%d %d", &n1, &n2);
	int sum = add(n1, n2);
	printf("%d+%d=%d\n", sum);
	return 0;
}
