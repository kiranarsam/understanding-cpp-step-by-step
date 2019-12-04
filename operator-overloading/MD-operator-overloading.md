# Operator Overloading
We can make operators to work for user defined classes. This means ability to provide the 
operators with a special meaning for a data type, this ability is known as operator overloading.

For example, we can overload an operator ‘+’ in a class like String so that we can concatenate 
two strings by just using +.

## What is the difference between operator functions and normal functions
Operator functions are same as normal functions. The only differences are, name of an operator 
function is always operator keyword followed by symbol of operator and operator functions are 
called when the corresponding operator is used.

## Can we overload all operators?
Almost all operators can be overloaded except few. Following is the list of operators that 
cannot be overloaded.
```
    . (dot)     ::     ?:     sizeof 
```
## Important points about operator overloading
1. For operator overloading to work, at least one of the operands must be a user defined class object.
1. Assignment Operator: Compiler automatically creates a default assignment operator with every 
class. The default assignment operator does assign all members of right side to the left side 
and works fine most of the cases (this behavior is same as copy constructor).
1. Conversion Operator: We can also write conversion operators that can be used to convert one 
type to another type.
Overloaded conversion operators must be a member method. Other operators can either be member 
method or global method.
1. Any constructor that can be called with a single argument works as a conversion constructor, 
means it can also be used for implicit conversion to the class being constructed.

# Copy constructor vs Assignment operator
Copy constructor is called when a new object is created from an existing object, as a copy of 
the existing object. And assignment operator is called when an already initialized object is 
assigned a new value from another existing object. 
```
t2 = t1;  // calls assignment operator, same as "t2.operator=(t1);" 
Test t3 = t1;  // calls copy constructor, same as "Test t3(t1);" 
```

## When should we write our own assignment operator
The answer is same as Copy Constructor. If a class doesn’t contain pointers, then there is no 
need to write assignment operator and copy constructor. The compiler creates a default copy 
constructor and assignment operators for every class. The compiler created copy constructor and 
assignment operator may not be sufficient when we have pointers or any run time allocation of 
resource like file handle, a network connection..etc.

1. Do not allow assignment of one object to other object. We can create our own dummy 
assignment operator and make it private.
1. Write your own assignment operator that does deep copy.

# What are the operators that can be and cannot be overloaded
List of operators that can be overloaded are:
```
+       -      *        /         %           ^
&       |       ~       !,        =
=      ++       --
==      !=      &&      ||
+=      -=      /=      %=        ^=          &=
|=      *=      =       []        ()
->      ->*     new     new []    delete      delete []
```

# List of operators that can be overloaded
```
1. Scope Resolution Operator        ::    
2. Pointer-to-member Operator       .*    
3. Member Access or Dot operator    . (dot)   
4. Ternary or Conditional Operator  ?: 
5. Object size Operator             sizeof 
6. Object type Operator             typeid
```

# Conversion Operators
The programmer abstracts real world objects using classes as concrete types. Sometimes it is 
required to convert one concrete type to another concrete type or primitive type implicitly. 
Conversion operators play smart role in such situations. 
Example:- converison-operatos.cpp


# Is assignment operator inherited
Like other functions, assignement operator function is inherited in derived class.

Example: base class assignment operator function can be accessed using the derived class object.
See: is-assignment-operator-inherited.cpp

# Default Assignment Operator and References
When we don’t write our own assignment operator, compiler created assignment operator does 
shallow copy and that cause problems. What happens when we have **references** in our class and 
there is **no user defined assignment operator**. Here, compiler doesn't create default assignment operator.

Compiler doesn’t creates default assignment operator in following cases:
1. Class has a nonstatic data member of a const type or a reference type
1. Class has a nonstatic data member of a type which has an inaccessible copy assignment operator
1. Class is derived from a base class with an inaccessible copy assignment operator

When any of the above conditions is true, user must define assignment operator.

# Overloading stream insertion ( << ) and extraction operator ( >> )
Stream insertion operator “<<” is used for output.
Stream extraction operator “>>” is used for input.

We must know following things before we start overloading these operators.
1. cout is an object of ostream class and cin is an object istream class
1. These operators must be overloaded as a global function. And if we want to allow them to 
access private data members of class, we must make them friend. 

## Why these operators must be overloaded as global?
In operator overloading, if an operator is overloaded as member, then it must be a member of 
the object on left side of the operator. For example, consider the statement “ob1 + ob2” (let 
ob1 and ob2 be objects of two different classes). To make this statement compile, we must 
overload ‘+’ in class of ‘ob1’ or make ‘+’ a global function.

The operators ‘<<' and '>>' are called like 'cout << ob1' and 'cin >> ob1'. So if we want to 
make them a member method, then they must be made members of ostream and istream classes, which 
is not a good option most of the time. Therefore, these operators are overloaded as global 
functions with two parameters, cout and object of user defined class.

# Overloading Subscript or array index operator []
Following are some useful facts about overloading of `[]`.
1. Overloading of `[]` may be useful when we want to check for index out of bound.
1. We must return by reference in function because an expression like `arr[i]` can be used an lvalue.





