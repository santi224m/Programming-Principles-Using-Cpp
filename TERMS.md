## This is a collection of all the terms I have learned in the book so far.

### Chapter 2 - Hello, World!
* // - This is the start of a comment in c++
* C++ - A programming language
* compiler - Turns source code into machine code
* compile-time error - An error that occurs while you are compiling code
* cout - Prints something to the console. It is included in the standard library
* executable - A computer program that can be run. It is the result of compiling source code.
* function - Made up of 4 parts: return value, name, parameters, and the body
* header - Allows you to bring in code from another file
* IDE - Intergrated Development Environment. Includes many resources that help you program, including a text editor, compiler, and linker
* #include - allows you to link other files in c++.
* library - a file that contains code which can be used in other programs
* linker - links all the files used into one file
* main() - A function that must be used in all c++ programs. This function is used to start the program.
* object code - The result of running source code through a compiler
* output - Something that comes out of the program
* program - A list of instructions that allow you to do something
* source code - Code written by a programmer that will be compiled to make the program
* statement - a line of code

### Chapter 3 - Objects, Types, and Values
* assignment - Gives a variable a new value
* cin - Included in the standard  library. Allows you to access the input stream.
* concatenation - Joining 2 or more strings together
* conversion - Converting from one type of literal to another
* declaration - A statement that gives a name and data type to an object. Let's the compiler know that the object exists.
* decrement - Decreasing the value of a number by 1 or more
* definition - Sets a value to an object that has been declared. Objects can be defined at the same time that they are declared.
* increment - Increasing a number by 1 or more
* initialization - Assigning an initial value to an object. This only happens once in the code for each object.
* name - The name of a variable
* narrowing - Converting from a type literal to a smaller type literal and losing some piece of information because of it
* object - A region in memory with a type that specifies what kind of value can be stored in it
* operation - Using an operator to get a value from some other values
* operator - Used to operate on other values (Ex: +,-,*,/,%)
* type - Specifies what kind of values can be stored in a variable
* type safety - It can be safe or unsafe to convert from one type to another depending on how much space that types can hold
* value - What is contained in a variable
* variable - Used to hold a value of different types

### Chapter 4 - Computation
* abstraction - Used to hide the low level details of an implementation. Users don't need to understand the implementation to use something
* computation - To take an input and produce an output using a well defined model.
* conditional statement - A statement that is used to handle decisions. Allows the program to perform different tasks based on the truth value of a statement.
* divide and conquer - Taking a problem and splitting it into smaller, easier to solve problems. The solutions to the sub-problems are then used to solve the original problem.
* else - Used in a condition statement. The "else" statement runs when the preceding conditional statements fail.
* expression - A combination of numbers and symbols that can be evaluated
* for-statement - A control flow statement that allows you to execute a piece of code repeatedly.
* range-for-statement - Similiar to a "for" statement, but it allows you to iterate over an object that is passed in as an argument
* function - 
* if-statement - 
* increment - 
* input - 
* iteration - 
* loop - 
* lvalue - 
* member function - 
* output - 
* push_back() - 
* repetition - 
* rvalue - 
* selection - 
* size() - 
* sort() - 
* statement - 
* switch-statement - 
* vector - 
* while-statement - 

### Chapter 5 - Errors
* argument error - 
* assertion - 
* catch - 
* compile-time error - 
* container - 
* debugging - 
* error - 
* exception - 
* invariant - 
* link-time error - 
* logic error - 
* post-condition - 
* pre-condition - 
* range error - 
* requirement - 
* run-time error - 
* syntax error - 
* testing - 
* throw - 
* type error - 

### Chapter 6 - Writing a Program
* analysis -
* class -
* class member -
* data member -
* design -
* divide by zero -
* grammar -
* implementation -
* interface -
* member function -
* parser -
* private -
* prototype -
* pseudo code -
* public -
* syntax analyzer -
* token -
* use case -

### Chapter 7 - Completing a Program
* code layout - 
* commenting - 
* error handling - 
* feature creep - 
* maintenance - 
* recovery - 
* revision history - 
* scaffolding - 
* symbolic constant - 
* testing -

### Chapter 8 - Technicalities: Functions, etc.
* activation record -
* argument -
* argument passing -
* call stack -
* class scope -
* const -
* constexpr -
* declaration -
* definition -
* extern -
* forward declaration -
* function -
* function definition -
* global scope -
* header file -
* initializer -
* local scope -
* namespace -
* namespace scope -
* nested block -
* parameter -
* pass-by-const-reference -
* pass-by-reference -
* pass-by-value -
* recursion -
* return -
* return value -
* scope -
* statement scope -
* technicalities -
* undeclared identifier -
* using declaration -
* using directive -

### Chapter 9 - Technicalities: Classes, etc.
* built-in types -
* class -
* const -
* constructor -
* destructor -
* enum -
* enumeration -
* enumerator -
* helper function -
* implementation -
* in-class initializer -
* inlining -
* interface -
* invariant -
* representation -
* struct -
* structure -
* user-defined types -
* valid state -

### Chapter 10 - Input and Output Streams
* bad() - Checks if stream is in a bad state, which means it can't recover
* buffer - Used to temporarily store data while it is being transferred to another place
* clear() - sets the stream state back to good()
* close() - closes an input or output stream
* device driver - Allows programs to connect to different input and output sources
* eof() - Indicates end of file.
* fail() - Something unexpected happened in the stream
* good() - Operation succeeded
* ifstream - an input file stream
* input device - used to input data into the program
* input operator - ">>"
* iostream - In the Standard Library, used to handle input and output 
* istream - input stream
* ofstream - output file stream
* open() - used to open a stream
* ostream - output stream
* ouput device - used to display output from the program
* ouput operator - "<<"
* stream state - the stream can be in four states: good(), eof(), fail(), bad()
* structured file - a file that is structured in a certain way so that its data can be easily read by a program
* terminator - a character used to signal the program to stop
* unget() - returns the last character to the input stream