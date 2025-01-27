# Heap Controller  

Heap Controller is a simple design I made to manage memory in C programs. It tracks dynamically allocated memory, provides easy-to-use functions for allocation and deallocation, and ensures memory is properly cleaned up to avoid memory leaks.  

This project is especially useful for projects where manual memory management can become such a headache.  

## Features  
- **Memory Tracking:** Keeps a linked list of all allocated memory blocks for centralized control.  
- **Automatic Cleanup:** Frees all allocated memory in one call with `free_all_heap()`.  
- **Selective Deallocation:** Frees specific memory blocks with `free_ptr()`.  
- **Graceful Exits:** Includes an `exiter()` function to clean up memory and exit the program with a specified status code.  
- **Minimal Overhead:** Lightweight and efficient, designed for performance-critical applications.  
- **Failing Protection:** the `malocate()` function exits the program when the allocation failed with all heap freed.
- **Error handling:** In case of the allocation failed the heap controler exits the program with free leaks.
- 
## How It Works  
The `mallocate()` function allocates memory and stores a reference in an internal linked list. by that it makes it accessible any time and never lost even if you overwrite its returned refernce. the mallocate function also checks if an error prevent from allocating, them it exits the program by calling `exiter()` function. 
then you can use `free_ptr()` to free a specific memory block when it’s no longer needed, it frees the pointer and remove the node containing it from the linked list and by that even calling it twice doesn't cause a double free error.
the calling of `free_all_heap()` release all tracked memory at once, typically at the end of your program , noting that this wont free memory that are not tracked by HEAP CONTROLLER.  
or you may just use the `exiter()` function to clean up memory and exit with a specified status code since it calls `free_all_heap()` withing it .No worries , no double free are countered when using `free_all_heap()` multiple times and you can just start calling `mallocate()` again to start another linked list.
you can add some code to the exiter function to be executed before exiting the program (like closing file descriptors, ...), Is'nt that so powerfull!?


## Getting Started  

### Important note for students:
HEAP CONTROLLER is not another piece of code that an AI generates, and you'll just copy it and use it to your code and go on,
but an idea to inspire from to make a better things.
Learning memory managment is a must for every programmer.
Dont be lazy!! by god, pls use your Brain.

### Prerequisites  
- A C compiler (e.g., GCC or Clang), obviesly.  
- Very basic understanding of C memory management.  

### Installation  
1. Clone the repository:  
```bash  
   git clone https://github.com/your-username/heap-controller.git  
```

2. Include heap_controller.h in your program:
```c
	#include "heap_controller.h"  
```

3. Replace the standard function with HEAP CONTROLLER API functions:
	replacing `malloc()` function with `mallocate()`,
	replacing `free()` function with `free_ptr()`,
	replacing `exit()` function with `exiter()` or call `free_all_heap()` before exiting,
	that's it nothing else needed, how easy is that.

4. Compile your program with heap_controller.c:
```bash
gcc -o program your_program.c heap_controller.c  
```

###  Usage

Here’s a simple example to get you started:
```c
# include "heap_controller.h"

int	main(int ac, char **argv)
{

	// allocating
	int *ptr = (int *)mallocate(sizeof(int ) * matrix_size);

	// writing to the allocated memory
	*ptr = 42;

	//	reading allocated memory
	printf("ptr value => %d", *ptr)

	//free all memory
	free_all_heap();
	// exiter(0);

	return 0;
```
and you can see also the tests.c file to see other tests

The exiter() Function

The exiter(int code) function cleans up all allocated memory tracked by the Heap Controller and exits the program with the specified status code. This ensures that your program exits without memory leaks.
```c
#include "heap_controller.h"  

void exiter(int code) {
    // add your code to be executed before exiting here
    free_all_heap();  
    exit(code);  
}  
```
So you can just add some code to it that you want it to be executed before exiting

###  API funtions 
```c
void *mallocate(size_t size);
```
Allocates memory of the specified size and tracks it. Returns a pointer to the allocated memory.

```c
void free_all_heap();
```
Frees all memory blocks tracked by the Heap Controller.

```c
void free_ptr(void *ptr);
```
Frees a specific memory block allocated using mallocate().

```c
void exiter(int code);
```
Frees all tracked memory and exits the program with the given exit code.
