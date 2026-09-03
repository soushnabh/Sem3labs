#include <bits/types/error_t.h>
#include <iostream>
#include <string>
using namespace std;
class BankAccount {
  public:    
    string fname;
    string lname;
    long long accountno;
    int balance;
};

int main(){
  char io = 'y';
  BankAccount n;
  while (io=='y') {
    cout<<"Enter the bank account details."<<endl;
    cout<<"Name: ";
    cin>>n.fname>>n.lname;
    cout<<"Account No.: ";
    cin>>n.accountno;
    cout<<"Balance: ";
    cin>>n.balance;

    cout<<"Bank account details: "<<endl;
    cout<<"Name: "<<n.fname<<' '<<n.lname<<endl;
    cout<<"Account No: "<<n.accountno<<endl;
    cout<<"Balance: "<<n.balance<<endl;
  
    cout<<"Do you want to enter another record? (y/n): ";
    cin>>io;
  }
}
