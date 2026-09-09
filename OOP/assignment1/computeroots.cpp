#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

class ComputeRoots {
    double fx(double x) { return pow(x, root) - n; }
    double gx(double x) {
        return ((root - 1) * x + (n / pow(x, root - 1))) / root;
    }
    double ddx(double x) { return root * pow(x, root - 1); }
    int approx_root() {
        long long l = 0, r = n, m;
        while (l <= r) {
            m = (l + r) / 2;
            if (pow(m, root) <= n) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return m;
    }

   public:
    double n;
    int iters;
    int root;
    double sol;

    void set_sol() { sol = approx_root(); }

    void newton_raphson(int iters) {
        if (sol == 0) {
            return;
        }
        sol = sol - (fx(sol) / ddx(sol));
        if (iters == 1) {
            return;
        }
        newton_raphson(iters - 1);
    }
    void secant(int iters) {
        if (sol == 0) {
            return;
        }
        int b = sol + 1;
        sol = ((b * fx(sol)) - (sol * fx(b))) / (fx(sol) - fx(b));
        if (iters <= 2) {
            return;
        }
        secant(iters - 1);
    }
    void fixedpointiter(int iters) {
        if (sol == 0) {
            return;
        }
        sol = gx(sol);
        if (iters == 1) {
            return;
        }
        fixedpointiter(iters - 1);
    }
};

int main() {
    ComputeRoots c;
    cout << "Enter n: ";
    cin >> c.n;
    cout << "Enter the root: ";
    cin >> c.root;
    cout << "Enter the number of iterations: ";
    cin >> c.iters;
    c.set_sol();

    char method;
    cout << "Enter the method to be used:" << endl;
    cout << "(N)ewton, (S)ecant or (F)ixed Point: ";
    cin >> method;
    switch (method) {
        case 'N': {
            c.newton_raphson(c.iters);
            break;
        }
        case 'S': {
            c.secant(c.iters);
            break;
        }
        case 'F': {
            c.fixedpointiter(c.iters);
            break;
        }
        default: {
            cout << "Invalid Input " << "\"" << method << "\"" << endl;
            return 1;
        }
    }

    cout << "The root is: " << fixed << setprecision(15) << c.sol << endl;
    return 0;
}
