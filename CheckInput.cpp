/******************************************************************************
* PROGRAMMED BY : Tamar Figotin
* ASSIGNMENT #6 : Boolean Expressions - Military Academy
*******************************************************************************/

#include "MyHeader.h"

/*****************************************************************************
* VARIABLES
*****************************************************************************/
int intInput;    // IN & OUT - integer input entered
char charInput;  // IN & OUT - character input entered
bool invalid;    // PROC     - determines if integer/character is a valid input

/******************************************************************************
* PROCESSING for CheckIntInput: Function reads in an input and checks first
* 								that it is an integer, and then checks if its
* 								value is between the set minimum and maximum
* 								range. Once it receives a valid input, it
* 								returns the valid integer input.
*
******************************************************************************/
int CheckIntInput(string prompt, int minRange, int maxRange, int promptWidth)
{
	int intInput;
	bool invalid;

	do
	{
		cout << left << setw(promptWidth) << prompt;

		if(!(cin >> intInput))
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "INVALID INPUT!" << endl;
			invalid = true;
		}
		else
		{
			invalid = intInput <= minRange || intInput >= maxRange;
			if(invalid)
			{
				cout << "INVALID INPUT!" << endl;
				cin.ignore(1000, '\n');
			}
		}
	}while(invalid);

	return intInput;
}

/******************************************************************************
* PROCESSING for CheckSexInput: Function reads in a character input  for sex
* 							    and checks that it is either 'm', 'M', 'f', 'F',
* 							    'x', or 'X'. Once a valid character for sex is
* 							    input, the function returns the valid character
* 							    input.
*******************************************************************************/
char CheckSexInput(string prompt, int promptWidth)
{
	char charInput;
	bool invalid;

	do
	{
		cout << left << setw(promptWidth) << prompt;
		cin.get(charInput);
		cin.ignore(1000, '\n');

		if(charInput != 'm' && charInput != 'M' &&
		   charInput != 'f' && charInput != 'F' &&
		   charInput != 'x' && charInput != 'X')
		{
			cout << "INVALID INPUT!" << endl;
			invalid = true;
		}
		else
		{
			invalid = false;
		}
	}while(invalid);

	return charInput;
}
