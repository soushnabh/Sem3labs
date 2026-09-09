#include <iostream>

using namespace std;

class factorial {
  public:
    int n;

    int fact_rec(int a) {
        if (a<=1) {
            return 1;
        }
        return a*fact_rec(a-1);
    }
    int fact() {
        int ans = 1;
        for (int i = 1; i<= n; i++) {
            ans*=i;
        }
        return ans;
    }
};

int main() {
    factorial f;
    cout<<"Enter n: ";
    cin>> f.n;
    cout<<"The factorial is: "<<endl;
    cout<<"Recursive: "<<f.fact_rec(f.n)<<endl;
    cout<<"Iterative: "<<f.fact()<<endl;
    return 0;
}
