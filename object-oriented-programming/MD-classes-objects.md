# Classes and Objects
**Class:** A class is the building block, that leads to OOP. Class is a user-defined 
data-type, which holds its own data members and member functions, which can be accessed 
and used by creating an instance of that class.

**Object:** An Object is an instance of a Class. When a class is defined, no memory 
is allocated but when it is instantiated(i.e. an object is created) memory is allocated.
```
class ClassName {
    Access specifier:
        Data members;
        Member functions() { }
};
```
**Declaring Objects:** To use the data and access functions defined in class, you need 
to create objects.
```
ClassName ObjectName;
```
**Access Modifiers:** public, private and protected
**Member Functions in Classes:** Inside and outside class definition. To define function 
outside the class definition we should use **::** scope resolution operator along with 
class name and function name.

# Access Modifiers
It is used to implement in OOP as known as **Data Hiding**.

Access Modifiers or Access Speicifers is a _class_ are used to set the accessibility of the 
class members. That is, it sets some restrictions on the class members not to get directly 
accessed by the outside functions.

Three types of access specifiers:
* public
* private
* protected

**NOTE:** By default access modifier for the members in a class is **_private_**

1. **public** All the class members declared under public will be available to everyone. The 
data members and member functions declared public can be accessed by other classes too. The 
public members of a class can be accessed from anywhere in the program using the direct member 
access operator (.) with the object of that class.

1. **private** The class members declared as private can be accessed only by the functions 
inside the class. They are not allowed to be accessed directly by any object or function 
outside the class. Only the member functions or the friend functions are allowed to access the 
private data members of a class.

1. **protected** Protected access modifier is similar to that of private access modifiers, the 
difference is that the class member declared as Protected are inaccessible outside the class 
but they can be accessed by any subclass(derived class) of that class.

# Inheritance
The capability of a class to derive properties and characteristics from another class is called 
**Inheritance**.
**Sub Class:** The class that inherits properties from another class is called Sub class or 
Derived Class.
**Super Class:** The class whose properties are inherited by sub class is called Base Class or 
Super class.

* Inheritance avoids duplication of data.
* Inheritance increase re-usability.
```
Syntax:
class subclass_name : access_mode base_class_name
{
    // body of subclass
};
```
**NOTE:** A derived class doesn’t inherit **access** to private data members. However, it does 
inherit a full parent object, which contains any private members which that class declares.

## Modes of Inheritance
1. **Public mode:** If we derive a sub class from a public base class. Then the public member 
of the base class will become public in the derived class and protected members of the base 
class will become protected in derived class.
1. **Protected mode:** If we derive a sub class from a Protected base class. Then both public 
member and protected members of the base class will become protected in derived class.
1. **Private mode:** If we derive a sub class from a Private base class. Then both public 
member and protected members of the base class will become Private in derived class.

**NOTE:** The private members in the base class cannot be directly accessed in the derived 
class, while protected memebers can be directly accessed.

## Types of Inheritance
1. **Single Inheritance:** A class is allowed to inherit from only one class. i.e. one sub 
class is inherited by one class only.
1. **Multiple Inheritance:** A class can inherit from more than one classes. i.e. one _sub_ 
_class_ is inherited from more than one _base classes_.
1. **Multilevel Inheritance:** A derived class is created from another derived class.
1. **Hierarchical Inheritance:** More than one sub class is inherited from a single base class. 
i.e. more than one derived class is created from a single base class.
1. **Hybrid (Virtual) Inheritance:** By combining more than one type of inheritance. Its 
combination of hierarchical and multiple inheritance.

# Polymorphism
Means having many forms. Polymorphism as the ability of a message to be displayed in more than 
one form. 
Example:- Like a man at the same time is a father, a husband, an employee. So the same person 
posses different behaviour in different situations. It's called polymorphism.

### Two types of polymorphism
* Compile time Polymorphism
* Runtime Polymorphism
![Polymorphism](/object-oriented-programming/Types-Polymorphism.png)

1. **Compile time polymorphism:** It is achieved by function overloading or operator overloading
    * **Function Overloading:** When there are multiple functions with same name but different 
    parameters then these functions are said to be **overloaded**. Functions can be overloaded 
    by **change in number of arguments** or/and **change in type of arguments**.
    * **Operator Overloading:** C++ also provide option to overload operators. For example, we 
    can make the operator (‘+’) for string class to concatenate two strings. We know that this 
    is the addition operator whose task is to add two operands. So a single operator ‘+’ when 
    placed between integer operands , adds them and when placed between string operands, 
    concatenates them.

1. **Runtime polymorphism:** It is achieved by Function Overriding.
    * **Function Overriding:** when a derived class has a definition for one of the member 
    functions of the base class. That base function is said to be **overridden**.

# Encapsulation
It is defined as wrapping up of data and information under a single unit. In OOP, Encapsulation 
is defined as binding together the data and functions that manipulates them.

Enacpsulation is also leads to data abstraction or hiding. As using encapsulation also hides 
the data. 
### Role of access specifiers in encapsulation
Access specifiers plays an important role in implementing encapsulation. It is divided into two:
1. Tha data members should be labeled as private using the **private** access specifiers.
1. The member function which manipulates the data members should be labeled as public using 
the **public** access specifier.

# Abstraction
Abstraction means displaying only essential information and hiding the details.
Data Abstraction refers to providing only essential information about the data to the outside 
world, hiding the background details or implementation.

* **Abstraction using Classes:** Class helps us to group data members and member functions 
using available access specifiers. A Class can decide which data members will be visible to 
outside world and which is not.

* **Abstraction in Header files:** Ex:- Consider the pow() method present in math.h 
header file. Whenever we need to calculate power of a number, we simply call the function 
pow() present in the math.h header file and pass the numbers as arguments without knowing 
the underlying algorithm to which the function is actually calculating power of numbers.

### Abstraction using access specifiers
Access specifiers are the main pillar of implementing abstraction. We can use access 
specifiers to enforce restrictions on class members.
* Members declared as **public** in a class, can be accessed from anywhere in the program.
* Members declared as **private** in a class, can be accessed only from within the class.
They are not allowed to be accessed from any part of code outside the class.

### Advantages of Data Abstraction
* Helps the user to avoid writing the low-level code
* Avoids code duplication and increases reusability
* Can change internal implementation of class independently without effecting the users
* Helps to increase security of an application or program as only important details are given 
to the user.

# Structure vs Class
A structure is the same as a class except for a few differences. The most important of them 
is security. A Structure is not secure and cannot hide its implementation details from the 
end user while a class is secure and can hide its programming and designing details.
1. Members of a class are private by default and members of a struct are public by default.
1. When deriving a struct from a class/struct, default access-specifier for a base class/struct 
is public. And when deriving a class, default access specifier is private.

# Can a C++ class have an object of self type?
A class declaration can contain static object of self type, it can also have pointer to self 
type, but it cannot have a non-static object of self type.

If a non-static object is member then declaration of class is incomplete and compiler has no 
way to find out size of the objects of the class.

Static variables do not contribute to the size of objects. So, no problem in calculating size 
with static variables of self type.

For a compiler, all pointers have a fixed size irrespective of the data type they are pointing 
to, so no problem with this also.

# Why is the size of an empty class not zero
Size of empty class is not zero. It is 1 Byte generally. It is non-zero to ensure that the two 
different objects will have different addresses.

Different objects should have different addresses, **_new_** always returns pointers to 
distinct objects.

**NOTE:** Empty base class need not be represented by a separate byte. So compilers are free 
to make optimization in case of empty base classes.

# Static Data Members
Static data members must be explicitly defined outside the class using scope resolution operator.

If we try to access static member without explicit definition of it, we will get compilation error.

Static members are **_shared among all objects_**. That is why they are also known as 
**class members or class fields**. Also, static members can be accessed without any object.

# Some intresting facts about static member functions
1. static member functions do not have **_this_** pointer.
1. A static member function cannot be _virtual_
1. Member function declarations with the same name and the name parameter-type-list cannot 
be overloaded if any of them is a static member function declaration.
Example:- `void Test::fun()` and `static void Test::fun()` cannot be overloaded.
1. A static member function can not be declared _const, volatile or const volatile_.
Example:- `static void fun() const` is invalid

# friend class and function
**Friend class** A friend class can access private and protected members of other class in 
which it is declared as friend. It is sometimes useful to allow a particular class to access 
private members of other class.

**Friend function** A friend function can be given special grant to access private and 
protected members. A friend function can be:
1. A method of another class
1. A global function

* Friends should be used only for limited purpose. too many functions or external classes are 
declared as friends of a class with protected or private data, it lessens the value of 
encapsulation of separate classes in OOP.
* Friendhip is not mutual. If class A is a friend of B, then B doesn't become a friend of A 
automatically.
* Friendship is not inherited.

# Local Classes
A class declared inside a function becomes local to that function and is called Local Class.
1. A local class type name can only be used in the enclosing function.
1. All the methods of Local classes must be defined inside the class only.
1. A Local class cannot contain static data members. It may contain static functions though.
1. Member methods of local class can only access static and enum variables of the enclosing 
function. Non-static variables of the enclosing function are not accessible inside local classes.
1. Local classes can access global types, variables, and functions. Also, local classes can 
access other local classes of same function.

# Nested Classes
A nested class is a class which is declared in another enclosing class. A nested class is a 
member and as such has the same access rights as any other member. The members of an enclosing 
class have no special acces to members of a nested class rules shall be obeyed.

# Simulating final class
It makes use of private constructor, virutal inheritance and friend class.

See the example:- how the usage of private constructor, virtual inheritance and friend class.
`simulating-final-class.cpp`.