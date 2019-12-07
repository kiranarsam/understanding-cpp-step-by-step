# Pointers
Pointers store address of variables or a memory location.
```
Syntax:-
datatype *var_name;
```
## Using a Pointer
* To access address of a variable to a pointer, we use the unary operator & (ampersand) that 
returns the address of that variable.
* One more operator is unary * (Asterisk)
    * To declare a pointer variable: When a pointer variable is declared, there must a * before 
    its name.
    * To access the value stored in the address we use the unary operator (*) that returns the 
    value of the variable located at the address specified by its operand.

## Pointer Expressions and Pointer Arithmetic
A limited set of arithmetic operations can be performed on pointers. A pointer may be:
* incremented ( ++ )
* decremented ( — )
* an integer may be added to a pointer ( + or += )
* an integer may be subtracted from a pointer ( – or -= )
Pointer arithmetic is meaningless unless performed on an array.

**NOTE**: Pointers contain addresses. Adding two addresses makes no sense, because there is no 
idea what it would point to. Subtracting two addresses lets you compute the offset between 
these two addresses.

## Array Name as Pointers
An array name acts like a pointer constant. The value of this pointer constant is the address 
of the first element.

## Pointers and Multidimensional Arrays
Consider pointer notation for the two-dimensional numeric arrays.
```
int nums[2][3]  =  { {16, 18, 20}, {25, 26, 27} };
```
In general, `nums[i][j]` is equivalent to `*(*(nums+i)+j)`.

# What is an Array Decay? How it can be prevented?
## What is an Array Decay?
The loss of type and dimensions of an array is known as decay of an array.This generally occurs 
when we pass the array into function by value or pointer. What it does is, it sends first 
address to the array which is a pointer, hence the size of array is not the original one, but 
the one occupied by the pointer in the memory.

Example: - [Array Decay problem](array-decay-problem.cpp)
In the above code, the actual array has 7 int elements and hence has 28 size. But by calling by 
value and pointer, array decays into pointer and prints the size of 1 pointer i.e. 8 (4 in 32 bit).

## How to prevent Array Decay?
A typical solution to handle decay is to pass size of array also as a parameter and not use 
sizeof on array parameters.
Another way to prevent array decay is to send the array into functions by reference. This 
prevents conversion of array into a pointer, hence prevents the decay.
Check the example.

# Opaque Pointer
**Opaque** as the name suggests is something we can’t see through. e.g. wood is opaque. 
Opaque pointer is a pointer which points to a data structure whose contents are not exposed at 
the time of its definition.

Following pointer is opaque. One can’t know the data contained in `STest` structure by looking 
at the definition.
```
struct STest* pSTest;
```
It is safe to assign ` NULL ` to an opaque pointer.
```
pSTest = NULL;
```
## Why Opaque pointer?
There are places where we just want to hint the compiler that “Hey! This is some data structure 
which will be used by our clients. Don’t worry, clients will provide its implementation while 
preparing compilation unit”. Such type of design is robust when we deal with shared code.

# References
When a variable is declared as reference, it becomes an alternative name for an existing 
variable. A variable can be declared as reference by putting ` & ` in the declaration.

## aplications:
1. **Modify the passed parameters in a function** : If a function receives a reference to a 
variable, it can modify the value of the variable. For example, in the following program 
variables are swapped using references.
1. **Avoiding copy of large structures** : Imagine a function that has to receive a large 
object. If we pass it without reference, a new copy of it is created which causes wastage of 
CPU time and memory. We can use references to avoid this.
1. **In For Each Loops to modify all objects** : We can use references in for each loops to 
modify all elements
1. **In For Each Loops to avoid copy of objects** : We can use references in for each loops to 
avoid copy of individual objects when objects are large.

## References vs Pointers
Both references and pointers can be used to change local variables of one function inside 
another function. Both of them can also be used to save copying of big objects when passed as 
arguments to functions or returned from functions, to get efficiency gain.

Despite above similarities, there are following differences between references and pointers.

* A pointer can be declared as void but a reference can never be void
```
int a = 10;
void* aa = &a;. //it is valid
void &ar = a; // it is not valid
```

## References are less powerful than pointers
1. Once a reference is created, it cannot be later made to reference another object; it cannot 
be reseated. This is often done with pointers.
1. References cannot be NULL. Pointers are often made NULL to indicate that they are not 
pointing to any valid thing.
1. A reference must be initialized when declared. There is no such restriction with pointers

Due to the above limitations, references in C++ cannot be used for implementing data structures 
like Linked List, Tree, etc. In Java, references don’t have above restrictions, and can be used 
to implement all data structures. References being more powerful in Java, is the main reason 
Java doesn’t need pointers.

## References are safer and easier to use:
1. **Safer**: Since references must be initialized, wild references like wild pointers are 
unlikely to exist. It is still possible to have references that don’t refer to a valid location 
1. **Easier to use**: References don’t need dereferencing operator to access the value. They 
can be used like normal variables. ‘&’ operator is needed only at the time of declaration. Also,
 members of an object reference can be accessed with dot operator (‘.’), unlike pointers where 
arrow operator (->) is needed to access members.

Together with the above reasons, there are few places like copy constructor argument where 
pointer cannot be used. Reference must be used pass the argument in copy constructor. Similarly 
references must be used for overloading some operators like ++.

# Can references refer to invalid location?
Reference variables are safer than pointers because reference variables must be initialized and 
they cannot be changed to refer to something else once they are initialized. But there are 
exceptions where we can have invalid references.

1. Reference to value at uninitialized pointer.
```
int *ptr; 
int &ref = *ptr; // Reference to value at some random memory location 
```
1. Reference to a local variable is returned.
```
int& fun() { 
   int a = 10; 
   return a; 
} 
```
Once fun() returns, the space allocated to it on stack frame will be taken back. So the 
reference to a local variable will not be valid.

# When do we pass arguments by reference or pointer
Variables are passed by reference due to following reasons:
1. **To modify local variables of the caller function**: A reference (or pointer) allows called 
function to modify a local variable of the caller function.
[Example](pass-arguments-by-reference.cpp)

1. **For passing large sized arguments**: If an argument is large, passing by reference (or 
pointer) is more efficient because only an address is really passed, not the entire object.
```
class Employee { 
private: 
	string name; 
	string desig; 
}; 

void printEmpDetails(Employee emp) { 
	cout<<emp.getName(); 
	cout<<emp.getDesig(); 
} 
```
The problem with above code is: every time printEmpDetails() is called, a new Employee object 
is constructed that involves creating a copy of all data members. So a better implementation 
would be to pass Employee as a reference.
```
void printEmpDetails(const Employee &emp) { 
	cout<<emp.getName(); 
	cout<<emp.getDesig(); 
}
```
This point is valid only for struct and class variables as we don’t get any efficiency 
advantage for basic types like int, char.. etc.

1. **To avoid Object Slicing**: If we pass an object of subclass to a function that expects an 
object of superclass then the passed object is sliced if it is pass by value.
[Example problem](object-slicing-problem-without-reference-or-pointer.cpp)

If we use pass by reference in the above example program, then object slicing will avoid.
[Example solution](object-slicing-solution-using-reference-or-pointer.cpp)
This point is also not valid for basic data types like int, char, .. etc.

1. To achieve Run Time Polymorphism in a function
We can make a function polymorphic by passing objects as reference (or pointer) to it.
[Example](achieve-runtime-polymorphism-through-reference-pointers.cpp)


# Smart Pointers
Consider the following simple C++ code with normal pointers.
```
MyClass *ptr = new MyClass(); 
ptr->doSomething(); 
// We must do delete(ptr) to avoid memory leak 
```
Using smart pointers, we can make pointers to work in way that we don’t need to explicitly call 
delete. Smart pointer is a wrapper class over a pointer with operator like * and -> overloaded. 
The objects of smart pointer class look like pointer, but can do many things that a normal 
pointer can’t like automatic destruction (yes, we don’t have to explicitly use delete), 
reference counting and more.

The idea is to make a class with a pointer, destructor and overloaded operators like * and ->. 
Since destructor is automatically called when an object goes out of scope, the dynamically 
allocated memory would automatically deleted (or reference count can be decremented).

# Can we write one smart pointer class that works for all types
Yes, we can use templates to write a generic smart pointer class.

Smart pointers are also useful in management of resources, such as file handles or network sockets.

# 'this' pointer
To understand ‘this’ pointer, it is important to know how objects look at functions and data members of a class.
1. Each object gets its own copy of the data member.
1. All-access the same function definition as present in the code segment.

Meaning each object gets its own copy of data members and all objects share a single copy of member functions.

Then now question is that if only one copy of each member function exists and is used by 
multiple objects, how are the proper data members are accessed and updated?

The compiler supplies an implicit pointer along with the names of the functions as **this**.

The **this** pointer is passed as a hidden argument to all nonstatic member function calls and 
is available as a local variable within the body of all nonstatic functions. **this** pointer 
is not available in static member functions as static member functions can be called without 
any object (with class name).

In the early version of C++ would let **this** pointer to be changed; by doing so a programmer 
could change which object a method was working on. This feature was eventually removed, and now 
this in C++ is an r-value.
C++ lets object destroy themselves by calling the following code :
```
delete this;
```
As Stroustrup said **this** could be the reference than the pointer, but the reference was not 
present in the early version of C++. If **this** is implemented as a reference then, the above 
problem could be avoided and it could be safer than the pointer.

## this pointer is used in following situations
1. When local variable’s name is same as member’s name
```
    void setX (int x) { 
        // The 'this' pointer is used to retrieve the object's x 
        // hidden by the local variable 'x' 
        this->x = x; 
    } 
```
1. To return reference to the calling object
```
    /* Reference to the calling object can be returned */
    Test& Test::func () { 
        // Some processing 
        return *this; 
    } 
```
When a reference to a local object is returned, the returned reference can be used to chain 
function calls on a single object.

# Type of this pointer
**this** pointer is passed as a hidden argument to all non-static member function calls. The 
type of _this_ depends upon function declaration. If the member function of a _class X_ is 
declared _const_, the type of _this_ is _const X*_, if the member function is declared 
_volatile_, the type of _this_ is _volatile X*_, and if the member function is declared _const_
 _volatile_, the type of _this_ is _const volatile X*_.

```
class X {
    void fun() const {
        // this is passed as hidden argument to fun().
        // Type of this is const X* const
    }
    void fun2() volatile {
        // Type of this is volatile X* const
    }
    void fun3() const volatile {
        // Type of this is const volatile X* const
    }
};
```

# delete this;
Ideally _delete_ operator should not be used for _this_ pointer. However, if used, then following points must be considered.
1. _delete_ operator works only for objects allocated using operator _new_. If the object is 
created using new, then we can do delete this, otherwise behavior is undefined.
1. Once _delete this_ is done, any member of the deleted object should not be accessed after deletion.
**NOTE**: The best thing is to not do delete this at all.

# auto_ptr, unique_ptr, shared_ptr, and weak_ptr
C++ libraries provide implmentations of smart pointersin following types
* auto_ptr
* unique_ptr
* shared_ptr
* weak_ptr
They all are declared in a **memory** header file.



