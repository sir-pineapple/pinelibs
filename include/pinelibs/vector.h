/*
 *
 * This is a header file for using vectors in C
 * use #include <pinelibs/vector.h> to use it in your C program
 * use the flag -lpinevector when compiling the program
 *
*/

#ifndef PINEVECTOR_H // check if the macro PINEVECTOR_H is defined or not
#define PINEVECTOR_H // if not defined, define it and run the rest of this program

// The above two lines ensure that there are no duplicate macros or function declarations

typedef struct Vector Vector; // declares Vector

Vector newVector(int capacity); // returns an empty vector of the given capacity

void vectorInsert(Vector*, int value); // inserts a new element into the vector and increase capacity if needed

#endif // PINEVECTOR_H
