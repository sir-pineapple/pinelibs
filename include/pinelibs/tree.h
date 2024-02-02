/*
 *
 * This is a header file for using trees in C
 * use #include <pinelibs/tree.h> to use it in your C program
 * use the flag -lpinetree when compiling the program
 *
*/

#ifndef PINETREE_H // check if the macro PINETREE_H is defined or not
#define PINETREE_H // if not defined, define it and run the rest of this program

// The above two lines ensure that there are no duplicate macros or function declarations

typedef struct Tree* Tree; // declare Tree

#ifndef POP_FAILURE
#define POP_FAILURE 0x80000000 // This is returned when you try to Remove a NULL Tree
#endif // POP_FAILURE

Tree newTree(int value); // create a new Tree of given value

int treeHeight(Tree); // returns the height of the Tree

void treeLLRot(Tree*); // performs LL-Rotation on the Tree

void treeLRRot(Tree*); // performs LR-Rotation on the Tree

void treeRLRot(Tree*); // performs RL-Rotation on the Tree

void treeRRRot(Tree*); // performs RR-Rotation on the Tree

void treeBalance(Tree*); // Balances the Tree by performing required rotations

void treeInsert(Tree*, int value); // Inserts the given value in the Tree

int treeRemove(Tree*); // removes the given Node of the Tree

Tree treeLeft(Tree); // returns the Tree to the left of the input Tree

Tree treeRight(Tree); // returns the Tree to the right of the input Tree

int treeVal(Tree); // returns the value stored in the current Tree Node

#endif // PINETREE_H
