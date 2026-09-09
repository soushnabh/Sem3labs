#include <iostream>
#include <string>

using namespace std;

class ToBinary {
   public:
    int n;
    string ans = "";

    void binary_direct() {
        for (int i = 31; i >= 0; i--) {
            ans += to_string((n >> i) & 1);
        }
    }

    void binary_factor() {
        int temp = n;
        while (temp > 0) {
            ans = to_string(temp % 2) + ans;
            temp /= 2;
        }
    }
};

int main() {
    ToBinary b;
    cout << "Enter n: ";
    cin >> b.n;

    cout << "The binary representation is: " << endl;

    cout << "1. Using bitshifting." << endl;
    b.binary_direct();
    cout << b.ans << endl;
    b.ans = "";

    cout << "2. Using factorization." << endl;
    b.binary_factor();
    cout << b.ans << endl;

    return 0;
}
