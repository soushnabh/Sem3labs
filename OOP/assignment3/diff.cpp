#include <algorithm>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct monomial {
  int coeff;
  int power;
};

class Polynomial {
  vector<monomial> expr;
  size_t len;

public:
  Polynomial(size_t l, int args[][2]) {
    len = l;
    for (int i = 0; i < l; i++) {
      this->insert(args[i]);
    }
  }
  void insert(int args[2]) { expr.push_back(monomial{args[0], args[1]}); }
  void derivative() {
    for (int i = 0; i < len; i++) {
      if (expr[i].power != 0) {
        expr[i].coeff *= expr[i].power;
        expr[i].power -= 1;
      } else {
        expr.erase(expr.begin() + i);
        len -= 1;
      }
    }
  }
  void sort() {
    std::sort(
        expr.begin(), expr.end(),
        [](const monomial &a, const monomial &b) { return a.power > b.power; });
  }
  string format() {
    string ans;
    for (int i = 0; i < len; i++) {
      if (expr[i].coeff != 0) {
        if (expr[i].coeff < 0) {
          ans += " - ";
        } else if (i > 0) {
          ans += " + ";
        }
        if (abs(expr[i].coeff) != 1 || expr[i].power == 0) {
          ans += to_string(abs(expr[i].coeff));
        }
        if (expr[i].power != 0) {
          ans += 'x';
          if (expr[i].power != 1) {
            ans += '^';
            ans += to_string(expr[i].power);
          }
        }
      }
    }
    if (ans.size() == 0) {
      return "0";
    }
    return ans;
  }
  double calc(double a) {
    double sum = 0;
    for (monomial &m : expr) {
      sum += m.coeff * pow(a, m.power);
    }
    return sum;
  }
};

int main() {
  int n = 4;
  int args[][2] = {{4, 3}, {3, 2}, {-5, 1}, {2, 0}};
  Polynomial p(n, args);
  p.sort();
  cout << "f(x): " << p.format() << endl;
  p.derivative();
  cout << "f'(x): " << p.format() << endl;

  double a;
  cout << "Enter the value of a: ";
  cin >> a;

  cout << "Value: " << p.calc(a) << endl;
  return 0;
}
