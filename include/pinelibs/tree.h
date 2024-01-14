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

typedef struct Tree {int value; struct Tree* left; struct Tree* right;}* Tree; // defines Tree as a struct containing an int and twi pointers to the left and right trees

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

#endif // PINETREE_H
