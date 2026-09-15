#include <iostream>

using namespace std;
class A { //class is a collection of data members and function members
  public: //outside class anyone can access
    int a,b;

    //int add(int a, int b) {
    //  return a + b;
    //}

  //protected: outside class only derived classes can access
  //private: outside class noone can access
};

int main() {
  A a1; //object

  //runtime binding
  cout<<"Enter a: ";
  cin>>a1.a;
  cout<<"Enter b: ";
  cin>>a1.b;

  //compile time binding
  //a1.a = 10;
  //a1.b = 20;
  cout<<a1.a+a1.b<<endl;
  return 0;
}

//Assignment: 
//1)WAP to calculate the factorial value of a given number
//using recursive function and non-recursive function
//2) Calculate fibonacci series
//3) Generate Prime numbers of a given number
//(have to use class)