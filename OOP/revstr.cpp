#include<iostream>
#include<string>

using namespace std;

int main() {
  string str;
  cout<<"Enter the string: ";
  cin>>str;
  int l = str.length();
  for (int i = 0; i<l/2; i++){
    char temp = str[i];
    str[i] = str[l-i-1];
    str[l-i-1]=temp;
  }
  cout<<str<<endl;
}
