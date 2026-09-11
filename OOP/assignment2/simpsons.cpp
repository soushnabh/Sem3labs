#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

class Integrate {
    double fx(double x) { return pow(x, 4); }
    // f(x) = x^4

   public:
    int n;
    double a = 0, b = 2;
    // lower bound: 0, upper bound: 2

    double integrate() {
        double h = (b - a) / n;
        double sum = 0;
        int mul;
        for (int i = 0; i <= n; i++) {
            if (i == 0 || i == n) {
                mul = 1;
            } else if (i % 2 == 0) {
                mul = 2;
            } else {
                mul = 4;
            }
            sum += mul * fx(i * h);
        }
        return sum * (h / 3);
    }
};

int main() {
    Integrate i;
    cout << "Enter the number of iterations: ";
    cin >> i.n;
    if (i.n % 2 != 0) {
        cout << "Input must be an even number" << endl;
        return 1;
    }
    cout << "The result is: " << fixed << setprecision(15) << i.integrate()
         << endl;
    return 0;
}
