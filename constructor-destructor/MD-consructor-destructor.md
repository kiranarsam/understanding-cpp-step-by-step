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





