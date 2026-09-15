#include <iostream>

using namespace std;

int add(int a, int b) {
	return a+b;
}

int main() {
	int a,b;
	cout<<"Enter the numbers: ";
	cin>>a>>b;
	cout<<a<<'+'<<b<<'='<<add(a,b)<<endl;
	return 0;
}
