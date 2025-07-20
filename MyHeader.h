/******************************************************************************
* PROGRAMMED BY : Tamar Figotin
* ASSIGNMENT #6 : Boolean Expressions - Military Academy
*******************************************************************************/

#ifndef MYHEADER_H_
#define MYHEADER_H_

#include <iostream> /* cout, cin    */
#include <iomanip>  /* setw         */
#include <string>   /* string class */
using namespace std;

/******************************************************************************
 * FUNCTION OutputClassHeading
 * 	This function receives an assignment name, type, and number then outputs
 * 	the appropriate class heading - returns nothing. asType has set lab as
 * 	default, since there are more labs than assignments for this class.
 *-----------------------------------------------------------------------------
 * PRE-CONDITIONS
 * 	asName - Assignment Name
 * 	asNum  - Assignment Number
 * 	asType - Assignment Type ==> THIS SHOULD CONTAIN:
 * 						       	 'L' for Labs
 * 						         'A' for Assignments
 *-----------------------------------------------------------------------------
 * POST-CONDITIONS
 * 	This function will output the class heading
 *****************************************************************************/

void OutputClassHeading(string asName,         // IN - assignment name
						int    asNum,          // IN - assignment number
						char   asType = 'L');  // IN - assignment type
											   //	   'L' - Lab
											   //      'A' - Assignment

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

#endif /* MYHEADER_H_ */
