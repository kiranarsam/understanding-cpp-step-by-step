# std::sort() in STL 
Sorts such as vector or array (items with random access), etc.

By default, sort() sorts an array in ascending order.

## How to sort in descending order
sort() takes a third parameter that is used to specify the order in which elements 
are to be sorted. We can pass "greater()" function to sort in descending order. This 
function does a comparison in a way that puts greater elements before.

## How to sort in particular order
We can also write our own comparator function and pass it as a third parameter. This 
“comparator” function returns a value; convertible to bool, which basically tells us 
whether the passed “first” argument should be placed before the passed “second” 
argument or not.

# Type Inference (auto and decltype)
Type Inference refers to automatic deduction of the data type of an expression in a 
programming language. Before C++ 11, each data type needs to be explicitly declared 
at compile time, limiting the values of an expression at runtime but after the new 
version of C++, many keywords are included which allows a programmer to leave the 
type deduction to the compiler itself.

With type inference capabilities, we can spend less time having to write out things 
compiler already knows. As all the types are deduced in compiler phase only, the time 
for compilation increases slightly but it does not affect the run time of the program.

## auto keyword
The auto keyword specifies that the type of the variable that is being declared will 
be automatically deducted from its initializer. In case of functions, if their return 
type is auto then that will be evaluated by return type expression at runtime.

We have used typeid for getting the type of the variables. typeid is an operator 
which is used where dynamic type of an object need to be known. `typeid(x).name()` 
return shorthand name of the data type of x, for example, it return i for integers, d 
for doubles, Pi for the pointer to integer etc. But actual name returned is mostly 
compiler dependent.

A good use of auto is to avoid long initializations when creating iterators for containers.

**Note** : auto becomes int type if even an integer reference is assigned to it. To 
make it reference type, we use auto &.
```
int& fun() {   } // function that returns a 'reference to int' type

// m will default to int type instead of int& type
auto m = fun();

// n will be of int& type because of use of extra & with auto keyword
auto& n = fun();
```

## decltype Keyword
It inspects the declared type of an entity or the type of an expression. Auto lets 
you declare a variable with particular type whereas decltype lets you extract the 
type from the variable so decltype is sort of an operator that evaluates the type of 
passed expression.

# std::transform() in stl.
Perform an operation on all elements
Consider the problem of adding contents of two arrays into a thirs array. It is given 
that all arrays are of same size.

Using transform function in STL, we can add arrays in signle line.

## transform() is used in two forms
1. **Unary Operation**: Applies a unary operator on input to convert into output.
```
    transform(Iterator inputBegin, Iterator inputEnd, Iterator OutputBegin, unary_operation) 
```
1. **Binary Operation**: Applies a binary operator on input to convert into ouput.
```
    transform(Iterator inputBegin1, Iterator inputEnd1, 
         Iterator inputBegin2, Iterator OutputBegin, 
         binary_operation)
```
### More examples:
We can use transform to convert a string to upper case.
```
    // vect is a vector of integers.
    transform(vect.begin(), vect.end(),vect.begin(), increment); 
```

# Variadic function templates
Variadic templates are template that take a variable number of arguments. Variadic function templates are functions which can take multiple number of arguments.
Syntax for a variadic function template: :
```
    template(typename arg, typename... args)
    return_type function_name(arg var1, args... var2)
```
**Note**:, typename arg, typename... args must be inside angular brackets.

Remember that templates are replaced by actual functions by compiler.

# Template Specialization
Template is a feature. We write code once and use it for any data type including user 
defined data types.
For example, sort() can be written and used to sort any data type items. A class 
stack can be created that can be used as a stack of any data type.

What if we want a different code for a particular data type? 
Consider a big project that needs a function sort() for arrays of many different data 
types. Let Quick Sort be used for all datatypes except char. In case of char, total 
possible values are 256 and counting sort may be a better option. Is it possible to 
use different code only when sort() is called for char data type?

It is possible to get a special behavior for a particular data type. This is called **template specialization**.

```
    // A generic sort function  
    template <class T> 
    void sort(T arr[], int size) { 
        // code to implement Quick Sort 
    } 
    
    // Template Specialization: A function specialized for char data type 
    template <> 
    void sort<char>(char arr[], int size) { 
        // code to implement counting sort 
    }
```
Another example could be a class Set that represents a set of elements and supports 
operations like union, intersection, etc. When the type of elements is char, we may 
want to use a simple boolean array of size 256 to make a set. For other data types, 
we have to use some other complex technique.

### An Example Program for function template specialization
For example, consider the following simple code where we have general template fun() 
for all data types except int. For int, there is a specialized version of fun().

### An Example Program for class template specialization
In the following program, a specialized version of class Test is written for int data type.

## How does template specialization work
When we write any template based function or class, compiler creates a copy of that 
function/class whenever compiler sees that being used for a new data type or new set 
of data types(in case of multiple template arguments).

If a specialized version is present, compiler first checks with the specialized 
version and then the main template. Compiler first checks with the most specialized 
version by matching the passed parameter with the data type(s) specified in a 
specialized version.




