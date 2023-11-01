#include "freeList.h"
#include <assert.h>

freeList::freeList( long int*inRAM, int size ) {
  assert(inRAM != nullptr && size >= 2); // It does not hurt to check
  this->head = inRAM;
  *this->head = size - 2;
  *(this->head + 1) = 0;

}

long int*
freeList::reserve_space( int size ) {
  assert(size > 0);
  long int* loc = nullptr;
  if (*head >= size + 2) { // Check for memory availability
    loc = head + 2; // Two pointers ahead of the current head to account for the requested memory block's header information
    long int curr_size = *head;
    head += size + 2; // Head is now pointing to new end of allocated memory, or beginning of free block, if not at the end;
    *head = curr_size - (size + 2); // Shrink available space
  }
  // Let the requester check for null;
  return loc;
}

void
freeList::free_space( long int* location ) {
  assert(location != nullptr); // Never trust the programmer
  long int* freehead = location - 2; // Take two steps back to the spot of the header; This is pointer subtraction
  *freehead = *head + *freehead; // This about-to-be head has available space equal to 
  *freehead = *freehead - 2;     
  *(freehead + 1) = *head;    
  head = freehead;      
}

void
freeList::coalesce_forward() {
}

// print() is given to you. It traverses the free list and prints out what is there.
void freeList::print() {
  long int * printHead = head;
  
  while( printHead != NULL ) {
    cout << "at " << printHead << "("<< dec <<printHead[0] << " : 0x" << hex << printHead[1] <<  ")\n";
    printHead = (long int *)printHead[1];
  }
}
