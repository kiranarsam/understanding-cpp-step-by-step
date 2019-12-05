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





