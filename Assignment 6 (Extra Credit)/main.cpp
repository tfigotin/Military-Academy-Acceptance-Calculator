/******************************************************************************
* PROGRAMMED BY : Tamar Figotin
* CLASS         : CS1A
* SECTION       : TTh: 11am
* ASSIGNMENT #6 : Boolean Expressions - Military Academy
*******************************************************************************/

#include <iostream> /* cout, cin          */
#include <iomanip>  /* setw, setprecision */
#include <string>   /* string             */
#include "MyHeader.h"
using namespace std;

/******************************************************************************
 * Boolean Expressions - Military Academy
 * ----------------------------------------------------------------------------
 * This program selects Military Academy candidates based on sex, height, and
 * 		weight. The program reads in a set a data for each candidate applying
 * 		including their:
 * 		- sex    : sex of candidate (M/m or F/f)
 * 		- height : height of the candidate (in inches)
 * 		- weight : weight of candidate (in pounds)
 *
 * Then, it determines and informs the user of the acceptance status of each
 * 		candidate applying based on the qualifications stated below:
 *
 * 	Sex:     Min. Height:   Max. Height:    Min.Weight:    Max. Weight:
 *	Male     65 in.         80 in.          130 lbs.       250 lbs.
 *	Female   62 in. 7       5 in.           110 lbs.       185 lbs.
 *
 * Once status for each candidate is determined and output, the user types in
 * 		'x' or 'X' to output the number of candidates accepted, as well as
 * 		the percentage accepted from the pool of candidates.
 * ----------------------------------------------------------------------------
 * INPUT:
 *     sex      : gender of the candidate (male or female)
 *     weight   : weight of the candidate (in pounds)
 *     height   : height of the candidate (in inched)
 *
 * OUTPUT:
 *     accectanceStatus : whether or not the candidate was accepted
 *     acceptedCount    : number of candidates accepted from ones that applied
 *     percentAccepted  : percentage of candidates accepted from ones that
 *     						applied
 *
 * ----------------------------------------------------------------------------
 * 		EXAMPLE INPUT / OUTPUT:
 *
 *	Please enter the candidate’s information (enter ‘X’ to exit).
 *	Sex:    m
 *	Height: 80
 *	Weight: 130
 *
 *	This candidate has been ACCEPTED!
 *
 *
 *	Please enter the candidate’s information (enter ‘X’ to exit).
 *	Sex:    m
 *	Height: 65
 *	Weight: 250
 *
 *	This candidate has been ACCEPTED!
 *
 *
 *	Please enter the candidate’s information (enter ‘X’ to exit).
 *	Sex:    f
 *	Height: 62
 *	Weight: 109
 *
 *	This candidate has been rejected based on the weight requirement.
 *
 *
 *	Please enter the candidate’s information (enter ‘X’ to exit).
 *	Sex:    x
 *
 *	2 candidate(s) accepted!
 *	That's 67%!
 *
 *
 ******************************************************************************/
int CheckIntInput(string prompt, int minRange, int maxRange, int promptWidth);

char CheckSexInput(string prompt, int promptWidth);

int main()
{
	/*************************************************************************
	 * CONSTANTS
	 * -----------------------------------------------------------------------
	 * OUTPUT - USED FOR CLASS HEADING
	 * -----------------------------------------------------------------------
	 * PROGRAMMER  : Programmer's Name
	 * CLASS       : Student's Course
	 * SECTION     : Class Day and Times
	 * ASSIGN_NUM  : Assignment Number (specific to this assignment)
	 * ASSIGN_NAME : Title of the Assignment
	 * -----------------------------------------------------------------------
	 * FORMATTING - USED FOR SETWS
	 * -----------------------------------------------------------------------
	 * PROMPT_COL : prompt column width
	 * -----------------------------------------------------------------------
	 * REQUIREMENTS - MIN AND MAX HEIGHT/WEIGHT FOR MALE
	 * -----------------------------------------------------------------------
	 * MIN_MALE_HEIGHT : minimum height for males to be accepted
	 * MAX_MALE_HEIGHT : maximum height for males to be accepted
	 * MIN_MALE_WEIGHT : minimum weight for males to be accepted
	 * MAX_MALE_WEIGHT : maximum weight for males to be accepted
	 * -----------------------------------------------------------------------
	 * REQUIREMENTS - MIN AND MAX HEIGHT/WEIGHT FOR FEMALE
	 * -----------------------------------------------------------------------
	 * MIN_FEM_HEIGHT : minimum height for females to be accepted
	 * MAX_FEM_HEIGHT : maximum height for females to be accepted
	 * MIN_FEM_WEIGHT : minimum weight for females to be accepted
	 * MAX_FEM_WEIGHT : maximum weight for females to be accepted
	 * ------------------------------------------------------------------------
	 * OUTPUT - USED FOR ACCEPTANCE STATUS
	 * ------------------------------------------------------------------------
	 * SENTENCE        : general statement before the acceptance status
	 * ACCEPTED        : statement for if the candidate is accepted
	 * REJECTED_HEIGHT : statement for if the candidate is rejected based on
	 * 						height requirements
	 * REJECTED_WEIGHT : statement for if the candidate is rejected based on
	 * 						weight requirements
	 * REJECTED_BOTH   : statement for if the candidate is rejected based on
	 * 						height and weight requirements
	 *
	 *************************************************************************/

	// FORMATTING - USED FOR SETWS
	const int PROMPT_COL = 10;

	// REQUIREMENTS - MIN AND MAX HEIGHT/WEIGHT FOR MALE
	const int MIN_MALE_HEIGHT = 65;
	const int MAX_MALE_HEIGHT = 80;
	const int MIN_MALE_WEIGHT = 130;
	const int MAX_MALE_WEIGHT = 250;

	// REQUIREMENTS - MIN AND MAX HEIGHT/WEIGHT FOR FEMALE
	const int MIN_FEM_HEIGHT = 62;
	const int MAX_FEM_HEIGHT = 75;
	const int MIN_FEM_WEIGHT = 110;
	const int MAX_FEM_WEIGHT = 185;

	// OUTPUT - USED FOR ACCEPTANCE STATUS
	const string SENTENCE        = "This candidate has been ";
	const string ACCEPTED        = "ACCEPTED!";
	const string REJECTED_HEIGHT = "rejected based on the HEIGHT requirement.";
	const string REJECTED_WEIGHT = "rejected based on the WEIGHT requirement.";
	const string REJECTED_BOTH   = "rejected based on the HEIGHT and WEIGHT "
										"requirement.";

	// CHECK INPUT
	const int MIN_HEIGHT_RANGE = 24;
	const int MAX_HEIGHT_RANGE = 110;
	const int MIN_WEIGHT_RANGE = 50;
	const int MAX_WEIGHT_RANGE = 1400;

	/**************************************************************************
	 * VARIABLES
	 *************************************************************************/
	char  sex;              // IN   - sex of candidate (m, M, f, or F)
	int   height;           // IN   - height of candidate (in inches)
	int   weight;           // IN   - weight of candidate (in pounds)
	int   candidateCount;   // CALC - number of candidates entered
	bool  acceptableHeight; // CALC - whether or not candidate's height meets
              				// 			military academy requirements
	bool  acceptableWeight; // CALC - whether or not candidate's weight meets
						    //          military academy requirements
	int   acceptedCount;    // CALC & OUT - number of accepted candidates
	float percentAccepted;  // CALC & OUT - percent accepted from those entered
	string acceptanceStatus;

	/**************************************************************************
	* OUTPUT - Class Heading
	**************************************************************************/
	OutputClassHeading("Boolean Expressions - Military Academy", 6, 'A');
	/*************************************************************************/

	/*************************************************************************
	 * INPUT - Input the sex of the candidate
	 *************************************************************************/

	cout << "Please enter the candidate's information (enter 'X' to exit).";
	cout << endl;

	sex = CheckSexInput("Sex:", PROMPT_COL);

	cout << right;

	// INITIALIZATIONS
	candidateCount = 0;
	acceptedCount  = 0;

	/*************************************************************************
	 * PROCESSING - Determines eligibility of each candidate until 'X' or 'x'
	 * 				is entered. This is the primary loop of the program. If
	 * 				the user enters a valid sex it will then prompt for height
	 * 				and weight and with that information will determine if the
	 * 				candidate is accepted to enter the military academy.
	 *************************************************************************/

	// WHILE - enter while loop
	while(sex != 'X' && sex != 'x')
	{
		// INPUT - height and weight
		cout << left;

		height = CheckIntInput("Height:", MIN_HEIGHT_RANGE,
							MAX_HEIGHT_RANGE, PROMPT_COL);

		weight = CheckIntInput("Weight:", MIN_WEIGHT_RANGE,
							MAX_WEIGHT_RANGE, PROMPT_COL);
		cin.ignore(1000, '\n');

		cout << right;

		// PROCESSING - checks in height is an acceptable height
		acceptableHeight = ((sex == 'm' || sex == 'M') &&
				   (height >= MIN_MALE_HEIGHT && height <= MAX_MALE_HEIGHT)) ||
						   ((sex == 'f' || sex == 'F') &&
				   (height >= MIN_FEM_HEIGHT && height <= MAX_FEM_HEIGHT));

		// PROCESSING - checks in weight is an acceptable weight
		acceptableWeight = ((sex == 'm' || sex == 'M') &&
				   (weight >= MIN_MALE_WEIGHT && weight <= MAX_MALE_WEIGHT)) ||
						   ((sex == 'f' || sex == 'F') &&
				   (weight >= MIN_FEM_WEIGHT && weight <= MAX_FEM_WEIGHT));

		// INCREMENT
		candidateCount++;


		// PROC - assign acceptance status
		if(acceptableHeight && acceptableWeight)
		{
			acceptedCount++;
			acceptanceStatus = ACCEPTED;
		}
		else if(!acceptableHeight && !acceptableWeight)
		{
			acceptanceStatus = REJECTED_BOTH;
		}
		else if(!acceptableHeight)
		{
			acceptanceStatus = REJECTED_HEIGHT;
		}
		else
		{
			acceptanceStatus = REJECTED_WEIGHT;
		}

		// OUTPUT - acceptance status
		cout << endl << SENTENCE;
		cout << acceptanceStatus;

		// INPUT - sex of next candidate (in loop)
		cout << endl << endl << endl;
		cout << "Please enter the candidate's information (enter 'X' to exit).";
		cout << endl;

		sex = CheckSexInput("Sex:", PROMPT_COL);

		cout << right;

	} // END - while

	cout << endl;

	/**************************************************************************
	* OUTPUT - Number of candidates accepeted and percentage of accepted
	* 		   candidates out of those that were entered.
	**************************************************************************/

	// Check for divide by zero error
	if(candidateCount>0)
	{
		// CALC - percentage of candidates accepted
		percentAccepted = (acceptedCount / float(candidateCount)) * 100;

		// OUTPUT - proper plurality and number of candidates accepted
		if(acceptedCount == 1)
		{
			cout << acceptedCount << " candidate accepted!";
		}
		else
		{
			cout << acceptedCount << " candidate(s) accepted!";
			cout << endl;
		}

		// OUTPUT - percentage of candidates accepted
		cout << "That's " << setprecision(2) << percentAccepted << "%!";

	}
	return 0;
}

