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




