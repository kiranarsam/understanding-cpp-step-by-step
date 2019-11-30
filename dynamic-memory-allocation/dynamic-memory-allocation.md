Dynamic memory allocation refers to performing memory allocation manually by programmer. 
Dynamically allocated memory is allocated on **Heap** and non-static and local variables 
get memory allocated on **Stack**.

### How is memory allocated / deallocated in C++
C uses _malloc()_ and _calloc()_ function to allocate memory dynamically at runtime and 
uses _free()_ function to free dynamically allocated memory.
C++ uses _**new**_ and _**delete**_ that perform the task of allocating and freeing the 
memory in a better and easier way.

## new operator
The _new_ operator denotes a request for memory allocation on the Heap. If sufficient 
memory is available, new operator initializes the memory and returns the address of the 
newly allocated and initialized memory to the pointer variable.
* **Syntax to use new operator:** To allocate memory of any data type, the syntax is
    `pointer-variable = new data-type;`
    `Example:`
    `int *p = NULL;`
    `p = new int;`

* **Initialise memory:** We can also initialize the memory using new operator.
    - ``