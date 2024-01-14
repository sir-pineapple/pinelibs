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

#ifndef PINENODE
#define PINENODE
typedef struct Node {int value; struct Node* next;} Node; // defines Node as an int value and Node pointer to the next Node
#endif // PINENODE

typedef struct {Node* front; Node* rear;} Queue; // define Queue as a Node pointer to front and one to rear

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
