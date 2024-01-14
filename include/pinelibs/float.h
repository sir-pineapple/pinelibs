/* 
 *
 * This is a header file for storing floating point values in integer variables without loss of precision in C
 * use #include <pinelibs/float.h> to use it in your C program
 * use the flag -lpinefloat when compiling the program
 *
*/

#ifndef PINEFLOAT_H // check if the macro PINEFLOAT_H is defined or not
#define PINEFLOAT_H // if not defined, define it and run the rest of this program

// The above two lines ensure that are no duplicate macros or function declarations

int toInt(float); // store float value in an int variable

float toFloat(int); // retrieve the float value from an int variable

long toLong(double); // store double value in a long variable

double toDouble(long); // retrieve the double value from a long variable

#endif // PINEFLOAT_H
