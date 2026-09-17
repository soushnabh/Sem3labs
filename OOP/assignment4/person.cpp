#include <iostream>
#include <utility>

using namespace std;

class Person {
public:
  string name;
  int age;
  // Parameterized Constructor
  Person(string name, int age) {
    this->name = name;
    this->age = age;
  }

  // Copy Constructor
  Person(const Person &a) {
    name = a.name;
    age = a.age;
  }

  // Move Constructor
  Person(Person &&a) {
    age = a.age;
    a.age = 0;
    name = std::move(a.name);
  }
};

int main() {
  string firstname, lastname;
  int age;
  cout << "Enter the name: ";
  cin >> firstname >> lastname;
  string name = firstname + ' ' + lastname;
  cout << "Enter the age: ";
  cin >> age;
  Person a(name, age);
  Person b = a;
  Person c = std::move(b);
  return 0;
}
