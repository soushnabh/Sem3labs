#include <iostream>
#include <utility>

using namespace std;

class Buffer {
public:
  int *data;
  int size;
  // Parameterized Constructor
  Buffer(int size) {
    this->size = size;
    data = new int[size];
  }

  // Copy Constructor
  Buffer(const Buffer &a) {
    size = a.size;
    data = new int[size];
    for (int i = 0; i < size; i++) {
      data[i] = a.data[i];
    }
  }

  // Move Constructor
  Buffer(Buffer &&a) {
    size = a.size;
    a.size = 0;
    data = a.data;
    a.data = nullptr;
  }

  // Destructor
  ~Buffer() { delete[] data; }
};

int main() {
  int n;
  cout << "Enter the Buffer length: ";
  cin >> n;
  Buffer a(n);
  Buffer b = a;
  Buffer c = std::move(b);
  return 0;
}
