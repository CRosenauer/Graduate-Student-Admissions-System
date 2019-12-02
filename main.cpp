//main.cpp, put your driver code here, 
//you can manipulate your class objects here
#include <iostream> //cin and cout
#include <fstream> //file processing
#include <sstream> //formatted string processing
#include <cstdlib> //atof and atoi
#include "linkFunction.hpp"
#include "DomesticStudent.hpp"
#include "internationalStudent.hpp"
#include "nodeClass.hpp"
//#include "testLoad.hpp"
//#define debug

using namespace std;

/*I provide example code here to help you read the input
 *data from a file, so that you can focus on creating
 *and manipulating classes and objects
 */

int main()
{
	//Read the international-stu.txt file and exit if failed
	string line;
	ifstream File("international-stu.txt");
	if (!File.is_open()) {
		cout << "Unable to open file international-stu.txt" << endl;
		return -1;
	}

	//Read the first line of domestic-stu.txt, which specifies
	//the file format. And then print it out to the screen
	getline(File, line);
	cout << "File format: " << line << endl << endl;

	/*Keep reading the rest of the lines in domestic-stu.txt.
	 *In the example code here, I will read each data separated
	 *by a comma, and then print it out to the screen.
	 *In your lab assignment 1, you should use these read data
	 *to initialize your DomesticStudent object. Then you can
	 *use get and set functions to manipulate your object, and
	 *print the object content to the screen
	 //*/

	//const int STULIST = 100;

	int stu_count = 0;

	/*internationalStudent intStuList[STULIST];
	DomesticStudent      domStuList[STULIST];*/

	NodePtr intStuHead = NULL;

	while (getline(File, line)) {
		/*process each line, get each field separated by a comma.
		 *We use istringstream to handle it.
		 *Note in this example code here, we assume the file format
		 *is perfect and do NOT handle error cases. We will leave the
		 *error and exception handling of file format to Lab Assignment 4*/
		 

		istringstream ss(line);

		string firstName, lastName, country, s_cgpa, s_researchScore, s_reading, s_listening, s_speaking, s_writing;
		float cgpa;
		int researchScore;
		int reading;
		int listening;
		int speaking;
		int writing;

		//get firstName separated by comma
		getline(ss, firstName, ',');

		//get lastName separated by comma
		getline(ss, lastName, ',');

		//get country separated by comma
		getline(ss, country, ',');

		//get cpga separated by comma, and convert string to float
		getline(ss, s_cgpa, ',');
		cgpa = atof(s_cgpa.c_str());

		//get researchScore separated by comma, and convert it to int
		getline(ss, s_researchScore, ',');
		researchScore = atoi(s_researchScore.c_str());

		//get reading separated by comma, and convert it to int
		getline(ss, s_reading, ',');
		reading = atoi(s_reading.c_str());

		//get listening separated by comma, and convert it to int
		getline(ss, s_listening, ',');
		listening = atoi(s_listening.c_str());

		//get speaking separated by comma, and convert it to int
		getline(ss, s_speaking, ',');
		speaking = atoi(s_speaking.c_str());

		//get writing separated by comma, and convert it to int
		getline(ss, s_writing);
		writing = atoi(s_writing.c_str());

		internationalStudent* i = new internationalStudent;
		i->set(firstName, lastName, cgpa, researchScore, stu_count + 20200000,
			reading, writing, listening, speaking);
		i->setCountry(country);
		bool check1 = CheckOutField2(i);
		bool check2 = CheckCountry(i);
		if (check1 == 0)
		{
			i->print();
			cout << "\t" << "There are some fields missing!" << endl;
			return 0;
		}
		else if (check2 == 0)
		{
			cout << i->getFirstName() << " " << i->getLastName() << " " << i->getCountry() << " The country is not valid!" << endl;
			return 0;
		}
                //Check if there is anything wrong with the information of the international student
		else
		{
			if (i->getReading() + i->getWriting() + i->getListening() + i->getSpeaking() >= 93
				&& i->getReading() >= 20
				&& i->getWriting() >= 20
				&& i->getListening() >= 20
				&& i->getSpeaking() >= 20)
			{
				insert_node1(intStuHead, i);
			}
			else
				continue;
		}

		stu_count++;
	}

	File.close();

	//print_linked_list1(intStuHead);
	//cout << endl;

	NodePtr intStuTail = NULL;
	find_tail(intStuTail, intStuHead);

	File.open("domestic-stu.txt");

	if (!File.is_open()) {
		cout << "Unable to open file domestic-stu.txt" << endl;
		return -1;
	}

	//Read the first line of domestic-stu.txt, which specifies
	//the file format. And then print it out to the screen
	getline(File, line);
	cout << "File format: " << line << endl << endl;

	/*Keep reading the rest of the lines in domestic-stu.txt.
	 *In the example code here, I will read each data separated
	 *by a comma, and then print it out to the screen.
	 *In your lab assignment 1, you should use these read data
	 *to initialize your DomesticStudent object. Then you can
	 *use get and set functions to manipulate your object, and
	 *print the object content to the screen*/
	 

	 NodePtr domStuHead = NULL;


	 
	 while (getline(File, line)) {
		 /*process each line, get each field separated by a comma.
		  *We use istringstream to handle it.
		  *Note in this example code here, we assume the file format
		  *is perfect and do NOT handle error cases. We will leave the
		  *error and exception handling of file format to Lab Assignment 4*/
		  
		 istringstream ss(line);

		 string firstName, lastName, province, s_cgpa, s_researchScore;
		 float cgpa;
		 int researchScore;

		 //get firstName separated by comma
		 getline(ss, firstName, ',');

		 //get lastName separated by comma
		 getline(ss, lastName, ',');

		 //get province separated by comma
		 getline(ss, province, ',');

		 //get cpga separated by comma, and convert string to float
		 getline(ss, s_cgpa, ',');
		 cgpa = atof(s_cgpa.c_str());

		 //get researchScore separated by comma, and convert it to int
		 getline(ss, s_researchScore, ',');
		 researchScore = atoi(s_researchScore.c_str());

		 DomesticStudent* d = new DomesticStudent;
		 d->set(firstName, lastName, cgpa, researchScore, province, stu_count + 20200000);
		 bool check2 = CheckProvince(d);
		 bool check1 = CheckOutField1(d);
		 if (check1 == 0)
		 {
			 d->print();
			 cout << "\t" << "There are some fields missing!" << endl;
			 return 0;
		 }
		 else if (check2 == 0)
		 {
			 cout << d->getFirstName() << " " << d->getLastName() << " " << d->getProvince() << " The province is not valid!" << endl;
			 return 0;
		 }
                 //Check if there is anything wrong with the information of the domestic student
		 else
			 insert_node2(domStuHead, d);

		 stu_count++;
	 }
	 File.close();

	NodePtr domStuTail = NULL;
	find_tail(domStuTail, domStuHead);

	char input;

	NodePtr allStuHead = NULL;
	
	//seperate international and domestic student loop.
	do
  	{
		cout << "Commands:" << endl
		     << "h: help" << endl
		     << "o: output students" << endl
             << "s: search students" << endl
		     << "d: delete student" << endl
		     << "i: insert student" << endl
		     << "r: remove head and tail students" << endl
		     << "m: merge students" << endl
		     << "q: quit" << endl;
		   
	  	cin >> input;

	  	if(input == 'h') //help
	  	{
		 	;
			//does nothing and re-enters loop, outputting command list again
	  	}
	  	else if(input == 'o') //output students
	  	{
		  	char newInput;
		  
		  	cout << "Which student set to show?" << endl
			     << "d: domestic students" << endl
			     << "i: international students" << endl;
		  
		  	cin >> newInput;
			
			if (newInput == 'd')
			{
				cout << "Domestic Student:" << endl;
				print_linked_list1(domStuHead);
			}
			else if (newInput == 'i')
			{
				cout << "International Student:" << endl;
				print_linked_list2(intStuHead);
			}
		   	else
		   	{
			   	cout << "Invalid input." << endl;
		   	}
	  	}
	   	else if(input == 's') //search students
	  	{
			char nChar;
			cout << "How do you want to search student?" << endl;
			cout << "a: Application ID" << endl
				 << "c: CGPA" << endl
			 	 << "r: Research Score" << endl
				 << "n: First and Last Name" << endl;
			cin >> nChar;

			if(nChar == 'a') //by app id
			{
				int id;
				cout << "Insert application ID:" << endl;
				cin >> id;
				cout << "Domestic Student:" << endl;
				outputStuByNum(domStuHead, id);
				cout << endl;
				cout << "International Student:" << endl;
				outputStuByNum(intStuHead, id);
			}
			else if(nChar == 'c') //by cgpa
			{
				float cgpa;
				cout << "Insert CGPA:" << endl;

				cin >> cgpa;
				cout << "Domestic Student:" << endl;
				outputStuByCGPA(domStuHead, cgpa);
				cout << endl;
				cout << "International Student:" << endl;
				outputStuByCGPA(intStuHead, cgpa);
			}
			else if(nChar == 'r') //by research score
			{
				int rs;
				cout << "Insert research score:" << endl;
				cin >> rs;
				cout << "Domestic Student:" << endl;
				outputStuByResScore(domStuHead, rs);
				cout << endl;
				cout << "International Student:" << endl;
				outputStuByResScore(intStuHead, rs);
			}
			else if(nChar == 'n')//by first and last name
			{
				string fName, lName;
				cout << "Insert first name:" << endl;
				cin >> fName;
				cout << "Insert last name:" << endl;
				cin >> lName;
				//cout << fName;
				//cout << lName;
				cout << "Domestic Student:" << endl;
				outputStuByName(domStuHead, fName, lName);
				cout << endl;
				cout << "International Student:" << endl;
				outputStuByName(intStuHead, fName, lName);
			}
			else
				cout << "Invalid Input" << endl;
	  }
	  else if(input == 'd') // delete student
	  {
			string fName, lName;
	    	cout << "Insert first name of student to be deleted:" << endl;
			cin >> fName;
			cout << "Insert last name of student to be deleted:" << endl;
			cin >> lName;
			
			bool domStuRemoved = removeStudent(domStuHead, fName, lName);
			bool intStuRemoved = removeStudent(intStuHead, fName, lName);
			
			if (domStuRemoved == 1 || intStuRemoved == 1)
				cout << "Students with specified name removed." << endl;
			else
				cout << "Could not remove students with specified name." << endl
					 << "Student may have already been removed or the student's name is wrong." << endl;
      }
	  else if(input == 'i') // insert student
	  {
		  	char nChar = 'n';
		  	cout << "Insert a domestic or international student?" << endl;
		  
		  	cout << "d: domestic student" << endl
              	         << "i: international student" << endl;
		  	cin >> nChar;

			if(nChar == 'd') //domestic student
			{
				string fname, lname, province;
				float cgpa;
				int resscore;
				DomesticStudent* d = new DomesticStudent;
				cout << "Insert student first name: " << endl;
				cin >> fname;
				cout << "Insert student last name: " << endl;
				cin >> lname;
				cout << "Insert student cgpa:" << endl;
				cin >> cgpa;
				cout << "Insert student research score:" << endl;	
				cin >> resscore;
				cout << "Insert student province:" << endl;
				cin >> province;

				*d = DomesticStudent(fname, lname, cgpa, resscore, province, stu_count + 20200000);
				bool check = CheckProvince(d);
				if (check == 1)
				{
					insert_node2(domStuHead, d);
					stu_count++;
					cout << "Student inserted into linked list." << endl;
				}
				else
				{
					d->print();
					cout << "\t The province is not valid!" << endl;
				}
                                //check out if the province of this student is valid.
			}
			else if(nChar == 'i')//international student
			{
				string fname, lname, country;
				float cgpa;
				int resscore, read, write, listen, speak;
				internationalStudent* i = new internationalStudent;
				cout << "Insert student first name: " << endl;
				cin >> fname;
				cout << "Insert student last name: " << endl;
				cin >> lname;
				cout << "Insert student cgpa:" << endl;
				cin >> cgpa;
				cout << "Insert student research score:" << endl;	
				cin >> resscore;
				cout << "Insert student country:" << endl;
				cin >> country;
				cout << "Insert TOEFL Score reading component:" << endl;
				cin >> read;
				cout << "Insert TOEFL Score writing component:" << endl;
				cin >> write;
				cout << "Insert TOEFL Score listening component:" << endl;
				cin >> listen;
				cout << "Insert TOEFL Score speaking component:" << endl;
				cin >> speak;

				*i = internationalStudent(fname, lname, country, cgpa, resscore, stu_count + 20200000, read, write, listen, speak);
				bool check = CheckCountry(i);
				if (check)
				{
					insert_node1(intStuHead, i);
					stu_count++;
					cout << "Student inserted into linked list." << endl;
				}
				else
				{
					i->print();
					cout << "\t The country is not valid!" << endl;
				}
				//check out if the country of this student is valid.
			}
			else
				cout << "Invalid input." << endl;

	  }
	  else if(input == 'r')
	  {
			char nChar;
			cout << "Which students lists do you want to remove the head and tail from?" << endl;
			cout << "d: domestic student list" << endl
				 << "i: international studenet list" << endl
		         << "b: both student lists" << endl;

			cin >> nChar;

			if(nChar == 'd')
			{
				removeHeadAndTail(domStuHead, domStuTail);
			}
			else if(nChar == 'i')
			{
				removeHeadAndTail(intStuHead, intStuTail);
			}
			else if(nChar == 'b')
			{
				removeHeadAndTail(domStuHead, domStuTail);
				removeHeadAndTail(intStuHead, intStuTail);
			}
			else
				cout << "Invalid input." << endl;
 	  }
	  else if(input == 'm')//merge student lists
      {
			allStuHead = sort_student(domStuHead, intStuHead);
			cout << "Domestic and International Students mereged." << endl
			     << "Switching to merged list command List." << endl;
      }
	  else if(input == 'q') // quit
	  {
		break;
	  }
	  else
	  {
		  cout << "Unknown command. input 'h' for a list of commands." << endl;
	  }
  }
  while(input != 'q' && input != 'm');
	
	
	//All student loop. Only accessed if students are merged.
	if(input == 'm')
	{
		do
		{
			cout << "Commands:" << endl
		   	 	 << "h: help" << endl
				 << "o: output students with requirement threshold" << endl
		    	 << "q: quit" << endl;
		   
	  		cin >> input;

	  		if(input == 'h') //help
	  		{
				;
	  		}
			if(input == 'o')//output by threshold requirements
			{
				float cgpa_threshold;
				int   researchScore_threshold;

				//input threshold requirements
				cout << "Input CGPA threshold:" << endl;
				cin >> cgpa_threshold;
				cout << "Input Research Score threshold" << endl;
				cin >> researchScore_threshold;
				
				
				//output students who meet or surpass threshold requirements
				if(!outputStuByThreshold(allStuHead, cgpa_threshold, researchScore_threshold))
				{
					cout << "Failed to output students who met the inputted thresholds." << endl
						 << "The linked list is empty or no students met requirements." << endl;
				}
				else
				{
					cout << "Students who met threshold requirements successfully outputted." << endl;
				}
			}
			if(input == 'q')
			{
				break;
			}
		}
		while(input != 'q');
	}

	return 0;
}
