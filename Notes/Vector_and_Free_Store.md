# Ch 17 - Vector and Free Store

## Introduction

* A vector provides a sequence of elements of a given type
* The standard library vector is efficient in time and space as a container
* A computer's memory doesn't natively support useful types like vecotrs, strings, lists and maps
* The only thing hardware supports is sequences of bytes
* When you are running operations on the container such as the push_back() function, at the low level, the computer is only reading and writing a few bytes at a time
* The c++ standard library provides us with facilities, or algorithms, which saves us from having to program common tasks
* In order to implement our own version of a vector, we must deal with directly with memory
* Containers are designed to allows us to manipulate data without having to deal with memory at a low level
* It is important to know who to manage memory at a low level so that you can implement your own containers, be able to read c and c++ code that directly uses memory, and pointers are sometimes necessary when programming in c++
* Understanind how a program maps to memory will make it easier to grasp higher-level topics, such as data structures, algorithms, and operating systems

## Vector Basics

* All containers in c++ start counting from 0
* The number of elements in a vector is called its size
* The elements in a vector are numbered (indexed) from 0 to size - 1
* To store our values, we must create a class called vector. The class needs a data member to hold the size and another to hold the elements in the vector
* We need a way to hold the elements of the vector which can vary in size
* Without a way to hold the elements of varying size, we would have to define a data structure of fixed size

  Ex:
  ```
  class vector {
    int size, element1, element2, element3;
    // ...
  };
  ```
  * This would be a problem because we wouldn't be able to add more elements than the fixed size
* To solve this problem, we need to use a pointer so that every time we need to change the size of the elements we are storing, we can point to a different container with a larger size
* **Pointer** - A data type that can hold a memory address
* To use a pointer we must add an asterisks to the end of the data type we are pointing to. For example the following code is a pointer to a double
```
double*
```

## Memory, Addresses, and Pointers

* A computers memory is a sequence of bytes
* The bytes can be numbered from 0 to the last one
* A number that indicates the location in memory is called an address
* Everything we put in memory has an address
* We can store an manipulate addresses using pointers
* The "address of" operator (&) is used to get the address of an object
```
int var = 20;
int* ptr = &var;  // prt is assigned the memory address of var
```
* each type has a corresponding pointer type
* The "contents of" operator, aka dereference operator, (*) is used to see the value of the object that is being pointed at
* Hexadecimal notation if often used when displaying memory addresses
* The dereference operator can be used on the left hand side of an assignment to change the value of the object that is being pointed at
```
*num = 6;  // Changes the value of the object being pointed to
```
* Pointers are not integers. You can't do arithmetic on them like how you can with integers
* You can't assign other types to a pointer except for a pointer of the same type
  * You can't assign an int to a pointer variable
  * You can't assign a pointer to int type to a pointer to char type
* This protection is put in place because if you were to assign a type of bigger size to a type of smaller size, then it would overwrite data stored in the address next to the type you are writing too. This would cause many errors that would be hard to debug
* We should try to work at the highest level of abstraction possible for the problem that we are trying to solve. This will reduce that amount of errors in our code
* You can use the sizeof operator to see how much memory a datatype takes up
* sizeof reports in bytes
