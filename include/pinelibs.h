/*
 *
 * This is a header file for including all header files in pinelibs
 * use #include <pinelibs.h> to include it in your C program
 *
*/

#ifndef PINELIBS_H // check if the macro PINELIBS_H is defined or not
#define PINELIBS_H // if not defined, define it and run the rest of this program

// The above two lines ensure that there are no duplicate macros or function declarations

#include <pinelibs/bool.h> // to define Booleans in C
#include <pinelibs/float.h> // to store Floating Point values in Integer variables
#include <pinelibs/vector.h> // to define Vectors in C
#include <pinelibs/linkedlist.h> // to define Linked Lists in C
#include <pinelibs/stack.h> // to define Stacks in C
#include <pinelibs/queue.h> // to define Queues in C
#include <pinelibs/tree.h> // to define Trees in C

#endif // PINELIBS_H
