# Ch 17 - Vector and Free Store

## Introduction

* A vector provides a sequence of elements of a given type
* The standard library vector is efficient in time and space as a container
* A computer's memory doesn't natively support useful types like vecotrs, strings, lists and maps
* The only thing hardware supports is sequences of bytes
* When you are running operations on the container such as the push_back() function, at the low level, the computer is only reading and writing a few bytes at a time
* The c++ standard library provides us with facilities, or algorithms, which saves us from having to program common tasks
* In order to implement our own version of a vector, we must deal directly with memory
* Containers are designed to allows us to manipulate data without having to deal with memory at a low level
* It is important to know how to manage memory at a low level so that you can implement your own containers, be able to read c and c++ code that directly uses memory, and pointers are sometimes necessary when programming in c++
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
* To use a pointer we must add an asterisk to the end of the data type we are pointing to. For example the following code is a pointer to a double
```
double*
```

## Memory, Addresses, and Pointers

* A computers memory is a sequence of bytes
* The bytes can be numbered from 0 to the last one
* A number that indicates the location in memory is called an address
* Everything we put in memory has an address
* We can store and manipulate addresses using pointers
* The "address of" operator (&) is used to get the address of an object
```
int var = 20;
int* ptr = &var;  // prt is assigned the memory address of var
```
* each type has a corresponding pointer type
* The "contents of" operator, aka dereference operator, (*) is used to see the value of the object that is being pointed at
* Hexadecimal notation is often used when displaying memory addresses
* The dereference operator can be used on the left hand side of an assignment to change the value of the object that is being pointed at
```
*num = 6;  // Changes the value of the object being pointed to
```
* Pointers are not integers. You can't do arithmetic on them like how you can with integers
* You can't assign other types to a pointer except for a pointer of the same type
  * You can't assign an int to a pointer variable
  * You can't assign a **pointer-to-int** type to a **pointer-to-char** type
* This protection is put in place because if you were to assign a type of bigger size to a type of smaller size, then it would overwrite data stored in the address next to the type you are writing too. This would cause many errors that would be hard to debug
* We should try to work at the highest level of abstraction possible for the problem that we are trying to solve. This will reduce that amount of errors in our code
* You can use the sizeof operator to see how much memory a data type takes up
* **sizeof** reports in bytes

## Free Store and Pointers

* When you start a c++ program, the compiler sets aside memory for your code (Code Storage)
* It also sets aside memory for the global variables (Static Storage)
* It also sets aside memory for your functions and their variables (Stack Storage)
* The rest of the  memory is free for any program to use
* This free store is also called heap
* You can access the free store with the **new** keyword
* The **new** operator returns a pointer to the object it creates
* If the **new** operator creates several objects, the pointer will point to the first object in memory
* The pointer does not know how many objects it is pointing to
* You can use a variable to set the size of an array that the **new** operator creates
  ```
  double* qd = new double[n];  // allocate n doubles (array of n doubles)
  ```
* Pointers can only be assigned to their same type in order to prevent type errors

### Access through pointers

* You can also use the subscript operator (**[ ]**) to dereference a pointer\
  For example:
  ```
  int* nums = int[5];  // Pointer to an array of 5 ints
  int p = *nums;  // Assigns the value of the first int in the nums array to p
  int q = nums[3] // Assigns the value of the 4th int in the nums array to q
  nums[4] = 22;  // Assigns 22 to the 5th int in the nums array
  ```
* the **[ ]** operator treats memory as a sequence of objects of the same type

### Ranges

* A pointer doesn't know how many elements it points to
* If you try to access an object with the subscript notation at an index that it doesn't have, there will be no error. You will simply get whatever is that many bytes away from the pointer
* Out-of-range access is bad because it allows us to read and write to parts of memory that we are not meant to access
* Errors caused by out-of-range-access can be hard to debug because they can affect areas unrelated to the code and it can cause different errors every time we run the program
* One of the reasons we should use a vector rather than directly accessing memory is that a vector knows its size, so we can avoid out-of-range access
* Assigning a **pointer-to-a-type** to different **pointer-to-a-type** can lead to out-of-range access if one pointer is of different size than the other pointer
* Understanding pointers is essential for understanding real-world code

### Initialization

* We want to make sure that the objects that our pointers point to have been initialized, otherwise we could try to access them when they don't exist
  ```
  double* p0; // uninitialized, the object at this location could be anything
  ```
* Memory allocated by **new** is not initialized
* We can initialize these objects with the **{ }** notation
  ```
  double* p1 = new double[3]{0,1,2};
  double* p2 = new double[]{3,4,5,6,7,8};
  ```
  * You can ommit the array length in the **[ ]** when you initialize the object with the **{ }**
* We don't have to worry about initializing with user-defined types that have default constructors
* Compilers often have a debug mode where all uninitialized objects are set to 0. This can be a problem because the program may not cause an error when running in debug mode, but will once it is compiled for production

### The Null Pointer

* When we don't have a pointer to intilialize a pointer with, we should set it equal to ```nullptr```
* This allows us to check if a pointer is valid with an if statement
```cpp
int* ptr0 = nullptr;
if (ptr0) {  // equivalent to ptr0 != nullptr
  // do something
}
```
* Once we delete the object in a pointer, we should set the pointer equal to ```nullptr``` so that it has no memory address. Otherwise, when we run the if statement it will pass since it will have a memory address to something random
* The ```nullptr``` keyword is new in C++11, so older code might use 0 or ```NULL``` instead
* Prefer to use ```nullptr``` since it is more specific

## Free-store deallocation

* Since memory is limited, we should return memory that we take from free-store once we are done using it
  * This is essential for long-running programs
```cpp
double* calc(int res_size, int max) {
  double* p = new double[max];
  double* res = new double[res_size];
  // we should've deleted p here since it won't be used anymore
  return res;
}

double* r = calc(100,1000);
// use r somewhere
// we should have deleted r here since it won't be used anymore
```
* In the program above, every call to ```calc()``` leaks memory since we never delete the pointers we use
* The call ```calc(100,1000)``` will take up ```8 bytes per double * 1000 doubles = 8000 bytes```
* The ```delete``` operator is used to return memory to the free store
* We use ```delete``` on pointers returned by the ```new``` keyword to make that memory available in the free store again
* **delete p** frees the memory of an individual object
* **delete[] p** frees the memory of an array
* The programmer has to decide which version of delete is the appropriate one for each case
* You will recieve an error if you try to delete a pointer more than once. There are two problems with trying to delete a pointer more than once:
  * The pointer may belong to the free-store manager, so you don't have access to that location anymore and you will recieve an error
  * The free-store manager could have assigned that address to a different pointer in the program and you will be deleting something unrelated to what you think you are deleting
* Deleting a ```nullptr``` doesn't do anything, it is harmless
* It is possible for compilers to free memory for you when you no longer need it. This is called *automatic garbage collection*
* Automatic Garbage Collection comes with a performance cost, so it is sometimes better to manage memory manually
* It is most important to not leak memory in programs that will run forever
  * The memory leaked will never be freed
  * This includes operating systems and embedded system
  * Libraries should also not leak since they could be used by others that can't afford to leak memory in their programs
* Even when you know that a memory leak will not cause huge problems, it is still better to deal with them so as to not appear sloppy

## Destructors

* A destructor is the opposite of a constructor
* It runs when an object goes out of scope
* The purpose of a destructor is to make sure that an object is properly cleaned up before it is destroyed
* If we didn't have destructors, for each object that used the free store, we would have to create member functions who would delete all the pointers in use and we would have to rely on the user of the object to run the member function when they were done using it
* Here is an example of a destructor that we would use in our vector class:
```cpp
class vector {
  // other code

  ~vector() {
    delete[] elem;
  }
}
```

* The reason to use vectors over arrays is that a vector's destructor runs automatically when it goes out of scope, while for an array, the user has to use the ```delete[]``` operator
* Having to use the ```delete[]``` operator opens the door to problems since the programmer can forget to include it
* Destructors are great for handling resources that have to be aquired and then returned
  * This includes files, threads, locks
  * This is how iostreams clean up after themselves
* If a member of an object has a destructor, that destructor will be called when the object is destroyed
* The basic idea of constructors and destructors is this:
  * A class object acquires the resources it needs to function in the constructor
  * During its lifetime, the object can aquire new resources and delete ones it doesn't need anymore
  * At the end of its lifetime, the destructor deletes all the remaining resources that the object still has
* When you have a class with a virtual function, it usually needs a virtual destructor
* Destructors are called with the ```delete``` operator instead of being called directly

## Pointers to class objects

* We can create pointer to anything that can have a memory address, including objects
* When we create a pointer to our vector object, the ```new``` operator does the following:
  1. Allocates memory for a vector
  2. Invokes the vector's constructor, which then allocates memory for its elements and initializes them
* The ```delete``` operator does the following when we call it on our vector class
  1. Invokes the vector's destructor. The vector destructor invokes the destructor for the elements. Finally, it deallocates the memory used by the elements
  2. Once it is done deallocating the memory for the elements, it deallocates the memory used for the vector
* Because ```delete``` invokes destructors, it is often used to destroy objects rather than just deallocate them
* Try to keep ```new```s in constructors and ```delete```s in destructors to avoid forgetting to deallocate objects
* To access the members of our vector given only a pointer, we use the arrow (->) operator
```cpp
vector* p = new vector(4);
int x = p->size();
double d = p->get(3);
```
* The arrow operator can be used for both accessing data members and function members
* Arrow doesn't apply to built-in types since they don't have members
* Dot (.) and arrow (->) are often called **member access operators**

## Messing with types: void* and casts
* We are working very close to hardware when using pointers and free-store-allocated arrays
* Sometimes we have to use pointers that don't offer type safety
  * This should be avoided whenever possible, but may be necessary in certain cases like when working with other languages that don't understand C++'s types
* To be able to work with pointers without type safety, we need two things
  * A type of pointer that points to memory without knowing what type of memory is at that address
  * An operation to tell the compiler what kind of type to assume for those pointers
* The ```void*``` type means "pointer to some memory that the compiler doesn't know the type of"
* We use the ```void*``` type when we want to transmit an address between pieces of code that don't know each others types
* There are no objects of type ```void```, but we use it to indicate that a function will not return anything
* A pointer of any type can be assigned to a ```void*```
* We have to tell the compiler what a ```void*``` points to since it doesn't know
* A ```static_cast``` can be used to explicitly convert between related pointer types
  * Use it only when necessary
* The ```static_cast``` is an *explicit type conversion*, or *cast*
* Whenever you use a cast, see if there is a better way without using one
* There is usually a way to rewrite code without a cast unless you are interfacing to other people's code or to hardware

## Pointers and references

* A reference can be thought of as an automatically dereferenced immutable pointer
* Pointers and references differ in these ways:
  * An assignment to a pointer changes the pointer's value, while assignment to a reference changes the value of the object referred to
  * To get a pointer you need ```new``` or ```&```
  * To access an object pointed to by a pointer you need ```*``` and ```&```
  * You cannot change the object that a reference refers to once it has been initialized
  * Assignment of references assign to the referred-to object, while assignment to pointers assigns to the pointer object itself
* To assign an object as a reference, you use the ```&``` operator on the type instead of in the initializer like with a pointer
```cpp
int y = 10;
int& r = y;  // r is a reference to y
r = 7;  // y and r are now equal to 7 since they point to the same thing
```
* If you need to change the what is being pointed to, you should use a pointer rather than a reference
* Pointers and references both use memory addresses, but they use them in different ways to allow you to do different things
