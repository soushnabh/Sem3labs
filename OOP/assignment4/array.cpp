#include <iostream>

using namespace std;

class Array {
public:
  int *data;
  int size;
  // Parameterized Constructor
  Array(int size) {
    this->size = size;
    data = new int[size];
  }

  // Copy Constructor
  Array(const Array &a) {
    size = a.size;
    data = new int[size];
    for (int i = 0; i < size; i++) {
      data[i] = a.data[i];
    }
  }

  // Destructor
  ~Array() { delete[] data; }

  // Display
  void display() {
    cout << '[';
    for (int i = 0; i < size; i++) {
      if (i > 0) {
        cout << ", ";
      }
      cout << data[i];
    }
    cout << ']' << endl;
  }
};

int main() {
  int n;
  cout << "Enter the array length: ";
  cin >> n;
  Array a(n);
  Array b = a;
  a.display();
  b.display();
  return 0;
}
