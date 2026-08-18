#include <iostream>
#include <cmath>
using namespace std;

int main(){
  cout<<"Enter the no. of elements to input: ";
  int a;
  cin>>a;
  if (a<3){
    cout<<"You must enter 3 or more elements."<<endl;
    return 1;
  }
  int arr[a];
  cout<<"Enter the elements of the array: ";
  for (int i = 0; i<a; i++){
    cin>>arr[i];
  }
  int is_ap = 1, is_gp = 1;
  for (int i = 1; i<a-1; i++){
    if (is_ap==1 && 2*arr[i]!=arr[i-1]+arr[i+1]){
      is_ap = 0;
    }
    if (is_gp==1 && arr[i]*arr[i]!=arr[i-1]*arr[i+1]){
      is_gp = 0;
    }
  }
  float n;
  cout<<"Enter the number of elements to sum: ";
  cin>>n;
  float sum=0;
  a = arr[0];
  if (is_ap==1){
    cout<<"The series is an AP."<<endl;
    int d = arr[1]-arr[0];
    sum = (n/2)*(2*a + (n-1)*d);
  } else if (is_gp==1) {
    cout<<"The series is an GP."<<endl;
    int r = arr[1]/arr[0];
    sum = a*((pow(r,n)-1)/(r-1));
  } else {
    cout<<"The series is neither an AP nor a GP."<<endl;
    return 2;
  }
  cout<<"The sum of the series upto "<<n<<" terms is: "<<sum<<endl;
  return 0;
}
