# Containers
## Pair in Standard Template Library
The pair container is a simple container defined in `<utility>` header consisting of two data 
elements or objects.

* The first element is referenced as ‘first’ and the second element as ‘second’ and the order is fixed (first, second).
* Pair is used to combine together two values which may be different in type. Pair provides a way to store two heterogeneous objects as a single unit.
* Pair can be assigned, copied and compared. The array of objects allocated in a map or 
hash_map are of type ‘pair’ by default in which all the ‘first’ elements are unique keys 
associated with their ‘second’ value objects.
* To access the elements, we use variable name followed by dot operator followed by the keyword first or second.
Syntax:- 
```
    pair (data_type1, data_type2) Pair_name;
```
We can also initialize a pair. Syntax :
```
    pair (data_type1, data_type2) Pair_name (value1, value2) ;
```
Different ways to initialize pair:
```
    pair  g1;           //default
    pair  g2(1, 'a');   //initialized,  different data type
    pair  g3(1, 10);    //initialized,  same data type
    pair  g4(g3);       //copy of g3
```
Another way to initialize a pair is by using the make_pair() function.
```
    g2 = make_pair(1, 'a');
```
**NOTE**: If not initialized, the first value of the pair gets automatically initialized.

## Member Functions
1. **make_pair()**: This template function allows to create a value pair without writing the types explicitly. Syntax :
```
    Pair_name = make_pair (value1,value2);
```
1. operators(=, ==, !=, >=, <=) : We can use operators with pairs as well.
    * **using equal(=)**: It assigns new object for a pair object.
    Syntax : ` pair& operator= (const pair& pr); `
    This Assigns pr as the new content for the pair object. The first value is assigned the first value of pr and the second value is assigned the second value of pr .

    * **Comparison (==) operator with pair**: For given two pairs say pair1 and pair2, the comparison operator compares the first value and second value of those two pairs i.e. if pair1.first is equal to pair2.first or not AND if pair1.second is equal to pair2.second or not .
    * **Not equal (!=) operator with pair**: For given two pairs say pair1 and pair2, the != operator compares the first values of those two pairs i.e. if pair1.first is equal to pair2.first or not, if they are equal then it checks the second values of both.
    * **Logical( >=, <= )operators with pair**: For given two pairs say pair1 and pair2, the =, >, can be used with pairs as well. It returns 0 or 1 by only comparing the first value of the pair.
1. **swap**: This function swaps the contents of one pair object with the contents of another 
pair object. The pairs must be of same type.
Syntax : ` pair1.swap(pair2) ; `
For two given pairs say pair1 and pair2 of same type, swap function will swap the pair1.first 
with pair2.first and pair1.second with pair2.second.

# Vector in STL
Vectors are same as dynamic arrays with the ability to resize itself automatically when an 
element is inserted or deleted, with their storage being handled automatically by the 
container. Vector elements are placed in contiguous storage so that they can be accessed and 
traversed using iterators. In vectors, data is inserted at the end. Inserting at the end takes 
differential time, as sometimes there may be a need of extending the array. Removing the last 
element takes only constant time because no resizing happens. Inserting and erasing at the 
beginning or in the middle is linear in time.

Certain functions associated with the vector are:
**Iterators**:
1. **begin()** – Returns an iterator pointing to the first element in the vector
1. **end()** – Returns an iterator pointing to the theoretical element that follows the last element in the vector
1. **rbegin()** – Returns a reverse iterator pointing to the last element in the vector (reverse beginning). It moves from last to first element
1. **rend()** – Returns a reverse iterator pointing to the theoretical element preceding the first element in the vector (considered as reverse end)
1. **cbegin()** – Returns a constant iterator pointing to the first element in the vector.
1. **cend()** – Returns a constant iterator pointing to the theoretical element that follows the last element in the vector.
1. **crbegin()** – Returns a constant reverse iterator pointing to the last element in the vector (reverse beginning). It moves from last to first element
1. **crend()** – Returns a constant reverse iterator pointing to the theoretical element preceding the first element in the vector (considered as reverse end)

**Capacity**
1. **size()** – Returns the number of elements in the vector.
1. **max_size()** – Returns the maximum number of elements that the vector can hold.
1. **capacity()** – Returns the size of the storage space currently allocated to the vector expressed as number of elements.
1. **resize(n)** – Resizes the container so that it contains ‘n’ elements.
1. **empty()** – Returns whether the container is empty.
1. **shrink_to_fit()** – Reduces the capacity of the container to fit its size and destroys all elements beyond the capacity.
1. **reserve()** – Requests that the vector capacity be at least enough to contain n elements.

**Element access**:
1. **reference operator [g]** – Returns a reference to the element at position ‘g’ in the vector
1. **at(g)** – Returns a reference to the element at position ‘g’ in the vector
1. **front()** – Returns a reference to the first element in the vector
1. **back()** – Returns a reference to the last element in the vector
1. **data()** – Returns a direct pointer to the memory array used internally by the vector to store its owned elements.

**Modifiers**:
1. **assign()** – It assigns new value to the vector elements by replacing old ones
1. **push_back()** – It push the elements into a vector from the back
1. **pop_back()** – It is used to pop or remove elements from a vector from the back.
1. **insert()** – It inserts new elements before the element at the specified position
1. **erase()** – It is used to remove elements from a container from the specified position or range.
1. **swap()** – It is used to swap the contents of one vector with another vector of same type. Sizes may differ.
1. **clear()** – It is used to remove all the elements of the vector container
1. **emplace()** – It extends the container by inserting new element at position
1. **emplace_back()** – It is used to insert a new element into the vector container, the new element is added to the end of the vector
