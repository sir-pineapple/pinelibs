/*
 *
 * This is a header file for using queues in C
 * use #include <pinelibs/queue.h> to use it in your C program
 * use the flag -lpinequeue when compiling the program
 *
*/

#ifndef PINEQUEUE_H // check if the macro PINEQUEUE_H is defined or not
#define PINEQUEUE_H // if not defined, define it and run the rest of this program

// The above two lines ensure that there are no duplicate macros or function declarations

#include <pinelibs/bool.h>

typedef struct Queue Queue; // declares Queue

Queue newQueue(); // returns a NULL Queue

#ifndef POP_FAILURE
#define POP_FAILURE 0x80000000 // this is returned if the Queue is empty
#endif // POP_FAILURE

Bool queueIsEmpty(Queue); // returns if the Queue is empty or not

void queueInsert(Queue*, int value); // insert a value into the Queue

int queueRemove(Queue*); // remove a value from the Queue

int front(Queue); // returns the front value in the Queue

int rear(Queue); // returns the rear value in the Queue

#endif // PINEQUEUE_H
