#include <iostream>
#include <cmath>
using namespace std;

int main() {
  int a,b,c;
  cout<<"Enter the first three terms: ";
  cin>>a>>b>>c;
  int n;
  cout<<"Enter the number of terms: ";
  cin>>n;
  if (2*b == a+c){
    cout<<"The series is an AP Series."<<endl;
    int d = b-a;
    double sum = 0;
    for(int i=1; i<=n; i++){
      sum += a + (i-1)*d;
    }
    cout<<"The sum of the terms is: "<<sum<<endl;
  }	else if (b*b == a*c){
    cout<<"The series is a GP Series."<<endl;
    int r = b/a;
    double sum = 0;
    for(int i=1; i<=n; i++){
      sum += a*(pow(r, i-1));
    }
    cout<<"The sum of the terms is: "<<sum<<endl;
  } else {
    cout<<"The series is neither AP nor GP."<<endl;
  }
}
