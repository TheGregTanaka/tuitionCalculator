# tuitionCalculator
## Overview

The Community College of Aurora is proposing a new cost structure for its courses. The plan is to charge a higher cost for higher level courses in order to hiring highly skilled instructors for those courses. The course levels are as follows:

000 Level Courses - $178.25 / hour
100 Level Courses - $232.42 / hour
200 Level Courses - $274.41 / hour
This new plan also includes a 2 percent per year cost increase for each level over the course of the next five years to bring the college closer to the national average.

## Instructions

Design a program that first asks the user the number of credit hours they plan to take in one semester.  Use this number to calculate the present semester tuition. The program should then display a menu that asks the user which course level to display in the report. (Note that only one course level can be displayed at a time!). Once the course level is selected, the program MUST use the per credit hour cost listed in the attached text file called tuitionAmounts.txt. Therefore, the initial tuition amounts must be read into the program from the text file and not hard-coded with the program. This allows the initial amounts to be changed in the text file an not in the code.

After the tuition amounts are read, then display the tuition for the level selected for the year by multiplying the semester tuition by 2.  Next, create a loop that displays the projected yearly tuition amounts for the next five years.  Therefore, the program should display 6 years of tuition with the first year representing the present tuition costs and the subsequent years representing a 2 percent increase each year.

Your output results should be in table format and should resemble the following if the user selected 000 Level Courses:

```
Community College of Aurora Tuition Report
            Level 000
---------------------------------------------
Year                        Tuition
-----                       -------
Year 1	                    $xxx.xx
Year 2	                    $xxx.xx
Year 3	                    $xxx.xx
Year 4	                    $xxx.xx
Year 5	                    $xxx.xx
Year 6	                    $xxx.xx
```
### Additional Requirements

 * You MUST use a loop to display years 2 through 6, which have the percent increase.
 * You Must use a switch statement to evaluate the level chosen
 * The program must loop and can only be exited by making a selection in the menu
 * The output results must be written to a new text file called TuitionReportResults.txt.

### Submitting Your Assignment

First remember that all assignments MUST follow this course's assignment naming convention. Each filename must begin with the course ID, followed by your first initial and last name, then ends with the name of the assignment (a name you would choose.) For example, CSC119_khoward_Challenge2.  Failure to properly name your assignment may result in points being deducted from your grade. When submitting your Python Visual Studio assignment, you must submit the ENTIRE Visual Studio solution folder.  To do this, follow these instructions:

Locate the Solution Folder (not the file) for your application. (Note that inside of your solution folder may be another folder with the same name that holds your files. DO NOT only submit this folder. Submit the outside solution folder so that the .sln file is included.)
Right click on the solution folder and select SEND TO >> Compressed Zipped File.
Submit the zipped folder
