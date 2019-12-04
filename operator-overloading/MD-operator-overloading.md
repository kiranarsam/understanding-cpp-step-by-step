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
