#include <iostream> 
#include <vector> 

using namespace std; 

int main() 
{ 
	vector<int> g1; 

    // Push elements at the end
	for (int i = 1; i <= 5; i++) 
		g1.push_back(i); 

    // Iterate from begin to end and display elements.
	cout << "Output of begin and end: "; 
	for (auto i = g1.begin(); i != g1.end(); ++i) 
		cout << *i << " "; 

    // constant iterate from cbegin to cend and display elements
	cout << "\nOutput of cbegin and cend: "; 
	for (auto i = g1.cbegin(); i != g1.cend(); ++i) 
		cout << *i << " "; 

    // Iterate reverse from rbegin to rend and display elements
	cout << "\nOutput of rbegin and rend: "; 
	for (auto ir = g1.rbegin(); ir != g1.rend(); ++ir) 
		cout << *ir << " "; 

    // constant iterate reverse from crbegin to crend and display elements
	cout << "\nOutput of crbegin and crend : "; 
	for (auto ir = g1.crbegin(); ir != g1.crend(); ++ir) 
		cout << *ir << " "; 
    
    // Capacity, size, and max_size of the vector
    cout << "Size : " << g1.size(); 
    cout << "\nCapacity : " << g1.capacity(); 
    cout << "\nMax_Size : " << g1.max_size(); 
    
    // resizes the vector size to 4 
    g1.resize(4); 
  
    // prints the vector size after resize() 
    cout << "\nSize : " << g1.size(); 
  
    // checks if the vector is empty or not 
    if (g1.empty() == false) 
        cout << "\nVector is not empty"; 
    else
        cout << "\nVector is empty"; 
  
    // Shrinks the vector 
    g1.shrink_to_fit(); 
    cout << "\nVector elements are: "; 
    for (auto it = g1.begin(); it != g1.end(); it++) 
        cout << *it << " ";
    
    cout << "\nReference operator [g] : g1[2] = " << g1[2]; 
  
    cout << "\nat : g1.at(1) = " << g1.at(1); 
  
    cout << "\nfront() : g1.front() = " << g1.front(); 
  
    cout << "\nback() : g1.back() = " << g1.back(); 
  
    // pointer to the first element 
    int* pos = g1.data(); 
  
    cout << "\nThe first element is " << *pos;

    // ===============================================================
    // Another example:
    // Assign vector 
    vector<int> v; 
  
    // fill the array with 10 five times 
    v.assign(5, 10); 
  
    cout << "The vector elements are: "; 
    for (int i = 0; i < v.size(); i++) 
        cout << v[i] << " "; 
  
    // inserts 15 to the last position 
    v.push_back(15); 
    int n = v.size(); 
    cout << "\nThe last element is: " << v[n - 1]; 
  
    // removes last element 
    v.pop_back(); 
  
    // prints the vector 
    cout << "\nThe vector elements are: "; 
    for (int i = 0; i < v.size(); i++) 
        cout << v[i] << " "; 
  
    // inserts 5 at the beginning 
    v.insert(v.begin(), 5); 
  
    cout << "\nThe first element is: " << v[0]; 
  
    // removes the first element 
    v.erase(v.begin()); 
  
    cout << "\nThe first element is: " << v[0]; 
  
    // inserts at the beginning 
    v.emplace(v.begin(), 5); 
    cout << "\nThe first element is: " << v[0]; 
  
    // Inserts 20 at the end 
    v.emplace_back(20); 
    n = v.size(); 
    cout << "\nThe last element is: " << v[n - 1]; 
  
    // erases the vector 
    v.clear(); 
    cout << "\nVector size after erase(): " << v.size(); 
  
    // two vector to perform swap 
    vector<int> v1, v2; 
    v1.push_back(1); 
    v1.push_back(2); 
    v2.push_back(3); 
    v2.push_back(4); 
  
    cout << "\n\nVector 1: "; 
    for (int i = 0; i < v1.size(); i++) 
        cout << v1[i] << " "; 
  
    cout << "\nVector 2: "; 
    for (int i = 0; i < v2.size(); i++) 
        cout << v2[i] << " "; 
  
    // Swaps v1 and v2 
    v1.swap(v2); 
  
    cout << "\nAfter Swap \nVector 1: "; 
    for (int i = 0; i < v1.size(); i++) 
        cout << v1[i] << " "; 
  
    cout << "\nVector 2: "; 
    for (int i = 0; i < v2.size(); i++) 
        cout << v2[i] << " "; 


	return 0; 
} 
