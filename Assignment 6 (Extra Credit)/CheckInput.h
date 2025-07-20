/******************************************************************************
* AUTHOR        : Tamar Figotin
* STUDENT ID    : 1315318
* ASSIGNMENT #6 : Boolean Expressions - Military Academy
* CLASS         : CS1A
* SECTION       : TTh: 11am
* DUE DATE      : 4/22/25
*******************************************************************************/
#ifndef CHECKINPUT_H_
#define CHECKINPUT_H_

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

/******************************************************************************
 * FUNCTION CheckIntInput
 * 	This function receives a prompt, minimum range, maximum range,
 * 	and prompt width and then returns a valid integer input, based on the
 * 	minimum and maximum range values.
 *-----------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 	prompt      - Prompt message for input
 * 	minRange    - Minimum accepted value (inclusively)
 * 	maxRange    - Minimum accepted value (inclusively)
 * 	promptWidth - Width of column
 *
 *-----------------------------------------------------------------------------
 * POST-CONDITIONS
 * 	This function will return a valid integer input.
 *****************************************************************************/

int CheckIntInput(string prompt,    // IN - prompt
				  int minRange,     // IN - minRange
				  int maxRange,     // IN - maxRange
				  int promptWidth); // IN - promptWidth


/******************************************************************************
 * FUNCTION CheckSexInput
 * 	This function receives a prompt and prompt width and then returns a
 * 	valid character for sex input, based on the accepted characters (m, M, f, F,
 * 	x, and X).
 *-----------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 	prompt      - Prompt message for input
 * 	promptWidth - Width of column
 *
 *-----------------------------------------------------------------------------
 * POST-CONDITIONS
 * 	This function will return a valid character input for sex.
 *****************************************************************************/

char CheckSexInput(string prompt,     // IN - prompt
				   int promptWidth);  // IN - promptWidth

#endif /* CHECKINPUT_H_ */
