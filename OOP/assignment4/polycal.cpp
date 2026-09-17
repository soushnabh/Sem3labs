#include <iostream>

using namespace std;

struct monomial {
  int coeff;
  int power;
};

class DynamicArray {
public:
  monomial *data;
  int size;
  DynamicArray(int size) {
    this->size = size;
    data = new monomial[size];
  }
  DynamicArray(int size, int args[][2]) {
    this->size = size;
    data = new monomial[size];
    for (int i = 0; i < size; i++) {
      data[i].coeff = args[i][0];
      data[i].power = args[i][1];
    }
  }
  DynamicArray(const DynamicArray &other) {
    size = other.size;
    data = new monomial[size];
    for (int i = 0; i < size; i++) {
      data[i] = other.data[i];
    }
  }

  ~DynamicArray() { delete[] data; }
};

class Polynomial {
  int len = 0;
  DynamicArray expr{len};

public:
  Polynomial(int l) : len(l), expr(l) {}
  Polynomial(const DynamicArray &other) : len(other.size), expr(other) {}

  void set_sum(const Polynomial &a, const Polynomial &b) {
    if (a.len + b.len == this->len) {
      for (int i = 0; i < a.len; i++) {
        this->expr.data[i] = a.expr.data[i];
      }
      for (int i = 0; i < b.len; i++) {
        this->expr.data[a.len + i] = b.expr.data[i];
      }
    }
  }
  void set_product(const Polynomial &a, const Polynomial &b) {
    if (a.len * b.len == this->len) {
      for (int i = 0; i < a.len; i++) {
        for (int j = 0; j < b.len; j++) {
          this->expr.data[i * b.len + j].coeff =
              a.expr.data[i].coeff * b.expr.data[j].coeff;
          this->expr.data[i * b.len + j].power =
              a.expr.data[i].power + b.expr.data[j].power;
        }
      }
    }
  }

  string format() {
    string ans;
    for (int i = 0; i < len; i++) {
      if (expr.data[i].coeff != 0) {
        if (expr.data[i].coeff < 0) {
          ans += " - ";
        } else if (i > 0) {
          ans += " + ";
        }
        if (abs(expr.data[i].coeff) != 1 || expr.data[i].power == 0) {
          ans += to_string(abs(expr.data[i].coeff));
        }
        if (expr.data[i].power != 0) {
          ans += 'x';
          if (expr.data[i].power != 1) {
            ans += '^';
            ans += to_string(expr.data[i].power);
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

int main() {
  int x = 3;
  int a1[][2] = {{3, 2}, {2, 1}, {1, 0}};
  DynamicArray d1(x, a1);
  Polynomial a(d1);

  int y = 2;
  int a2[][2] = {{3, 2}, {2, 1}};
  DynamicArray d2(y, a2);
  Polynomial b(d2);

  char op;
  cout << "(+)/(*): ";
  cin >> op;

  cout << a.format() << endl;
  cout << op << endl;
  cout << b.format() << endl;
  cout << '=' << endl;
  switch (op) {
  case '+': {
    int z = x + y;
    Polynomial c(z);
    c.set_sum(a, b);
    cout << c.format() << endl;
    break;
  }
  case '*': {
    int z = x * y;
    Polynomial c(z);
    c.set_product(a, b);
    cout << c.format() << endl;
    break;
  }
  default: {
    cout << "Invalid input." << endl;
  }
  }
  return 0;
}
