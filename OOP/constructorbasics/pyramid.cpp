#include <cstring>
#include <iostream>
#include <cmath>

using namespace std;

class Pyramid {
  double b,l;
  public:
    Pyramid(double b, double l) {
      this->b = b;
      this->l = l;
    }  
    double area() {
      return pow(b,2)+2*b*l;
    }
};

int main() {
  double b,l;
  cout<<"Enter the length of the base: ";
  cin>>b;
  cout<<"Enter the length of the slant: ";
  cin>>l;
  Pyramid p(b,l);
  cout<<"The area of the pyramid is: "<<p.area()<<endl;
  return 0;
}
