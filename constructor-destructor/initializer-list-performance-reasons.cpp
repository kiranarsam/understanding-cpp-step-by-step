// Without Initializer List 
template <class Type>
class MyClass { 
	Type variable; 
public: 
	MyClass(Type a) { // Assume that Type is an already 
					// declared class and it has appropriate 
					// constructors and operators 
	variable = a; 
	} 
};
/* Steps order is 
1. Type’s constructor is called first for “a”.
2. The assignment operator of “Type” is called inside body of MyClass() constructor to assign
    variable = a; 
3. And then finally destructor of “Type” is called for “a” since it goes out of scope.
*/

// With Initializer List 
template <class Type>
class MyClass1 { 
	Type variable; 
public: 
	MyClass1(Type a):variable(a) { // Assume that Type is an already 
					// declared class and it has appropriate 
					// constructors and operators 
	} 
}; 

/* Steps order
1. Copy constructor of “Type” class is called to initialize: variable(a). The arguments in the initializer list are used to copy construct “variable” directly.
2. The destructor of “Type” is called for “a” since it goes out of scope.
*/

/**
As we can see from this example if we use assignment inside constructor body there are 
three function calls: 
constructor + destructor + one addition assignment operator call. 

And if we use Initializer List there are only two function calls: 
copy constructor + destructor call.
*/