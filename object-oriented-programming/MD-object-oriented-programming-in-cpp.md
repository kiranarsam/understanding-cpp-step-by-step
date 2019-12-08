# Object Oriented Programming
## **TABLE OF CONTENT**
    1. Introduction
    2. Class
    3. Objects
    4. Encapsulation
    5. Abstraction
    6. Polymorphism
    7. Inheritance
    8. Dynamic Binding
    9. Message Passing

### Introduction
Object-oriented programming - aims to implement real-world entities like inheritance,
hiding, polymorphism, etc in programmming.
The main aim of OOP is to bind together the data and the functions that operate on them
so that no other part of the code can access this data except that function.

### Class
It is user defined data type, which holds its own data members and member functions, which
can be accessed and used by creating an instance of that class.
A class is like a blueprint for an object.

* A Class is a user-defined data-type which has data members and member functions.
* Data members are the data variables and member functions are the functions used to maipulate 
these variables and together these data members and member functions define the properties 
and behaviour of the objects in a Class.

**Class in C++** is a blue-print representing a group of objects which shares some common 
properties and behaviours.

### Object
An Object is an identifiable enitity with some characteristics and behaviour. An Object is 
an instance of a Class. When a class is defined, no memory is allocated but when it is 
instantiated (i.e. an object is created) memory is allocated.

Object take up space in memory and have an assoicated address.

When a program is executed the objects interact by sending messages to one another.

Each object contains data and code to manipulate the data. Objects can interact without 
having to know the details of each other's data or code, it is sufficient to know the type of 
message accepted and type of response returned by the objects.

### Encapsulation
It is defined as wrapping up of data and information under a single unit. In OOP, Encapsulation 
is defined as binding together the data and the functions that manipulate them.

Encapsulation also leads to **_data abstraction or hiding_**. As using encapsulation also hides 
the data.

### Abstraction
Abstraction means displaying only essential information and hiding the details.
Data abstraction refers to providing only essential information about the data to the outside 
world, hiding the background details or information.

* _Abstraction using Classes:_ The class helps us to group data members and member functions 
using available access specifiers. A Class can decide which data member will be visible to the 
outside world and which is not.
* _Abstraction in Header files:_ One more type of abstraction in C++ can be header files.

### Polymorphism
It means having many forms. In simple words, we can define polymorphism as the ability of a 
message to be displayed in more than one form.

An operation may exhibit different behaviours in different instances. The behaviour depends 
upon the types of data used in the operation.

C++ supports operator and function overloading.
* _Operator Overloading:_ The process of making an operator to exhibit different behaviours 
in different instances is known as operator overloading.
* _Function Overloading:_ Function overloading is using a single function name to perform 
different types of tasks.

Polymorphism is extensively used in implementing inheritance.

#### Types of Polymorphism
* Compile Time
    * Function Overloading
    * Operator Overloading
* Run Time
    * Virtual Functions

### Inheritance
The capability of a class to derive properties and characteristics from another class is 
called inheritance.

* **Sub Class:** The class that inherits properties from another class is called 
Sub class or Derived Class.
* **Super Class:** The class whose properties are inherited by sub class is called 
Base Class or Super Class.
* **Reusability:** Inheritance supports the concept of "reusability", i.e. when we want 
to create a new class and there is already a class that includes some of the code that we want,
we can derive our new class from the existing class. By doing this, we are reusing the fields 
and methods of the existing class.

#### Types of Inheritance
* Single Inheritance
    - Child Class X --> Parent Class A
* Multiple Inheritance
    - Child Class X --> Parent Class A, Parent Class B
* Multilevel Inheritance
    - Child Class Y --> Child Class X --> Parent Class A
* Hierarchical Inheritance
    - Child Class X --> Parent Class A
    - Child Class Y --> Parent Class A
    - Child Class Z --> Parent Class A
* Hybrid Inheritance
    - Derived Class B --> Parent Class A
    - Derived Class C --> Parent Class A
    - Derived Class D --> Derived Class B, Derived Class C

### Dynamic Binding
In dynamic binding, the code to be executed in response to function call is decided at runtime.
C++ has virtual functions to support this.

### Message Passing
Objects communicate with one another by sending and receiving information to each other. 
A message for an object is an object is a request for execution of a procedure and therfore 
will invoke a function in the receiving object that generates the desired results. 
Message passing involves specifying the name of the object, the name of the function and 
the information to be sent.



