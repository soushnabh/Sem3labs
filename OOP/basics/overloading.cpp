#include <iostream>
using namespace std;

int add(int a, int b);
float add(float a, float b);

int main() {

	float a,b;	
  char type;
  cout<<"Enter the type: ";
  cin>>type;
  cout<<"Enter the numbers: ";
  cin>>a>>b;
  switch (type) 
  {
    case 'f': 
	    {

	    	cout<<add(a,b)<<endl;
				break;
      	
	    }   
    case 'i': 
	    {
	    	cout<<add((int)a, (int)b)<<endl;
        	break;
      }
    default: {
      cout<<"Not a valid type"<<endl;
    }
  }
}


int add(int a, int b)
{

  return a+b;
}

float add(float a, float b) 
{
	return a+b;
}
