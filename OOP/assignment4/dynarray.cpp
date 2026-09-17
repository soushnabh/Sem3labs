#include <iostream>

using namespace std;

class DynamicArray {
public:
  int *data;
  int size;
  DynamicArray(int size) {
    this->size = size;
    data = new int[size];
  }

  ~DynamicArray() { delete[] data; }

  void input() {
    cout << "Enter the elements: ";
    for (int i = 0; i < size; i++) {
      cin >> data[i];
    }
  }

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
  cout << "Enter the DynamicArray length: ";
  cin >> n;
  DynamicArray a(n);
  a.input();
  a.display();
  return 0;
}
