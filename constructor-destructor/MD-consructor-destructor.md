# Constructors
A constructor is a member function of a class which initializes objects of a class. It is 
_automatically_ called when object(instance of class) create. It is special member function 
of the class.

## How constructors are different from a normal member function
* Constructor has same name as the class itself
* Constructors don't have return type
* A constructor is automatically called when an object is created
* If we do not specify a constructor, compiler genrates a default constructor for us (expects 
no parameters and has an empty body).

## Types of Constructors
* Default constructor
* Parameterized constructor
* Copy constructor

1. **Default Constructor:** Default constructor is the constuctor which doesn't take any 
argument. It has no parameters.
**NOTE:** Even if we do not define any constructor explicitly, the compiler will automatically
provide a default contructor implicitly.

2. **Parameterized Constructor:** It is possible to pass arguments to constructors. These 
arguments help initialize an object when it is created. 
```
Point p = Point(10,20); // Explicit call
Point p(10,20);         // Implicit call
```
## Uses of Parameterized constructor
* It is used to initialize the various data elements of different objects with different values 
when they are created.
* It is used to overload consturctors.

## Can we have more than one constructors in a class
Yes, It is called Constructor Overloading.

3. **Copy Constructor:** A copy constructor is a member function which initializes an object 
using another object of the same class.

**NOTE:** When ever we define one or more constructors with parameters for a class, a default 
constructor should also be explicitly defined. The compiler will not provide a default 
constructor in this case. It is good praticse to define default constructor.

# Copy Constructor
See definiton above
```
ClassName (const ClassName &oldObj);
```
## When is copy constructor is called
1. When an object of the class is returned by value
1. When an object of the class is passed to a function by value as an argument
1. When an object is constructed based on another object of the same class
1. when the compiler generates a temporary object

## When is used-defined copy constructor needed
If we don’t define our own copy constructor, the compiler creates a default copy constructor 
for each class which does a member-wise copy between objects. The compiler created copy 
constructor works fine in general. We need to define our own copy constructor only if an object 
has pointers or any runtime allocation of the resource like **_file handle_**, **_a network_** 
**_connection_**..etc.

**Default constructor does only shallow copy.**

![Shallow Copy](/constructor-destructor/copy-constructor-shallow-copy.png)

**Deep copy is possible only with user defined copy constructor.** In user defined copy 
constructor, we make sure that pointers (or references) of copied object point to new memory 
locations.

![Deep Copy](/constructor-destructor/copy-constructor-deep-copy.png)

## Copy Constructor vs Assignment Operator
```
MyClass t1, t2;
MyClass t3 = t1;    // Copy constructor
t2 = t1;            // Assignment Operator
```
**Copy constructor** is called when a new object is created from an existing object, as a copy
of the existing object. **Assignment operator** is called when an already initialized object is 
assigned a new value from another existing object. 

## Can we make copy constructor private?
Yes, a copy constructor can be made private. When we make a copy constructor private in a 
class, objects of that class become non-copyable. This is particularly useful when our class 
has pointers or dynamically allocated resources. In such situations, we can either write our 
own copy constructor like above String example or make a private copy constructor so that users 
get compiler errors rather than surprises at runtime.

## Why argument to a copy constructor must be passed as a reference?
A copy constructor is called when an object is passed by value. Copy constructor itself is a 
function. So if we pass an argument by value in a copy constructor, a call to copy constructor 
would be made to call copy constructor which becomes a non-terminating chain of calls. 
Therefore compiler doesn’t allow parameters to be passed by value.

## Why argument to a copy constructor should be const?
One reason for passing const reference is, we should use const wherever possible so that 
objects are not accidentally modified. This is one good reason for passing reference as const, 
but there is more to it.


# Destructors
Destructor is a member function which destructs or deletes an object.
## When is destructor called?
A destructor function is called automatically when the object goes out of scope:
1. the function ends
1. the program ends
1. a block containing local variables ends
1. a delete operator is called
## How destructors are different from a normal member function?
Destructors have same name as the class preceded by a tilde (**~**)
Destructors don’t take any argument and don’t return anything
## Can there be more than one destructor in a class?
No, there can only one destructor in a class with classname preceded by ~, no parameters 
and no return type.
## When do we need to write a user-defined destructor?
If we do not write our own destructor in class, compiler creates a default destructor for us. 
The default destructor works fine unless we have dynamically allocated memory or pointer in 
class. When a class contains a pointer to memory allocated in class, we should write a 
destructor to release memory before the class instance is destroyed. This must be done to avoid 
memory leak.
## Can a destructor be virtual?
Yes, In fact, it is always a good idea to make destructors virtual in base class when we have a 
virtual function.

## Does C++ compiler create default constructor when we write our own?
Compiler by default creates default constructor for every class. But, if we define our own 
constructor, compiler doesn’t create the default constructor.

## When should we write our own copy constructor?
Compiler provide default copy constructor (and assignment operator) with class. When we don’t 
provide implementation of copy constructor (and assignment operator) and tries to initialize 
object with already initialized object of same class then copy constructor gets called and 
copies members of class one by one in target object.

The problem with default copy constructor (and assignment operator) is – When we have members 
which dynamically gets initialized at run time, default copy constructor copies this members 
with address of dynamically allocated memory and not real copy of this memory. Now both the 
objects points to the same memory and changes in one reflects in another object, Further the 
main disastrous effect is, when we delete one of this object other object still points to same 
memory, which will be dangling pointer, and memory leak is also possible problem with this 
approach.

Hense, in such cases, we should always write our own copy constructor (and assignment operator).

## Initialization of data members
Class variables are initialized in the same order as they appear in the class declaration.
Check the example.

# Explicit Keyword
If a class has a constructor which can be called with a single argument, then this constructor 
becomes conversion constructor because such a constructor allows conversion of the single 
argument to the class being constructed
_We can avoid such implicit conversions as these may lead to unexpected results. We can make_ 
_the constructor explicit with the help of explicit keyword._

## Why do we use initilizer list
Initializer List is used in initializing the data members of a class. The list of members to be 
initialized is indicated with constructor as a comma-separated list followed by a colon.
```
Point(int i = 0, int j = 0) : x(i), y(j) { }
```
But there are situations where initialization of data members inside constructor doesn’t work and Initializer List must be used.

Following cases are:
1. **For initialization of non-static const data members:**
const data members must be initialized using Initializer List.
Reason for initializing the const data member in initializer list is because no memory is 
allocated separately for const data member, it is folded in the symbol table due to which we 
need to initialize it in the initializer list.

1. **For initialization of reference members:**
Reference members must be initialized using Initializer List.
1. **For initialization of member objects which do not have default constructor:**
1. **For initialization of base class members**
The parameterized constructor of the base class can only be called using Initializer List.
1. **When constructor’s parameter name is same as data member**
If constructor’s parameter name is same as data member name then the data member must be 
initialized either using this pointer or Initializer List.
1. **For Performance reasons**
It is better to initialize all class variables in Initializer List instead of assigning values inside body.

# Default Constructors
A constructor without any arguments or with default value for every argument, is said to 
be **default constructor**.

The compiler will implicitly declare default constructor if not provided by programmer, will 
define it when in need. Compiler defined default constructor is required to do certain 
initialization of class internals. It will not touch the data members or plain old data types 
(aggregates like an array, structures, etc…). However, the compiler generates code for default 
constructor based on the situation.

# Private Destructors
Only with dynamic memory allocation and help of friend class, user can be delete the object.
`Example:- private-destructors.cpp`

## What is the use of private destructor?
Whenever we want to control destruction of objects of a class, we make the destructor private. 
For dynamically created objects, it may happen that you pass a pointer to the object to a 
function and the function deletes the object. If the object is referred after the function call,
 the reference will become dangling.

## Playing with Destructors
`Example:- playing-with-destructors.cpp`

# Copy Elision or Copy Omission
It is compiler optimization technique that avoids unnecessary copying of objects. Now a days, 
almost every compiler uses it.
```
B ob = "copy me";
should be broke down by the compiler as
B ob = B("copy me");
```
## Why copy constructor is not called?
According to theory, when the object “ob” is being constructed, one argument constructor is 
used to convert “copy me” to a temporary object & that temporary object is copied to the object 
“ob”.

Modern compilers avoids such overheads of creating a temporary object & then copying it.
```
    B ob = "copy me"; // copy initialization
as
    B ob("copy me"); // direct initialization
and thus eliding call to copy constructor
```
However, if we still want to ensure that the compiler doesn’t elide the call to copy 
constructor [disable the copy elision], we can compile the program using 
`-fno-elide-constructors` option with g++. `g++ copy_elision.cpp -fno-elide-constructors`

If `-fno-elide-constructors` option is used, first default constructor is called to create a temporary object, then copy constructor is called to copy the temporary object to ob.

# Default constructor for Built-in Data types
allows even built-in type (primitive types) to have default constructors. The function style 
cast int() is analogous to casting 0 to required type.

# When does compiler create default and copy constructors
Compiler creates a **default constructor** if we don’t define our own constructor (See this). 
Compiler created default constructor has empty body, i.e., it doesn’t assign default values to 
data members.

Compiler also creates a **copy constructor** if we don’t write our own copy constructor. Unlike 
default constructor, body of copy constructor created by compiler is not empty, it copies all 
data members of passed object to the object which is being created.

## What happens when we write only a copy constructor – does compiler create default constructor
Compiler **doesn’t create** a **default constructor** if we write any constructor even if it is copy constructor. Gives compiler error.

## What about reverse – what happens when we write a normal constructor and don’t write a copy constructor
Reverse is not true. Compiler **creates** a copy constructor if we don’t write our own. 
Compiler creates it even if we have written other constructors in class.

**NOTE:** So we need to write copy constructor only when we have pointers or run time 
allocation of resource like file handle, a network connection, etc

# Why copy constructor argument should be const
When we create our own copy constructor, we pass an object by reference and we generally pass 
it as a const reference.
One reason for passing const reference is, we should use const in C++ wherever possible so that 
objects are not accidentally modified. This is one good reason for passing reference as const, 
but there is more to it.

# Virtual Constructor
## Can we make a class constructor virtual to create polymorphic objects 
No. C++ being static typed (the purpose of RTTI is different) language, it is meaningless to 
the C++ compiler to create an object polymorphically. The compiler must be aware of the class 
type to create the object. In other words, what type of object to be created is a compile time 
decision from C++ compiler perspective.
If we make constructor virtual, compiler flags an error. In fact except inline, no other 
keyword is allowed in the declaration of constructor.

In practical scenarios we would need to create a derived class object in a class hierarchy 
based on some input. Putting in other words, _object creation and object type are tightly_ 
_coupled which forces modifications to extended. The objective of virtual constructor is to_ 
_decouple object creation from it’s type_.

virtual constructor creates an object of class hierarchy at runtime based on some input. 
Check the example: virtual-consturctor.cpp
```
    // The "Virtual Constructor" 
    static Base *Create(int id);
```

# Virtual Copy Constructor
Sometimes we may need to construct an object from another existing object. Precisely the copy 
constructor does the same. The initial state of new object will be based on another existing 
object state. The compiler places call to copy constructor when an object being instantiated 
from another object. However, the compiler needs concrete type information to invoke 
appropriate copy constructor.

Virtual constructor creates an object of class hierarchy at runtime based on some input. When 
we want to copy construct an object from another object created by virtual constructor, we 
can’t use usual copy constructor. We need a **special cloning function** that can duplicate the 
object at runtime.

The concept behind clone function is building block of **_prototype pattern_**.
```
    // The "Virtual Copy Constructor" 
    virtual Base *Clone() = 0;
```

# When are static objects destroyed
careful static keyword and static object
## What is static keyword
**static** keyword can be applied to local variables, functions, class’ data members and 
objects. 
static local variable retain their values between function call and initialized only once. 
static function can be directly called using the scope resolution operator preceded by class name.

## What are static objects
An object become static when static keyword is used in its declaration. 

```
Test t;         \\ stack based object
static Test t;  \\ static object
```
First statement when executes creates object on stack means storage is **allocated on stack**. 
Stack based objects are also called automatic objects or local objects. 

**static object** are initialized only once and live until the program terminates. 
**Local object** is created each time its declaration is encountered in the execution of program.

**static objects** are allocated storage in static storage area. 
**static object** is destroyed at the termination of program. 
This language supports both local static object and global static object.

# Is it possible to call constructor and destructor explicitly
**Constructor** is a special member function that is automatically called by compiler when 
object is created and **destructor** is also special member function that is also implicitly 
called by compiler when object goes out of scope.
They are also called when dynamically allocated object is allocated and destroyed, new operator 
allocates storage and calls constructor, delete operator calls destructor and free the memory allocated by new.

### Is it possible to call constructor and destructor explicitly
Yes, it is possible to call special member functions explicitly by programmer.

* When the constructor is called explicitly the compiler creates a nameless temporary object 
and it is immediately destroyed.
```
NOTE:
Once a destructor is invoked for an object, the object no longer exists; the behavior is 
undefined if the destructor is invoked for an object whose lifetime has ended.

As mentioned here, we should never call destructor explicitly on local (automatic) object, 
because really bad results can be acquired by doing that.

Local objects are automatically destroyed by compiler when they go out of scope and this is the guarantee. In general, special member functions shouldn’t be called explicitly.
```
* Constructor and destructor can also be called from the member function of class.

* Explicit call to destructor is only necessary when object is placed at particular location in 
memory by using placement **new**. Destructor should not be called explicitly when the object 
is dynamically allocated because **delete** operator automatically calls destructor.







