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






