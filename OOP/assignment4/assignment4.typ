#import "../template.typ": assignment

#show: assignment.with(
  title: "Assignment 4",
  course: "ITB301: Object Oriented Programming",
  author: "Soushnabh Bagchi",
  student_id: "2505264",
  faculty: "Er Sudipto Patowary",
  date: "September 30, 2026",
)

== 1. Create a class Array containing an integer pointer data and an integer size. Allocate memory dynamically in the constructor and implement constructor methods.

*Code:*
#raw(read("array.cpp"), lang: "cpp", block: true)

*Output:*
#block(
  fill: rgb("#f1f5f9"),
  stroke: 0.5pt + rgb("#94a3b8"),
  inset: 8pt,
  radius: 4pt,
  width: 100%,
)[
```
Enter the array length: 5
[0, 0, 0, 0, 0]
[0, 0, 0, 0, 0]
```
]

== 2. Create a class Buffer containing a dynamically allocated array and implement constructor methods.

*Code:*
#raw(read("buffer.cpp"), lang: "cpp", block: true)

*Output:*
#block(
  fill: rgb("#f1f5f9"),
  stroke: 0.5pt + rgb("#94a3b8"),
  inset: 8pt,
  radius: 4pt,
  width: 100%,
)[
```
Enter the Buffer length: 10

⏵ Task `Compile & Run C++` finished successfully
```
]

== 3. Create a class Person and implement constructor methods.

*Code:*
#raw(read("person.cpp"), lang: "cpp", block: true)

*Output:*
#block(
  fill: rgb("#f1f5f9"),
  stroke: 0.5pt + rgb("#94a3b8"),
  inset: 8pt,
  radius: 4pt,
  width: 100%,
)[
```
Enter the name: Soushnabh Bagchi
Enter the age: 18

⏵ Task `Compile & Run C++` finished successfully
```
]

== 4. Write a C++ program to create a dynamic integer array using a constructor.

*Code:*
#raw(read("dynarray.cpp"), lang: "cpp", block: true)

*Output:*
#block(
  fill: rgb("#f1f5f9"),
  stroke: 0.5pt + rgb("#94a3b8"),
  inset: 8pt,
  radius: 4pt,
  width: 100%,
)[
```
Enter the DynamicArray length: 4
Enter the elements: 2 4 6 8
[2, 4, 6, 8]
```
]

== 5. Write a C++ program to multiply two polynomials using dynamic arrays and a constructor.

*Code:*
#raw(read("polymul.cpp"), lang: "cpp", block: true)

*Output:*
#block(
  fill: rgb("#f1f5f9"),
  stroke: 0.5pt + rgb("#94a3b8"),
  inset: 8pt,
  radius: 4pt,
  width: 100%,
)[
```
3x^2 + 2x + 1
*
3x^2 + 2x
=
9x^4 + 6x^3 + 6x^3 + 4x^2 + 3x^2 + 2x
```
]

== 6. Write a C++ program to implement a Polynomial Calculator using dynamic memory, constructors, copy constructor, move constructor.

*Code:*
#raw(read("polycal.cpp"), lang: "cpp", block: true)

*Output:*
#block(
  fill: rgb("#f1f5f9"),
  stroke: 0.5pt + rgb("#94a3b8"),
  inset: 8pt,
  radius: 4pt,
  width: 100%,
)[
```
(+)/(*): +
3x^2 + 2x + 1
+
3x^2 + 2x
=
3x^2 + 2x + 1 + 3x^2 + 2x
```
```
(+)/(*): *
3x^2 + 2x + 1
*
3x^2 + 2x
=
9x^4 + 6x^3 + 6x^3 + 4x^2 + 3x^2 + 2x
```
]
