#import "../template.typ": assignment

#show: assignment.with(
  title: "Assignment 5",
  course: "ITB301: Object Oriented Programming",
  author: "Soushnabh Bagchi",
  student_id: "2505264",
  faculty: "Er Sudipto Patowary",
  date: "November 5, 2026",
)

== 1. Create an abstract base class Payment with a pure virtual function `processPayment(double amount)`. Implement derived classes CreditCardPayment, PayPalPayment and BitcoinPayment. Write a global function `void executeTransaction(Payment* paymentMethod, double amount)` that demonstrates runtime polymorphism.

*Code:*
#raw(read("payment.cpp"), lang: "cpp", block: true)

*Output:*
#block(
  fill: rgb("#f1f5f9"),
  stroke: 0.5pt + rgb("#94a3b8"),
  inset: 8pt,
  radius: 4pt,
  width: 100%,
)[
```
paying amount: 50 via Credit Card...
paying amount: 100 via PayPal...
paying amount: 150 via Bitcoin...
```
]

== 2. Design a base class SmartDevice with virtual functions `turnOn()` and `turnOff()`, and a pure virtual function `getDeviceStatus()`. Derive SmartLight and SmartThermostat from it. Overload `turnOn()` in SmartLight to also dim to 50% by default and ensure your system can manage an array of different devices using `SmartDevice*` pointers.

*Code:*
#raw(read("device.cpp"), lang: "cpp", block: true)

*Output:*
#block(
  fill: rgb("#f1f5f9"),
  stroke: 0.5pt + rgb("#94a3b8"),
  inset: 8pt,
  radius: 4pt,
  width: 100%,
)[
```
Turning all devices ON
Turning SmartLight On (dimmed to 50%)...
Status: Active

Turning Device On...
Status: Active

Turning SmartLight On (dimmed to 80%)...

Turning all devices OFF
Turning Device Off...
Turning Device Off...
```
]

== 3. Create a base class Report and derived classes FullTimeReport and ContractReport. Create a base class Employee with a virtual function `Report* generateReport()`. Derive FullTimeEmployee and ContractEmployee and use *covariant return types* so their respective `generateReport()` methods return the specific derived report types instead of the base pointer.

*Code:*
#raw(read("report.cpp"), lang: "cpp", block: true)

*Output:*
#block(
  fill: rgb("#f1f5f9"),
  stroke: 0.5pt + rgb("#94a3b8"),
  inset: 8pt,
  radius: 4pt,
  width: 100%,
)[
```
Direct calls
Full-Time Employee Report: Salary + Benefits included.
Contract Employee Report: Hourly Rate + Invoice included.

Polymorphic call via base pointer
Full-Time Employee Report: Salary + Benefits included.
```
]

== 4. Write a base class DatabaseConnection with a virtual function `void logConnectionStatus()`. Call this function inside the DatabaseConnection constructor. Create a derived class SecureConnection that overrides `logConnectionStatus()` to output "Secure Logged". Instantiate a SecureConnection object and explain why the output shows the base version instead of the derived version.

*Code:*
#raw(read("dbconn.cpp"), lang: "cpp", block: true)

*Output:*
#block(
  fill: rgb("#f1f5f9"),
  stroke: 0.5pt + rgb("#94a3b8"),
  inset: 8pt,
  radius: 4pt,
  width: 100%,
)[
```
log connection established
```
]

*Explanation:*
During the construction of SecureConnection, the base class constructor `DatabaseConnection()` executes first. At this point, the derived part of the object has not yet been initialized. To prevent accessing uninitialized derived members, C++ resolves all virtual function calls to the base class's implementation while inside the base constructor.
