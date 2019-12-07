#include <iostream> 
#include<string> 
using namespace std; 

class Pet { 
    public: 
        virtual string getDescription() const { 
            return "This is Pet Class"; 
        } 
}; 

class Dog : public Pet { 
    public: 
        virtual string getDescription() const { 
            return "This is Dog Class"; 
        } 
}; 

// Doesn't slice the derived class object. 
void describe(const Pet &p) {
	cout << p.getDescription() << endl; 
} 

int main() { 
	Dog d; 
	describe(d);

	return 0; 
}
