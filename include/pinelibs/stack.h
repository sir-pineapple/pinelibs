/*
 *
 * This is a header file for using stacks in C
 * use #include <pinelibs/stack.h> to use it in your C program
 * use the flag -lpinestack when compiling the program
 *
*/

#ifndef PINESTACK_H // check if the macro PINESTACK_H is defined or not
#define PINESTACK_H // if not defined, define it and run the rest of this program

// The above two lines ensure that there are no duplicate macros or function declarations

#include <pinelibs/bool.h>

typedef struct Stack* Stack; // declares Stack

Stack newStack(); // define newStack as NULL

Bool stackIsEmpty(Stack); // returns if the Stack is empty or not

#ifndef POP_FAILURE
#define POP_FAILURE 0x80000000 // this is returned if the Stack is empty
#endif // POP_FAILURE

void stackPush(Stack*, int value); // push a value into the Stack

int stackPop(Stack*); // pop a value from the Stack

int stackTop(Stack); // peek the top value of the Stack

#endif // PINESTACK_H
