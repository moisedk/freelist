#include <iostream>
#include <stdlib.h>
using namespace std;

class freeList {
public:

  // Constructor: Taking a pointer to an array of long ints and its
  // size, it sets up the simulated memory with the appropriate header
  // information
  freeList( long int*, int size );

  // reserve_space: Taking a size as the number of long int's (note
  // that because we are working with a 64-bit physical machine, each
  // addressable location does not contain bytes (8 bits), but long
  // ints (64 bits, or 8 bytes).

  // It returns the address of the allocation space, which is 2 spots
  // AFTER the head of the chunk because those two are in the header
  // and hold the meta data. Make sure to update head to not just the
  // size but two more to account for this overhead.
  // Also, make sure to update the value at head to reflect the
  // updated amount of space after size has been allocated.
  
  // NOTE: if you add 4 to head, which is a pointer, the program will
  // alsomatically convert that 4 to 32 because a 4 long int jump is
  // equizalent to 32 bytes (4x64 bits = 4x8bytes = 32)
  long int* reserve_space( int size );

  // free_space: Given a pointer value, it updates the table to add
  // the chunk referened by the input pointer to the front of free
  // list and update head to now refer to it. Whatever head refers to
  // should be updated to be the "next" field of this chunk.

  // Note that the input pointer is referring to the start of the data
  // of this chunk, so you need to go to two spots before it to access
  // the header.
  void free_space( long int* pntr );

  // Manipulate the RAM so that chunks that are continuous are
  // coalesced. This function for NOT find pieces that are BEFORE each
  // chunk, however.
  void coalesce_forward();

  // the print function is given to you that outputs the contents of
  // the free list as currently represented in simulated memory.
  void print();

private:
  long int * head;    
};

