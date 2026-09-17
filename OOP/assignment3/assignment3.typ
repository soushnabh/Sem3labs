#import "../template.typ": assignment

#show: assignment.with(
  title: "Assignment 3",
  course: "ITB301: Object Oriented Programming",
  author: "Soushnabh Bagchi",
  student_id: "2505264",
  faculty: "Er Sudipto Patowary",
  date: "September 25, 2026",
)

== 1. Create a class Polynomial that stores the coefficients of a polynomial using a dynamic array.

*Code:*
#raw(read("polynomial.cpp"), lang: "cpp", block: true)

*Output:*
#block(
  fill: rgb("#f1f5f9"),
  stroke: 0.5pt + rgb("#94a3b8"),
  inset: 8pt,
  radius: 4pt,
  width: 100%,
)[
```
Enter the number of polynomial terms: 6
Enter the coefficient and polynomial for each term (ax^b):
-13 0
9 4
-2 2
6 7
8 1
-4 5
Original: 6x^7 - 4x^5 + 9x^4 - 2x^2 + 8x - 13
Derivative: 42x^6 - 20x^4 + 36x^3 - 4x + 8
Program executed.
```
```
Enter the number of polynomial terms: 8
Enter the coefficient and polynomial for each term (ax^b):
-1 0
4 1
-5 9
7 3
12 8
-10 2
3 6
-1 4
Original:  - 5x^9 + 12x^8 + 3x^6 - x^4 + 7x^3 - 10x^2 + 4x -
Derivative:  - 45x^8 + 96x^7 + 18x^5 - 4x^3 + 21x^2 - 20x + 4
Program executed.
```
]

== 2. Create a class that represents a function and differentiates it.

*Code:*
#raw(read("diff.cpp"), lang: "cpp", block: true)

*Output:*
#block(
  fill: rgb("#f1f5f9"),
  stroke: 0.5pt + rgb("#94a3b8"),
  inset: 8pt,
  radius: 4pt,
  width: 100%,
)[
```
f(x): 4x^3 + 3x^2 - 5x + 2
f'(x): 12x^2 + 6x - 5
Enter the value of a: 5
Value: 325
```
```
f(x): 4x^3 + 3x^2 - 5x + 2
f'(x): 12x^2 + 6x - 5
Enter the value of a: 6.7
Value: 573.88
```
```
f(x): 4x^3 + 3x^2 - 5x + 2
f'(x): 12x^2 + 6x - 5
Enter the value of a: 0
Value: -5
```
]

== 3. Create a class that represents a function and integrates it using Trapezoidal rule.

*Code:*
#raw(read("int.cpp"), lang: "cpp", block: true)

*Output:*
#block(
  fill: rgb("#f1f5f9"),
  stroke: 0.5pt + rgb("#94a3b8"),
  inset: 8pt,
  radius: 4pt,
  width: 100%,
)[
```
f(x): x^2
Enter the number of divisions: 1
Integration: 4.000000000000000
```
```
f(x): x^2
Enter the number of divisions: 999999999
2.666666666666204
```
]
