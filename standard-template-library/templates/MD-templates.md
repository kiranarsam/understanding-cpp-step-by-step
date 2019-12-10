# Templates
A template is a simple and yet very powerful tool in C++. The simple idea is to pass 
data type as a parameter so that we don’t need to write the same code for different 
data types.
For example, a software company may need sort() for different data types. Rather than 
writing and maintaining the multiple codes, we can write one sort() and pass data 
type as a parameter.

C++ adds two new keywords to support templates: ‘template’ and ‘typename’. The second 
keyword can always be replaced by keyword ‘class’.

## How templates work?
Templates are expanded at compiler time. This is like macros. The difference is, 
compiler does type checking before template expansion. The idea is simple, source 
code contains only function/class, but compiled code may contain multiple copies of 
same function/class.

**Function Templates** We write a generic function that can be used for different 
data types. Examples of function templates are sort(), max(), min(), printArray().

**Class Templates** Like function templates, class templates are useful when a class 
defines something that is independent of the data type. Can be useful for classes 
like LinkedList, BinaryTree, Stack, Queue, Array, etc.

## Can there be more than one arguments to templates?
Yes, like normal parameters, we can pass more than one data types as arguments to templates.

## Can we specify default value for template arguments?
Yes, like normal parameters, we can specify default arguments to templates.

## What is the difference between function overloading and templates?
Both function overloading and templates are examples of polymorphism feature of OOP. 
Function overloading is used when multiple functions do similar operations, templates 
are used when multiple functions do identical operations.

## What happens when there is static member in a template class/function?
Each instance of a template contains its own static variable. 

## What is template specialization?
Template specialization allows us to have different code for a particular data type.

## Can we pass nontype parameters to templates?
We can pass non-type arguments to templates. Non-type parameters are mainly used for 
specifying max or min values or any other constant value for a particular instance of 
a template. The important thing to note about non-type parameters is, they must be 
const. The compiler must know the value of non-type parameters at compile time. 
Because compiler needs to create functions/classes for a specified non-type value at 
compile time.

# Template Metaprogramming
```
    template<int n> struct funStruct 
    { 
        enum { val = 2*funStruct<n-1>::val }; 
    }; 
    
    template<> struct funStruct<0> 
    { 
        enum { val = 1 }; 
    }; 
    
    int main() 
    { 
        cout << funStruct<8>::val << endl; 
        return 0; 
    } 
```
The program calculates `2 raise to the power 8 (or 2^8)`. In fact, the structure 
funStruct can be used to calculate `2^n` for any known n (or constant n). The special 
thing about above program is: calculation is done at compile time. So, it is compiler 
that calculates `2^8`. To understand how compiler does this, let us consider the 
following facts about templates and enums:

1. We can pass nontype parameters (parameters that are not data types) to class/function templates.
1. Like other const expressions, values of enumaration constants are evaluated at compile time.
1. When compiler sees a new argument to a template, compiler creates a new instance of the template.

Let us take a closer look at the original program. When compiler sees 
`funStruct<8>::val`, it tries to create an instance of funStruct with parameter as 8, 
it turns out that `funStruct<7>` must also be created as enumaration constant val 
must be evaluated at compile time. For `funStruct<7>`, compiler need `funStruct<6>` 
and so on. Finally, compiler uses `funStruct<1>::val` and compile time recursion 
terminates. So, using templates, we can write programs that do computation at compile 
time, such programs are called template metaprograms. Template metaprogramming is in 
fact Turing-complete, meaning that any computation expressible by a computer program 
can be computed, in some form, by a template metaprogram. Template Metaprogramming is 
generally not used in practical programs, it is an interesting conecpt though.

# Templates and Static variables
**Function templates and static variables**:
Each instantiation of function template has its own copy of local static variables. For example, there are two instances: void fun(int ) and void fun(double ). So two 
copies of static variable i exist.

**Class templates and static variables**:
The rule for class templates is same as function templates
Each instantiation of class template has its own copy of member static variables. For example, there are two instances Test and Test. So two copies of static variable 
count exist.

# Templates and Default Arguments
**Default parameters for templates**:
Like function default arguments, templates can also have default arguments. For 
example, the second parameter U has the default value as char.
source: [Default parameters for templates](default-value-in-templates.cpp)

**NOTE**: Also, similar to default function arguments, if one template parameter has 
a default argument, then all template parameters following it must also have default arguments.





