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

## auto_ptr
This class template is deprecated. **unique_ptr** is a new facility with a similar functionality
but with improved security.

**auto_ptr** is a smart pointer that manages an object obtained via new expression and deletes 
that object when **auto_ptr** itself is destroyed.

An object when described using **auto_ptr** class it stores a pointer to a single allocated 
object which ensures that when it goes out of scope, the object it points to must get 
automatically destroyed. It is based on **exclusive ownership model** i.e. two pointers of the 
same type can’t point to the same resource at the same time. As shown in the below program, 
copying or assigning of pointers changes the ownership i.e. source pointer has to give 
ownership to the destination pointer.

The copy constructor and the assignment operator of auto_ptr do not actually copy the stored 
pointer instead they transfer it, leaving the first auto_ptr object empty. This was one way to 
implement strict ownership so that only one auto_ptr object can own the pointer at any given 
time i.e. auto_ptr should not be used where copy semantics are needed.

## Why is auto_ptr deprecated?
It takes ownership of the pointer in a way that no two pointers should contain the same object. 
Assignment transfers ownership and resets the rvalue auto pointer to a null pointer. Thus, they 
can’t be used within STL containers due to the aforementioned inability to be copied.

## unique_ptr
std::unique_ptr was developed in C++11 as a replacement for std::auto_ptr.

unique_ptr is a new facility with similar functionality, but with improved security (no fake 
copy assignments), added features (deleters) and support for arrays. It is a container for raw 
pointers. It explicitly prevents copying of its contained pointer as would happen with normal 
assignment i.e. it allows exactly one owner of the underlying pointer.

So, when using unique_ptr there can only be at most one unique_ptr at any one resource and when 
that unique_ptr is destroyed, the resource is automatically claimed. Also, since there can only 
be one unique_ptr to any resource, so any attempt to make a copy of unique_ptr will cause a 
compile-time error.
```
    unique_ptr<A> ptr1 (new A);
    unique_ptr<A> ptr2 = ptr1; // Error: can't copy unique_ptr
```
But, unique_ptr can be moved using the new move semantics i.e. using `std::move()` function to 
transfer ownership of the contained pointer to another unique_ptr.
```
unique_ptr<A> ptr2 = move(ptr1); // Works, resource now stored in ptr2
```
So, it’s best to use unique_ptr when we want a single pointer to an object that will be 
reclaimed when that single pointer is destroyed.

The below code returns a resource and if we don’t explicitly capture the return value, the 
resource will be cleaned up. If we do, then we have exclusive ownership of that resource. In 
this way, we can think of unique_ptr as safer and better replacement of auto_ptr.
```
unique_ptr<A> fun() {
    unique_ptr<A> ptr(new A);
    // .. some stuff
    return ptr;
}
```
### When to use unique_ptr?
Use unique_ptr when you want to have single ownership(Exclusive) of the resource. Only one 
unique_ptr can point to one resource. Since there can be one unique_ptr for single resource its 
not possible to copy one unique_ptr to another.

## shared_ptr
A shared_ptr is a container for raw pointers. It is a **reference counting ownership model** 
i.e. it maintains the reference count of its contained pointer in cooperation with all copies 
of the shared_ptr. So, the counter is incremented each time a new pointer points to the 
resource and decremented when the destructor of the object is called.

**Reference Counting**: It is a technique of storing the number of references, pointers or 
handles to a resource such as an object, block of memory, disk space or other resources.

An object referenced by the contained raw pointer will not be destroyed until reference count 
is greater than zero i.e. until all copies of shared_ptr have been deleted.

So, we should use shared_ptr when we want to assign one raw pointer to multiple owners.

### When to use shared_ptr?
Use shared_ptr if you want to share ownership of a resource. Many shared_ptr can point to a 
single resource. shared_ptr maintains reference count for this propose. when all shared_ptr’s 
pointing to resource goes out of scope the resource is destroyed.

## weak_ptr
A weak_ptr is created as a copy of shared_ptr. It provides access to an object that is owned by one or more shared_ptr instances but does not participate in reference counting. The existence or destruction of weak_ptr has no effect on the shared_ptr or its other copies. It is required in some cases to break circular references between shared_ptr instances.

**Cyclic Dependency (Problems with shared_ptr)**: Let’s consider a scenario where we have two 
classes A and B, both have pointers to other classes. So, it’s always like A is pointing to B 
and B is pointing to A. Hence, use_count will never reach zero and they never get deleted.

This is the reason we use **weak pointers(weak_ptr)** as they are not reference counted. So, 
the class in which weak_ptr is declared doesn’t have a stronghold of it i.e. the ownership 
isn’t shared, but they can have access to these objects.

So, in case of shared_ptr because of cyclic dependency use_count never reaches zero which is 
prevented using weak_ptr, which removes this problem by declaring A_ptr as weak_ptr, thus class 
A does not own it, only have access to it and we also need to check the validity of object as 
it may go out of scope. In general, it is a design issue.

### When to use weak_ptr?
When you do want to refer to your object from multiple places – for those references for which 
it’s ok to ignore and deallocate (so they’ll just note the object is gone when you try to 
dereference).

# Dangling, Void , Null and Wild Pointers
## Dangling pointer
A pointer pointing to a memory location that has been deleted (or freed) is called dangling 
pointer. There are three different ways where Pointer acts as dangling pointer
1. De-allocation of memory
1. Function call
1. Variable goes out of scope

## Void pointer
Void pointer is a specific pointer type – `void *` – a pointer that points to some data 
location in storage, which doesn’t have any specific type. Void refers to the type. Basically 
the type of data that it points to is can be any. If we assign address of char data type to 
void pointer it will become char Pointer, if int data type then int pointer and so on. Any 
pointer type is convertible to a void pointer hence it can point to any value.

### Important Points
1. void pointers cannot be dereferenced. It can however be done using typecasting the void pointer
1. Pointer arithmetic is not possible on pointers of void due to lack of concrete value and thus size.

## NULL Pointer
NULL Pointer is a pointer which is pointing to nothing. In case, if we don’t have address to be 
assigned to a pointer, then we can simply use NULL.

### Important Points
1. **NULL vs Uninitialized pointer** – An uninitialized pointer stores an undefined value. A 
null pointer stores a defined value, but one that is defined by the environment to not be a 
valid address for any member or object.
1. **NULL vs Void Pointer** – Null pointer is a value, while void pointer is a type

## Wild pointer
A pointer which has not been initialized to anything (not even NULL) is known as wild pointer. 
The pointer may be initialized to a non-NULL garbage value that may not be a valid address.

# Passing by pointer Vs Passing by Reference
We can pass parameters to a function either by pointers or by reference. In both the cases, we 
get the same result.

## Difference in Reference variable and pointer variable
References are generally implemented using pointers. A reference is same object, just with a 
different name and reference must refer to an object. Since references can’t be NULL, they are 
safer to use.

1. A pointer can be re-assigned while reference cannot, and must be assigned at initialization only.
1. Pointer can be assigned NULL directly, whereas reference cannot.
1. Pointers can iterate over an array, we can use ++ to go to the next item that a pointer is pointing to.
1. A pointer is a variable that holds a memory address. A reference has the same memory address as the item it references.
1. A pointer to a class/struct uses ‘->'(arrow operator) to access it’s members whereas a reference uses a ‘.'(dot operator)
1. A pointer needs to be dereferenced with * to access the memory location it points to, whereas a reference can be used directly.

### Usage in parameter passing:
References are usually preferred over pointers whenever we don’t need “reseating”.

Overall, Use references when you can, and pointers when you have to.

# NaN – What is it and how to check for it?
## What is NaN ?
NaN, acronym for **Not a Number** is an exception which usually occurs in the cases when an 
expression results in a number that can’t be represented.
For example square root of negative numbers.

## How to check for NaN ?
1. Using compare (“==”) operator.
In this method we check if a number is complex by comparing it with itself. If the result is 
true, then the number is not complex i.e., real. But if result is false, then “nan” is returned,
 i.e the number is complex.
1. Using inbuilt function `isnan()`.
Another way to check for NaN is by using “isnan()” function, this function returns true if a 
number is complex else it returns false.

# Understanding nullptr
Need of nullptr
```
int fun(int N) { cout << "fun(int)"; }  // function with integer argument 
int fun(char* s) { cout << "fun(char *)"; }  // Overloaded function with char pointer argument 
int main() { 
	fun(NULL); // Ideally, it should have called fun(char *), but it causes compiler error. 
} 
```
## What is the problem with above program?
NULL is typically defined as (void *)0 and conversion of NULL to integral types is allowed. So 
the function call fun(NULL) becomes ambiguous.
```
    int x = NULL; // This program compiles (may produce warning) 
```
## How does nullptr solve the problem?
In the above program, if we replace NULL with nullptr, we get the output as “fun(char *)”.

**nullptr** is a keyword that can be used at all places where _NULL_ is expected. Like NULL, 
nullptr is implicitly convertible and comparable to any pointer type. Unlike NULL, it is not 
implicitly convertible or comparable to integral types.
```
    int x = nullptr; // Compiler Error
```
**NOTE**: nullptr is convertible to bool. Below program compile fine.
```
    int *ptr = nullptr; 
```

There are some unspecified things when we compare two simple pointers but comparison between 
two values of type nullptr_t is specified as, comparison by <= and >= return true and 
comparison by < and > returns false and comparing any pointer type with nullptr by == and != 
returns true or false if it is null or non-null respectively.

# Pointers vs References
Both references and pointers are very similar, both are used to have one variable provide 
access to another. With both providing lots of the same capabilities, it’s often unclear what 
is different between these different mechanisms.

**Pointers**: A pointer is a variable that holds memory address of another variable. A pointer 
needs to be dereferenced with * operator to access the memory location it points to.

**References** : A reference variable is an alias, that is, another name for an already 
existing variable. A reference, like a pointer, is also implemented by storing the address of an object.

A reference can be thought of as a constant pointer (not to be confused with a pointer to a 
constant value!) with automatic indirection, i.e the compiler will apply the * operator for you

## Differences
1. **Initialization**: A pointer can be initialized
we can declare and initialize pointer at same step or in multiple line.
References should declare and initialize references at single step.
1. **Reassignment**: A pointer can be re-assigned. This property is useful for implementation 
of data structures like linked list, tree, etc.
On the other hand, a reference cannot be re-assigned, and must be assigned at initialization.
1. **Memory Address**: A pointer has its own memory address and size on the stack whereas a 
reference shares the same memory address (with the original variable) but also takes up some 
space on the stack.
1. **NULL value**: Pointer can be assigned NULL directly, whereas reference cannot. The 
constraints associated with references (no NULL, no reassignment) ensure that the underlying 
operations do not run into exception situation.
1. **Indirection**: You can have pointers to pointers offering extra levels of indirection. 
Whereas references only offer one level of indirection.
1. **Arithmetic operations**: Various arithmetic operations can be performed on pointers 
whereas there is no such thing called Reference Arithmetic.(but you can take the address of an 
object pointed by a reference and do pointer arithmetics on it as in &obj + 5).)

## When to use What
The performances are exactly the same, as references are implemented internally as pointers. 
But still you can keep some points in your mind to decide when to use what :

**Use references**
* In function parameters and return types.
**Use pointers**
* Use pointers if pointer arithmetic or passing NULL-pointer is needed. For example for arrays 
(Note that array access is implemented using pointer arithmetic).
* To implement data structures like linked list, tree, etc and their algorithms because to 
point different cell, we have to use the concept of pointers.

