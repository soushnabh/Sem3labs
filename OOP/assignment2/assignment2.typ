#import "../template.typ": assignment

#show: assignment.with(
  title: "Assignment 2",
  course: "ITB301: Object Oriented Programming",
  author: "Soushnabh Bagchi",
  student_id: "2505264",
  faculty: "Er Sudipto Patowary",
  date: "September 25, 2026",
)

== 1. Write a Program to calculate the integration of *$integral_0^2 x^4 dif x$* using Simpson's Rule.

*Code:*
#raw(read("simpsons.cpp"), lang: "cpp", block: true)

*Output:*
#block(
  fill: rgb("#f1f5f9"),
  stroke: 0.5pt + rgb("#94a3b8"),
  inset: 8pt,
  radius: 4pt,
  width: 100%,
)[
```
Enter the number of iterations: 10
The result is: 6.400426666666667
```
```
Enter the number of iterations: 7500
The result is: 6.400000000000006
```
```
Enter the number of iterations: 9999
Input must be an even number
```
]
