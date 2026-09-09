#import "../template.typ": assignment

#show: assignment.with(
  title: "Assignment 1",
  course: "ITB301: Object Oriented Programming",
  author: "Soushnabh Bagchi",
  student_id: "2505264",
  faculty: "Er Sudipto Patowary",
  date: "September 18, 2026",
)

== 1. Write a program to convert decimal to binary number using function.

*Code:*
#raw(read("binary.cpp"), lang: "cpp", block: true)

*Output:*
#block(
  fill: rgb("#f1f5f9"),
  stroke: 0.5pt + rgb("#94a3b8"),
  inset: 8pt,
  radius: 4pt,
  width: 100%,
)[
```
Enter n: 10
The binary representation is:
1. Using bitshifting.
00000000000000000000000000001010
2. Using factorization.
1010
```
```
Enter n: 123456789
The binary representation is:
1. Using bitshifting.
00000111010110111100110100010101
2. Using factorization.
111010110111100110100010101
```
]

== 2. Write a program to using switch statement for the following:
- Root of a given number using Newton-Raphson Method.
- Secant Method
- Fixed Point Iteration


*Code:*
#raw(read("computeroots.cpp"), lang: "cpp", block: true)

*Output:*
#block(
  fill: rgb("#f1f5f9"),
  stroke: 0.5pt + rgb("#94a3b8"),
  inset: 8pt,
  radius: 4pt,
  width: 100%,
)[
```
Enter n: 64
Enter the root: 2
Enter the number of iterations: 5
Enter the method to be used:
(N)ewton, (S)ecant or (F)ixed Point: N
The root is: 8.000000000000000
```
```
Enter n: 99
Enter the root: 3
Enter the number of iterations: 3
Enter the method to be used:
(N)ewton, (S)ecant or (F)ixed Point: N
The root is: 4.626066084823458
```
```
Enter n: 759237165
Enter the root: 5
Enter the number of iterations: 10
Enter the method to be used:
(N)ewton, (S)ecant or (F)ixed Point: S
The root is: 59.713907599367566
```
```
Enter n: 1122334455
Enter the root: 4
Enter the number of iterations: 7
Enter the method to be used:
(N)ewton, (S)ecant or (F)ixed Point: F
The root is: 183.033495564811233
```
]
