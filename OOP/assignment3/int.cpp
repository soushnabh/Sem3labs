#include <algorithm>
#include <cmath>
#include <cstddef>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct monomial {
  int coeff;
  int power;
};

class Polynomial {
protected:
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
};

class Integrate : public Polynomial {
public:
  Integrate(const Polynomial &other, double a, double b, int divs)
      : Polynomial(other) {
    this->divs = divs;
    this->a = a;
    this->b = b;
  }
  int divs;
  double a, b;
  double trapezoidal() {
    double h = (b - a) / divs;
    double sum = 0;
    int mul;
    for (int i = 0; i <= divs; i++) {
      if (i == 0 || i == divs) {
        mul = 1;
      } else {
        mul = 2;
      }
      for (int j = 0; j < len; j++) {
        sum += mul * expr[j].coeff * pow(i * h, expr[j].power);
      }
    }
    return sum * (h / 2);
  }
};

int main() {
  int n = 1;
  int args[][2] = {{1, 2}};
  Polynomial p(n, args);
  p.sort();
  cout << "f(x): " << p.format() << endl;

  int divs;
  cout << "Enter the number of divisions: ";
  cin >> divs;
  Integrate i(p, 0, 2, divs);

  cout << "Integration: " << fixed << setprecision(15) << i.trapezoidal()
       << endl;
  return 0;
}
