/*
 *
 * This is a header file for using booleans in C
 * use #include <pinelibs/bool.h> to use it in your C program
 *
*/

#ifndef PINEBOOL_H // check if the macro PINEBOOL_H is defined or not
#define PINEBOOL_H // if not defined, define it and run the rest of this program

// The above two lines ensure that there are no duplicate macros or function declarations

#define Bool char // define Bool data type as a char, this is to make it an 8-bit data type
#define true 1 // define true as 1
#define false 0 //define false as 0

#endif // PINEBOOL_H
