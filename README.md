# Custum-Vector-Operating-Class

This project is a C++ program that allows you to perform multiple operations on vectors through a menu-driven interface.

How It Works
* At the beginning, the program asks you for the size of Vector 1 and lets you enter the elements.

* A menu is displayed after that with 21 different operations you can perform on two vectors.

* You can continue performing operations until you choose to Exit.

Available Operations
* Display elements

* Add or remove elements

* Access or remove elements at a specific index

* Insert elements at a given position

* Swap two vectors

* Sort a vector

* Move elements inside a vector

* Perform Union or Intersection of vectors

* Keep only unique elements

* Count frequency of an element

* Check if one vector is a subset of another

* Search for an element

* Add or subtract vectors

* Compare vectors (==, >, <)

How to Compile and Run

g++ main.cpp -o VectorApp
./VectorApp

Make sure vector.h is in the same directory as main.cpp.

Files
  * main.cpp — Main program that controls the flow.

  * vector.h — Vector class template with operator overloading and various methods.

Extra Notes
 * The program uses templates so it can work with different data types (like int, float, etc.).

 * Exceptions are handled for invalid operations (like out-of-bound access).

 * Overloaded operators are used for input/output and operations between vectors.

🚀 Quick Start Example
mathematica
Copy
Edit
Enter size for Vector 1: 4
Enter elements for Vector 1: 5 2 8 1

Menu:
1. Display elements
2. Add an element
...
21. Exit
Enter your choice: 1
