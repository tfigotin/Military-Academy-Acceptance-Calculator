/******************************************************************************
* AUTHOR        : Tamar Figotin
* STUDENT ID    : 1315318
* ASSIGNMENT #6 : Boolean Expressions - Military Academy
* CLASS         : CS1A
* SECTION       : TTh: 11am
* DUE DATE      : 4/22/25
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

#endif /* MYHEADER_H_ */
