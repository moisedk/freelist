## The Free list Assignment
### This assignment is designed to help students understand how a linked list structure can be embedded within the simulated memory while building a free list for allocated memory. 
#### This process follows what is described starting on page 7 of [OSTEP: Free List Management](https://pages.cs.wisc.edu/~remzi/OSTEP/vm-freespace.pdf)

The program with stubs for functions has already been created for you:
- [freeList.h](freeList.h) - the header of the free list class. DO NOT CHANGE THIS FILE
- [freeList.cc](freeList.cc) - the implementation file for the free list class. You will be implementing functions here.
- [main.cc](main.cc) - the file containing the <code>main()</code> function only. You will be making some changes to this file as you test your program. In its current form, <code>coalesce_forward()</code> will not do anything. You will need to change the way that memory blocks are reserved and freed to enable the simple coalescing function to work. 

## You are to implement the following in order:
- the constructor
- <code>reserver_space()</code> - the description for what needs to happen is defined in the header file. Note that after any number of these calls, there is still only item in the free list (the block of free space at the end.
- <code>free_space()</code> - the description for what needs to happen is defined in the header file. Note that it does not check for valid addresses and assumes that the process saved the correct one. As this function is repeatedly called (for each previously allocated chunks of memory), the free list increases and should be shown then it is printed.
- <code>coalesce_forward()</code> - the description for what needs to happen is defined in the header file. THIS FUNCTION IS HARD and only works to find blocks of free memory that are consecutive elements in the free list. Do not implement anything more sophisticated.

## Notes: 
- the <code>main()</code> function is currently built so that it creates an embedded free list in the heap (simulated as a dynamically allocated array of long ints), reserves a bunch of blocks and frees them, calling the print function after each action. *do not change the order of these operations!* All reserves should be done BEFORE any frees because we want to have the <code>head</code> variable to refer to the last block of memory.
- Once a <code>free_space()</code> function is called, the <code>head</code> variable will be pointing to the location of the most recently freed chunk, so calling <code>reserve_space()</code> will break.
- We will be doing some pointer arithmetic.
- In order to create the program, you need to type <code>make</code> in the directory where the source files and Makefile are located.
- You will be getting some practice using the Linux command line; it is a very good skill to develope! 
