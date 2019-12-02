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






