#include "freeList.h"

freeList::freeList( long int*inRAM, int size ) {
}

long int*
freeList::reserve_space( int size ) {
  long int* loc = NULL;

  return loc;
}

void
freeList::free_space( long int* location ) {
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
