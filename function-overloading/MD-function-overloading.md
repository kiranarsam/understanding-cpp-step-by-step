# Function Overloading
Function overloading is where two or more functions can have the same name but different parameters.

Function overloading can be considered as an example of polymorphism.

# Functions that cannot be overloaded
Function declaractions cannot be overloaded
1. Function declarations that differ only in the return type. 
```
int foo() { return 10; } 
char foo() { return 'a'; } 
```
1. Member function declarations with the same name and the name parameter-type-list cannot 
be overloaded if any of them is a static member function declaration.
```
class Test { 
   static void fun(int i) {} 
   void fun(int i) {}    
}; 
```
1. Parameters declarations that differ only in a pointer * versus an array [] are equivalent.
i.e. the array declarations is adjusted to become a pointer declaration. Only the second and 
subsequent array dimensions are significant in parameter types.
```
int fun(int *ptr); 
int fun(int ptr[]); // redeclaration of fun(int *ptr) 
```
1. Parameter declarations that differ only in that one is a function type and the other is a 
pointer to the same function type are equivalent.
```
void h(int ()); 
void h(int (*)()); // redeclaration of h(int()) 
```
1. Parameter declarations that differ only in the presence or absence of const and/or volatile 
are equivalent. That is, the const and volatile type-specifiers for each parameter type are 
ignored when determining which function is being declared, defined, or called.
```
int f ( int x) { return x+10; } 
int f ( const int x) { return x+10; }
```
Only the const and volatile type-specifiers at the outermost level of the parameter type 
specification are ignored.

1. Two parameter declarations that differ only in their default arguments are equivalent.
```
int f ( int x, int y) { return x+10; } 
int f ( int x, int y = 10) { return x+y; } 
```

# Function overloading and const keyword
Member methods to be overloaded on the basis of const type. Overloading on the basis of const 
type can be useful when a function return reference or pointer. We can make one function const, 
that returns a const reference or const pointer, other non-const function, that returns 
non-const reference or pointer.
example:- [function-overloading-const-keyword](function-overloading-const-keyword.cpp)

## what about parameters
When we pass by reference or pointer, we can modify the value referred or pointed, so we can 
have two versions of a function, one which can modify the referred or pointed value, other 
which can not.
[Function overloading with parameters (pointer) having const](function-overloading-over-pointer.cpp)
[Function overloading with parameters (reference) having const](function-overloading-over-reference.cpp)

## Function overloading and return type
Functions can not be overloaded if they differ only in the return type. 

# Does overloading work with Inheritance
Overloading doesn’t work for derived class in C++ programming language. There is no overload 
resolution between Base and Derived. There is no overloading across scopes – derived class 
scopes are not an exception to this general rule.

Ex:- The compiler looks into the scope of Derived, finds the single function “double f(double)” 
and calls it. It never disturbs with the (enclosing) scope of Base.

# Can main() be overloaded
No, we cannot overloaded main().
But, it is necessary to use class and declare the main as member function. Note that main is not reserved word in programming languages.

# Function Overloading and float
It’s a well known fact in Function Overloading, that the compiler decides which function needs 
to be invoked among the overloaded functions. If the compiler can not choose a function amongst 
two or more overloaded functions, the situation is -” Ambiguity in Function Overloading”.

* The reason behind the ambiguity in above code is that the floating literals 3.5 and 5.6 are 
actually treated as double by the compiler. **As per C++ standard, floating point literals** 
**(compile time constants) are treated as double unless explicitly specified by a suffix**.
Since compiler could not find a function with double argument and got confused if the value 
should be converted from double to int or float.

