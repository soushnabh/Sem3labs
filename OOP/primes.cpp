#include <iostream>
using namespace std;

class prime {
    bool isPrime(int n) {
        for (int i = 2; i<n; i++) {
            if (n%i==0) {
                return false;
            }
        }
        return true;
    }
  public:
    int n;

    //some function
};

int main() {
    prime p;
    cout<<"Enter n: ";
    cin>> p.n;
    //some output
    return 0;
}
