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
    ```
    pointer-variable = new data-type;
    Example:
    int *p = NULL;
    p = new int;
    
    or

    int *p = new int;
    ```
* **Initialise memory:** We can also initialize the memory using new operator.
    ```
    int *p = new int(25);
    float *f = new float(32.46);
    ```
* **Allocate block of memory:** new operator is also used to allocate a block(an array) 
of type data-type. _size_ specifies the number of elements in an array.
    ```
    pointer-variable = new data-type[size];
    Example:
        int *p = new int[20];
    ```

## delete operator
Programmer's responsibility to deallocate dynamically allocated memory.
```
// release memory pointed to pointer variable
**delete** pointer-variable;
```
To free the dynamically allocated array pointed by pointer-variable,
```
delete[] pointer-variable;
```

# malloc vs new 
### differences between malloc() and new
1. **Calling Constructors:** _new_ calls constructors, while _malloc_ does not. In fact 
primitive data types can also be initialized with _new_.
1. **operator vs function:** _new_ is an operator, while _malloc_ is a function.
1. **return type:** _new_ retuns exact data type, while _malloc_ returns _void *_.
1. **Failure Condition:** On failure _malloc_ returns NULL, where as _new_ throws bad_alloc
execption.
1. **Memory:** In case of _new_ memory is allocated from free store, where as _malloc_ memory 
allocated is done from heap.
1. **Overriding:** We are allowed to override _new_ operator, _malloc_ cannot override.
1. **Size:** Required size of memory is allocated by compiler for _new_, where as we have to 
manually calculate size for _malloc_.
1. **Buffer Size:** _malloc_ allows to change the size of buffer using _realloc_, while new doesn't.

# delete vs free
**delete** operator should only be used either for the pointers pointing to the memory 
allocated using _new_ operator or for a _NULL_ pointer,
**free** should only be used either for the pointers pointing to the memory allocated using 
_malloc_ or for a NULL pointer.


# std::get_temporary_buffer
Get a block of temporary memory.
* This function take a size _n_ and return the largest available buffer up to size n which 
can be fit into physical memory.
* This function get a memory of temporary nature mostly used for the operation of an alogortihm 
as some algorithms required extra space to perform correctly.
* Once the memory block is assigned is not needed anymore, it shall be released by calling 
**return_temprory_buffer**.

```
Syntax:
pair(int *, ptrdiff_t) p = get_temporary_buffer(int)(required_size)
```
