# Virtual Functions and Runtime Polymorphism
Having the derived class’s function is called using a base class pointer.

The idea is that virtual functions are called according to the type of the object instance 
pointed to or referenced, not according to the type of the pointer or reference.

In other words, **virtual functions are resolved late, at runtime**.

## What is the use virtual functions
Virtual functions allow us to create a list of base class pointers and call methods of any of the derived classes without even knowing kind of derived class object. 

## How does the compiler perform runtime resolution
The compiler maintains two things to serve this purpose:
1. **vtable**: A table of function pointers, maintained per class.
1. **vptr**: A pointer to vtable, maintained per object instance.

![Virtual Function](VirtualFunction.png)

Compiler adds additional code at two places to maintain and use vptr.
1. Code in every constructor. This code sets the **_vptr_** of the object being created. This 
code sets **_vptr_** to point to the **_vtable_** of the class.
1. Code with polymorphic function call (e.g.`bp->show()`). Wherever a polymorphic call is made, 
the compiler inserts code to first look for **_vptr_** using base class pointer or reference. 
Once **_vptr_** is fetched, **_vtable_** of derived class can be accessed. Using **_vtable_**, 
address of derived derived class function `show()` is accessed and called. 

## Is this a standard way for implementation of run-time polymorphism
The C++ standards do not mandate exactly how runtime polymorphism must be implemented, but 
compilers generally use minor variations on the same basic model.

# Default arguments and virtual function
Default arguments do not participate in signature of functions. So signatures in base class and 
derived class are considered same, hence base class is overridden. Also, the default value is 
used at compile time. When compiler sees that an argument is missing in a function call, it 
substitutes the default value given.

In general, it is a best practice to avoid default values in virtual functions to avoid confusion.

## Virtual functions in derived classes
Once a member function is declared as a virtual function in a base class, it becomes virtual in 
every class derived from that base class. In other words, it is not necessary to use the 
keyword virtual in the derived class while declaring redefined versions of the virtual base 
class function.

## Can static functions be virtual
A static member function of a class **cannot be virtual**. Gives compilation error.

Also, static member function **cannot be const and volatile**. Fails in compilation.

# Virtual Destructor
Deleting a derived class object using a pointer to a base class that has a **non-virtual** 
**destructor** results in undefined behavior. To correct this situation, **the base class** 
**should be defined with a virtual destructor**.

Making base class destructor virtual guarantees that the object of derived class is destructed 
properly, i.e., both base class and derived class destructors are called.

As a guideline, any time you have a virtual function in a class, you should immediately add a 
virtual destructor (even if it does nothing).

# Virtual Constructor and Virtual Copy Constructor
Please refer to [Virtual Constructor and Virtual Copy Constructor](/constructor-destructor/MD-consructor-destructor.md).

# RTTI (Run-Time Type Information)
RTTI (Run-time type information) is a mechanism that exposes information about an object’s data 
type at runtime and is available only for the classes which have at least one virtual function. 
It allows the type of an object to be determined during program execution.

For example, **dynamic_cast** uses RTTI and following program fails with error:
"cannot dynamic_cast 'b' (of type 'class Base*') to type 'class Derived*' (source type is not 
polymorphic)” **because** there is no virtual function in the base class Base.
Example: [Program fails over dynamic_cast which uses RTTI](/constructor-destructor/RTTI-fails-dynamic-cast.cpp).

Adding a virtual function to the base class B makes it working.
Example: [Program works over dynamic_cast which uses RTTI](/constructor-destructor/RTTI-works-over-dynamic-cast.cpp)


## Can virtual functions be private
Virtual functions can be private and can be overridden by the derived class.
Note: Check the example problem which works fine with friend function 
1. `ptr` is a pointer of `Base` type and points to a `Derived` class object. When `ptr->fun()` 
is called, `fun()` of `Derived` is executed.
2. `int main()` is a friend of `Base`.  If we remove this friendship, the program won’t 
compile. We get compiler error.

## Can virtual functions be inlined
**Virtual functions** are used to achieve runtime polymorphism or say late binding or dynamic 
binding. Inline functions are used for efficiency. The whole idea behind the inline functions 
is that whenever inline function is called code of inline function gets inserted or substituted 
at the point of inline function call at compile time. Inline functions are very useful when 
small functions are frequently used and called in a program many times.

By default all the functions defined inside the class are implicitly or automatically 
considered as inline **except virtual functions** (**NOTE** that inline is a request to the 
compiler and its compilers choice to do inlining or not).

_Whenever virtual function is called using base class reference or pointer it cannot be inlined (because call is resolved at runtime), but whenever called using the object (without reference or pointer) of that class, can be inlined because compiler knows the exact class of the object at compile time_.











