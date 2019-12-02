#include <iostream> //cin and cout
#include <fstream> //file processing
#include <sstream> //formatted string processing
#include <cstdlib> //atof and atoi
#include "linkFunction.hpp"
#include "DomesticStudent.hpp"
#include "internationalStudent.hpp"
#include "nodeClass.hpp"
#include "unittests.hpp"


int main()
{
	int input;
	
	do
	{
		cout << "Select Test Mode:" << endl
			 << "0: exit" << endl
			 << "1: outputStu" << endl 			//2, 3
			 << "2: removeHeadAndTail" << endl 	//5
			 << "3: insertStudent" << endl 		//1
			 << "4: thresholdOutput" << endl	//7
			 << "5: removeStudent" << endl		//4
			 << "6: mergeStudents" << endl;		//6

		cin >> input;


		//switch statement to determine which function will be tested.
		switch(input)
		{
			case 0:
				break;
			case 1:
				UNITSWITCH_outputStu();
				break;
			case 2:
				UNITSWITCH_removeHeadAndTail();
				break;
			case 3:
				UNITSWITCH_insertStudent();
				break;
			case 4:
				UNITSWITCH_thresholdOutput();
				break;
			case 5:
				UNITSWITCH_removeStudent();
				break;
			case 6:
				UNITSWITCH_mergeStudents();
				break;
			default:
				break;
		}
	}
	while(input != 0);

	return 0;
}
