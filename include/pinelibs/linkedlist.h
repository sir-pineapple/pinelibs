/*
 *
 * This is a header file for using linked lists in C
 * use #include <pinelibs/linkedlist.h> to use it in your C program
 * use the flag -lpinell when compiling the program
 *
*/

#ifndef PINELL_H // check if the macro PINELL_H is defined or not
#define PINELL_H // if not defined, define it and run the rest of this program

// The above two lines ensure that there are no duplicate macros or function declarations

#include <pinelibs/bool.h>

typedef struct LinkedList* LinkedList; // declares LinkedList

LinkedList newLinkedList(); // define newLinkedList as NULL

#ifndef POP_FAILURE
#define POP_FAILURE 0x80000000 // this is returned if the LinkedList is empty
#endif // POP_FAILURE

Bool llIsEmpty(LinkedList); // returns if the LinkedList is empty or not

int llSize(LinkedList); // returns the size of the LinkedList

void llInsertStart(LinkedList*, int value); // insert an element to the beginning of the LinkedList

void llInsertEnd(LinkedList*, int value); // insert an element to the end of the LinkedList

void llInsertAt(LinkedList*, int index, int value); // insert an element at the given index of the LinkedList

int llRemoveStart(LinkedList*); // remove an element from the beginning of the LinkedList

int llRemoveEnd(LinkedList*); // remove an element from the end of the LinkedList

int llRemoveAt(LinkedList*, int index); // remove an element from the given index of the LinkedList

int llValAt(LinkedList, int index);

#endif // PINELL_H
