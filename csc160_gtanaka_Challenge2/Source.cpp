#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

// function prototypes
int getCreditHours();
int selectCourseLevel();
double rateFromCourseLevel(int);
void outputYearlyTuition(double, int, int);
double calculateYearlyTuition(int, double, int);

// constant file location so it is easy to update
const string TUITION_FILE = ".\\tuitionAmounts.txt";
const string OUTPUT_FILE  = ".\\TuitionReportResults.txt";

int main() 
{
// declare vars
	int creditHours;
	int courseLevelSelection;
	double ratePerCreditHour = 0.0;

// get credit hours from user
	creditHours = getCreditHours();

// get course level from user (this also displays menu)
	courseLevelSelection = selectCourseLevel();
	//cout << endl << courseLevelSelection << endl;
	ratePerCreditHour = rateFromCourseLevel(courseLevelSelection);

	//cout << ratePerCreditHour;

// loop to display tuition this yr and next 5
	outputYearlyTuition(ratePerCreditHour, creditHours, courseLevelSelection);
	
// output to text file

	system("pause");
	return 0;
}

/**
	Purpose: get and validate the user's number of credit hours this semester
	@return integer number of credit hours
*/
int getCreditHours()
{
	int entry;
	bool isValid = false;
	while (!isValid)
	{
		cout << "How many credit hours are you taking this semester? ";
		cin >> entry;
		// validate that the entry is not negative
		if (entry >= 0 && !cin.fail())
			isValid = true;
		else
		{
			cout << "Invalid selection! Please select a non-negative integer." << endl;
			cin.clear();
		}
	}
	
	return entry;
}

/**
	Purpose: builds a menu of course levels read from the associated file. Only
		a single course level can be displayed at a time. Once the user indicates
		that a selection has been made, the selection is returned.
	@return an integer to represent the course level
*/
int selectCourseLevel()
{
	// declare function vars
	std::ifstream infile;
	infile.open(TUITION_FILE);
	char entry = 'N';
	int count = 0;
	string line;

	// For consistancy in the appearance of the menu, clear the screen first.
	system("cls");

	while (toupper(entry) != 'Y')
	{
		cout << "Please select a course level. Enter Y to make your selection," <<
			"press any key to cycle to the next option. " << endl;
		getline(infile, line);
		if (!line.empty())
		{
			cout << "Course level " << count << "00 - Price: ";
			cout << line << ": ";
		}
		else
			cout << "Reached end of file! Hit any key to return to the top";
		//cin.ignore(1, '\n');
		cin.get(entry);
		// if the end of the file has been reached, do not allow a selection, 
		// reset the filestream to the begining
		if (infile.eof()) {
			entry = 'n';
			infile.clear();
			infile.seekg(0, infile.beg);
			count = 0;
		}
		// if the end of the file has not been reached, but no valid selection
		// has been made, then increment the counter and move to the next line
		else if (toupper(entry) != 'Y')
		{
			++count;
		}
		// break out of loop if a selection is made
		else
		{
			break;
		}
		if (toupper(entry) != 'Y')
			system("CLS"); // This is generally not considered great practice, and will likely ONLY work on Windows OS.
	}
	// clean up
	infile.close();

	// an alternate version of this program might convert the value stored in 
	// line to a double, and return that, thus eliminating the need for 
	// rateFromCourseLevel() and the use of a switch statement
	return count;
}

/**
	Purpose: use a switch statement to evaluate the level chosen
	@param int The user's chosen course level
	@return double The rate per credit hour for the chosen level
*/
double rateFromCourseLevel(int courseLevel)
{
	std::ifstream infile;
	infile.open(TUITION_FILE);
	double rate;
	// based on the user selection, read the appropriate rate from the file
	switch (courseLevel) {
	case 0:
		infile >> rate;
		break;
	case 1:
		infile.ignore(1000, '\n');
		//getline(infile, line);
		infile >> rate;
		break;
	case 2:
		for (int i = 0; i < 2; ++i)
		{
			infile.ignore(1000, '\n');
		}
		//getline(infile, line);
		infile >> rate;
		break;
	default:
		rate = 0.0;
	}
	//rate = line
	return rate;
}

/**
	Purpose: format and output the table for the tuition amounts using a loop.
	@param rate The cost per credit hour each semester
	@param hours The number of credit hours the student is registered for
	@param level The level of courses the student is taking
*/
void outputYearlyTuition(double rate, int hours, int level)
{
	// declare function vars
	double yearlyTuition;
	string timeFrame;
	string outStr;
	std::ofstream outfile;
	outfile.open(OUTPUT_FILE);

	cout << std::fixed << std::showpoint << std::setprecision(2);
	outfile << std::fixed << std::showpoint << std::setprecision(2);

	// build header
	/*This is not very dry, as each out stream is duplicated. Initially I
	wanted to pass an output stream as a parameter to this function, 
	however I was unsucessful in making such a dynamic output stream 
	work correctly.*/
	cout << "Community College of Aurora Tuition Report\n";
	outfile << "Community College of Aurora Tuition Report\n";
	cout << "\tLevel " << level << "00" << endl;
	outfile << "\tLevel " << level << "00" << endl;
	cout << "---------------------------------------------\n";
	outfile << "---------------------------------------------\n";
	cout << "Year\t\t\tTuition\n";
	outfile << "Year\t\t\tTuition\n";
	cout << "-----\t\t\t-------\n";
	outfile << "-----\t\t\t-------\n";

	// call calculate method
	for (int i = 0; i < 6; ++i)
	{
		yearlyTuition = calculateYearlyTuition(i, rate, hours);
		cout << "Year " << i + 1 << "\t\t\t$" << yearlyTuition << endl;
		outfile << "Year " << i + 1 << "\t\t\t$" << yearlyTuition << endl;
	}

	// cleanup
	outfile.close();
}

/**
	Purpose: calculate the tuition for a provided set of details
	@param year This indicates the number of years after the initial enrollment
		and is used to calculate a 2% per year rate of inflation
	@param rate This is the cost per credit hour, dictated by the level of
		courses the student has selected prior in the program
	@param creditHours The number of credit hours the student has enrolled in
*/
double calculateYearlyTuition(int year, double rate, int creditHours)
{
	double semesterTuition = rate * creditHours;
	double yearlyTuition = semesterTuition * 2;
	yearlyTuition += yearlyTuition * (0.02 * year);

	return yearlyTuition;
}