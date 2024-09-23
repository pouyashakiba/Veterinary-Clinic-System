/*******************************************************
 * Pouya Shakiba
 * Pooya.shakiba5@gmail.com
 * https://github.com/pouyashakiba
 * 2024/09/23
 *******************************************************/

// SAFE-GUARD: 
// It is good practice to apply safe-guards to header files
// Safe-guard's ensures only 1 copy of the header file is used in the project build
// The macro name should be mirroring the file name with _ for spaces, dots, etc.

// !!! DO NOT DELETE THE BELOW 2 LINES !!!
#ifndef CORE_H
#define CORE_H
#define use
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// 
// Copy your work done from Milestone #2 (core.h) into this file
// 
// NOTE:
// - Organize your functions into the below categories
// - Make sure the core.c file also lists these functions in the same order!
// - Be sure to provide a BRIEF comment for each function prototype
// - The comment should also be copied to the core.c function definition
//
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

//////////////////////////////////////
// USER INTERFACE FUNCTIONS
//////////////////////////////////////

//validats the number and display it if it's varified
void  displayFormattedPhone(const char* number);

// Clear the standard input buffer
void clearInputBuffer(void);

// Wait for user to input the "enter" key to continue
void suspend(void);


//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

//getting an int input from the user
int inputInt(void);

//getting and validating a pomonthsitive int input
int inputIntPositive();

//getting int input and validate it based on entered arguments(min & max)
int inputIntRange(int min, int max);

//getting an input from user and checks if it's existing in the given string or not
char inputCharOption(const char car[]);

//getting input from user and return the value if it's between max and min
void inputCString(char* string, int min, int max);


// !!! DO NOT DELETE THE BELOW LINE !!!
#endif // !CORE_H
