#include <iostream>
using namespace std;

int main() {
	char a;
	cout<<"Enter the operation: (f)or, (w)hile or (d)o: ";cin>>a;
	int n;
	cout<<"Enter the number : ";cin>>n;
	
	switch (a) {
case 'f': {
	      for (int i = 0; i<=3; i++) {
		      cout<<n;
	      }
	      break;
      }
case 'w': {
              int i = 0;
	      while (i<=3) {
		      cout<<n;
		      i+=1;
	      }
	      break;
      }
case 'd': {
	      int i = 0;
	      do{
		      cout<<n;
		      i++;
	      } while (i<=3);
	      break;
      }
default: {
	      cout<<"Invalid Output, Exiting Program"<<endl;
	      return 1;
      }
	}
	cout<<endl;
	return 0;
}


