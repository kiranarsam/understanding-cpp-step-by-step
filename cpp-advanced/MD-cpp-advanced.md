# User Defined Literals
User Defined Literals (**UDL**) are added from C++11. Although, C++ provides literals 
for a variety of built-in types but these are limited.
Examples of literals for built-in types :
```
    42      // int
    2.4     // double
    3.2F    // float
    'w'     // char
    32ULL   // Unsigned long long
    0xD0    // Hexadecimal unsigned
    "cd"    // C-style string(const char[3]")
```

## Why do we use UDLs?
Let us consider below example to understand need of UDLs.
```
    long double Weight = 2.3; //  pounds? kilograms? grams?
    // With UDL, we attach units to the values which has following advantages
    // 1) The code becomes readable.
    // 2) Conversion computations are done at compile time. 
    weight = 2.3kg;
    ratio = 2.3kg/1.2lb;
```
To compute the above ratio it is necessary to convert them to same units. UDLs help 
us to overcome unit translation cost. We can define user-defined literals for 
user-defined types and new form of literals for built-in types. They help to make 
constants in code more readable. The value of UDLs is substituted with the actual 
value defined in the code by the compiler at compile time. UDL’s don’t save much of 
coding time but more and more calculations can be shifted to compile-time for faster 
execution.

### Examples of User Defined Literals:
```
    "hello"s            // string
    4.3i                // imaginary
    101000111101001b    // binary
    53h                 // hours
    234093270497230409328432840923849 // extended-precision
```
UDLs are treated as a call to a literal operator. Only suffix form is supported. The 
name of the literal operator is `operator “”` followed by the suffix.

Here, constexpr is used to enable compile time evaluation.

Restriction:
UDL can only work with the following parameters:
```
    char const*
    unsigned long long
    long double
    char const*, std::size_t
    wchar_t const*, std::size_t
    char16_t const*, std::size_t
    char32_t const*, std::size_t
```
But return value can be of any types.

# Placement new operator
Placement new is a variation new operator. Normal new operator does two things :
1. Allocates memory 
1. Constructs an object in allocated memory.

Placement new allows us to separate above two things. In placement new, we can pass a 
preallocated memory and construct an object in the passed memory.

## new vs placement new
* Normal new allocates memory in heap and constructs objects tehre whereas using 
**placement new**, object construction can be done at known address.
* With normal new, it is not known that, at what address or memory location it’s 
pointing to, whereas the address or memory location that it’s pointing is known while 
**using placement new**.
* The deallocation is done using delete operation when allocation is done by new but 
there is no placement delete, but if it is needed one can write it with the help of 
destructor

Syntax: -
```
new (address) (type) initializer
As we can see, we can specify an address where we want a new object of given type 
to be constructed.
```
## When to prefer using placement new ?
As it allows to construct an object on memory that is already allocated , it is 
required for optimizations as it is faster not to re-allocate all the time. There may 
be cases when it is required to re-construct an object multiple times so, placement 
new operator might be more efficient in these cases.

## How to delete the memory allocated by placement new ?
The operator delete can only delete the storage created in heap, so when placement 
new is used delete operator cannot be used to delete the storage. In the case of 
memory allocation using placement new operator , since it is created in **stack** the 
compiler knows when to delete it and it will handle deallocation of the memory 
automatically.

## When will placement new operator show segmentation fault
The placement new operator should be used with care. The address which is passed can 
be a reference or a pointer  pointing to a valid memory location. It may show error 
when the address passed is :
* A pointer such as NULL pointer.
* A pointer that is not pointing to any location.
* It cannot be a void pointer unless it points to some location.

Invalid placemet new examples: Gives segmentation fault
```
    // Incorrect as ip may not be a valid address 
    int *ip; 
    int *i2 = new(ip) int(4) ; 
  
    // Incorrect as x is not an address 
    int x; 
    int *i5 = new(x) int(3) ;
```
## Advantages of placement new operator over new operator
* The address of memory allocation is known before hand.
* Useful when building a memory pool, a garbage collector or simply when performance 
and exception safety are paramount.
* There’s no danger of allocation failure since the memory has already been allocated,
 and constructing an object on a pre-allocated buffer takes less time.
* This feature becomes useful while working in an environment with limited resources.

