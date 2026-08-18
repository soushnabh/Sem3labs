#include <iostream>
using namespace std;

void add_to(int *a, int b) {
	*a += b;
}

int main() {
	int a,b;
	cout<<"Enter two values: ";
	cin>>a>>b;
	add_to(&a, b);
	cout<<a<<endl;
}
