# Constructors
A constructor is a member function of a class which initializes objects of a class. It is 
_automatically_ called when object(instance of class) create. It is special member function 
of the class.

#### How constructors are different from a normal member function
* Constructor has same name as the class itself
* Constructors don't have return type
* A constructor is automatically called when an object is created
* If we do not specify a constructor, compiler genrates a default constructor for us (expects 
no parameters and has an empty body).

### Types of Constructors
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
##### Uses of Parameterized constructor
* It is used to initialize the various data elements of different objects with different values 
when they are created.
* It is used to overload consturctors.

##### Can we have more than one constructors in a class
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
### When is copy constructor is called
1. When an object of the class is returned by value
1. When an object of the class is passed to a function by value as an argument
1. When an object is constructed based on another object of the same class
1. when the compiler generates a temporary object

### When is used-defined copy constructor needed

