# Heap Controller  

Heap Controller is a simple yet effective memory management tool for C programs. It tracks dynamically allocated memory, provides easy-to-use functions for allocation and deallocation, and ensures memory is properly cleaned up to avoid memory leaks.  

This project is especially useful for projects where manual memory management can become cumbersome or error-prone.  

## Features  
- **Memory Tracking:** Keeps a linked list of all allocated memory blocks for centralized control.  
- **Automatic Cleanup:** Frees all allocated memory in one call with `free_all_heap()`.  
- **Selective Deallocation:** Frees specific memory blocks with `free_ptr()`.  
- **Graceful Exits:** Includes an `exiter()` function to clean up memory and exit the program with a specified status code.  
- **Minimal Overhead:** Lightweight and efficient, designed for performance-critical applications.  
- **Failing Protection:** the `malocate()` function exits the program when the allocation failed with all heap freed

## How It Works  
1. **Dynamic Allocation:** The `mallocate()` function allocates memory and stores a reference in an internal linked list.  
2. **Selective Deallocation:** Use `free_ptr()` to free a specific memory block when it’s no longer needed.  
3. **Global Cleanup:** Call `free_all_heap()` to release all tracked memory at once, typically at the end of your program.  
4. **Graceful Exit:** Use `exiter()` to clean up memory and exit with a specified status code, you can also code the exiter function to be executed before exiting (like closing file descriptors, ...).
5. **Error handling:** In case of the allocation failed the heap controler exits the program with free leaks

## Getting Started  

### Important note for students:
HEAP CONTROLLER is not another piece of code that an AI generates, and you'll just copy it and use it to your code and go on,
but an idea to inspire from to make a better things.
Learning memory managment is a must for every programmer.
Dont be lazy!! by god, pls use your Brain.

### Prerequisites  
- A C compiler (e.g., GCC or Clang).  
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
	that's it nothing else needed.

4. Compile your program with heap_controller.c:

gcc -o program your_program.c heap_controller.c  


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
