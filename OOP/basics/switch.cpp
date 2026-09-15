#include <iostream>
using namespace std;

int main() {
	char a;
	cout<<"Enter the operation: +, -, * or /: ";cin>>a;
	int n1,n2;
	cout<<"Enter number 1: ";cin>>n1;
	cout<<"Enter number 2: ";cin>>n2;
	
	int sol;
	switch (a) {
case '+': {
	      sol = n1+n2;
	      break;
      }
case '-': {
	      sol = n1-n2;
	      break;
      }
case '*': {
	      sol = n1*n2;
	      break;
      }
case '/': {
	      sol = n1/n2;
	      break;
      }
default: {
	      cout<<"Invalid Output, Exiting Program"<<endl;
	      return 1;
      }
	}
	cout<<n1<<a<<n2<<"="<<sol<<endl;
	return 0;
}


