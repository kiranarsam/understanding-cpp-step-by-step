# Constructors
Constructors are special class members which are called by the compiler every time an 
object of that class is intantiated. Constructors have the same name as the class and 
may be defined inside or outside the class definition.
* Default constructors
* Parametrized constructors
* Copy constructors

A **Copy Constructors** creates a new object, which is exact copy of the existing object.
The compiler provides a default Copy Constructor to all the classes.
```
class-name (class-name &) { }
```

# Destructors
Destructor is another special member function that is called by the compiler when the scope 
of the object ends.
