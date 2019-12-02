#include "unittests.hpp"

NodePtr loadDomStu()
{
	string line;
	ifstream File("domestic-stu.txt");

	NodePtr domStuHead = NULL;
	
	int stu_count = 0;
	
	if (!File.is_open()) {
		cout << "Unable to open file domestic-stu.txt" << endl;
		return NULL;
	}

	//Read the first line of domestic-stu.txt, which specifies
	//the file format. And then print it out to the screen
	getline(File, line);
	cout << "File format: " << line << endl << endl;

	 while (getline(File, line)) {
		 /*process each line, get each field separated by a comma.
		  *We use istringstream to handle it.
		  *Note in this example code here, we assume the file format
		  *is perfect and do NOT handle error cases. We will leave the
		  *error and exception handling of file format to Lab Assignment 4
		  */
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
			 return NULL;
		 }
		 else if (check2 == 0)
		 {
			 cout << d->getFirstName() << " "
				  << d->getLastName() << " "
				  << d->getProvince() 
				  << " The province is not valid!" << endl;
			 return NULL;
		 }
		 else
			 insert_node2(domStuHead, d);

		 stu_count++;
	 }
	 File.close();

	return domStuHead;
}


/*
 * *****NOTE:*****
 * all UNITSWITCH family of funtions work very similarly, they enter the user in
 * a switch statement that selects a specific linked list input depending on user input.
 * then each function calls their respective UNITTEST family of function, passing the linked list
 * as an arguement.
*/

void UNITSWITCH_outputStu()
{
	int input1, input2;
	
	do
	{

		cout << "Select Test Mode:" << endl
			 << "0: exit" << endl
			 << "1: By Application ID" << endl
			 << "2: By Name" << endl
			 << "3: By Research Score" << endl
			 << "4: By CGPA" << endl;
		
		cin >> input1;

		cout << "Select Linked List Mode:" << endl
			 << "1: Test with loaded students from text files" << endl
			 << "2: Test with only one student" << endl
			 << "3: Test with NULL list" << endl;

		cin >> input2;
		
		NodePtr head = new Node;
		student* testStu = new DomesticStudent;
		*testStu = DomesticStudent("Chris", "Rosenauer", 3.3, 80, "BC", 20200000);

		switch(input2)
		{
			case 0:
				break;

			case 1:
				head = loadDomStu();
				
				if(head == NULL)
				{
					cout << "Failed to load regular case linked list." << endl;
					break;
				}
				break;

			case 2:
				head->setLink(NULL);
				head->setData(testStu);
				break;

			case 3:
				head = NULL;
				break;

			default:
				break;
		}
		
		switch(input1)
		{
			case 0:
				break;
			case 1:
				genericPrint(head);
				UNITTEST_outputStuByNum(head);
				
				break;
			case 2:
				UNITTEST_outputStuByName(head);
				genericPrint(head);
				break;
			case 3:
				genericPrint(head);
				UNITTEST_outputStuByResScore(head);
				
				break;
			case 4:
				genericPrint(head);
				UNITTEST_outputStuByCGPA(head);
				break;
			default:
				break;
		}

		delete head;
	}
	while(input1 != 0);
}

void UNITSWITCH_removeHeadAndTail()
{
	int input;
	
	NodePtr head = new Node;
	NodePtr tail = new Node;
	student* testStu = new DomesticStudent;
	*testStu = DomesticStudent("Chris", "Rosenauer", 3.3, 80, "BC", 20200000);
	
	do
	{
		cout << "Select Test Mode:" << endl
			 << "0: exit" << endl
			 << "1: Test with loaded students from text file" << endl
			 << "2: Test with only one student" << endl
			 << "3: Test with empty linked list" << endl;

		cin >> input;

		switch(input)
		{
			case 0:
				break;

			case 1:
				head = loadDomStu();
				tail = find_tail(head);
				
				if(head == NULL)
				{
					cout << "Failed to load regular case linked list." << endl;
					break;
				}
				genericPrint(head);
				UNITTEST_removeHeadAndTail(head, tail);
				genericPrint(head);
				break;

			case 2:
				head->setLink(NULL);
				head->setData(testStu);
				tail = head;
				
				genericPrint(head);
				UNITTEST_removeHeadAndTail(head, tail);
				genericPrint(head);
				break;

			case 3:
				head = NULL;
				tail = NULL;

				genericPrint(head);
				UNITTEST_removeHeadAndTail(head, tail);
				genericPrint(head);
				break;

			default:
				break;
		}
	}
	while(input != 0);

	delete head;
	delete tail;
}

void UNITSWITCH_insertStudent()
{
	int input;
	
	NodePtr head = new Node;
	student* testStu = new DomesticStudent;
	*testStu = DomesticStudent("Chris", "Rosenauer", 3.3, 80, "BC", 20200000);
	
	testStu->print();

	do
	{
		cout << "Select Test Mode:" << endl
			 << "1: Test with loaded students from text file" << endl
			 << "2: Test with only one student" << endl
			 << "3: Test with empty linked list" << endl;

		cin >> input;

		switch(input)
		{
			case 0:
				break;

			case 1:
				head = loadDomStu();
				
				if(head == NULL)
				{
					cout << "Failed to load regular case linked list." << endl;
					break;
				}
				genericPrint(head);
				UNITTEST_insertStudent(head, testStu);
				genericPrint(head);
				
				break;

			case 2:
				head->setLink(NULL);
				head->setData(testStu);
				
				genericPrint(head);
				UNITTEST_insertStudent(head, testStu);
				genericPrint(head);
				break;

			case 3:
				head = NULL;
				genericPrint(head);
				UNITTEST_insertStudent(head, testStu);
				genericPrint(head);
				break;

			default:
				break;
		}
	}
	while(input != 0);

	delete head;
}


void UNITSWITCH_thresholdOutput()
{
	int input;
	
	NodePtr head = new Node;
	student* testStu = new DomesticStudent;
	*testStu = DomesticStudent("Chris", "Rosenauer", 3.3, 80, "BC", 20200000);

	do
	{
		cout << "Select Test Mode:" << endl
			 << "0: exit" << endl
			 << "1: Test with loaded students from text file" << endl
			 << "2: Test with only one student" << endl
			 << "3: Test with empty linked list" << endl;

		cin >> input;

		switch(input)
		{
			case 0:
				

				break;

			case 1:
				head = loadDomStu();

				if(head == NULL)
				{
					cout << "Failed to load regular case linked list." << endl;
					break;
				}
				UNITTEST_OUTPUT_threshholdOutput(head);
				
				break;

			case 2:
				head->setLink(NULL);
				head->setData(testStu);

				UNITTEST_OUTPUT_threshholdOutput(head);
				
				break;

			case 3:
				head = NULL;
				UNITTEST_OUTPUT_threshholdOutput(head);

				break;

			default:
				break;
		}
	}
	while(input != 0);

	delete head;
}

void UNITSWITCH_removeStudent()
{
	int input;
	
	student* testStu = new DomesticStudent;
	*testStu = DomesticStudent("Chris", "Rosenauer", 3.3, 80, "BC", 20200000);

	NodePtr head = new Node;
	string fName = "Chris";
	string lName = "Rosenauer";	

	do
	{
		cout << "Select Test Mode:" << endl
			 << "0: exit" << endl
			 << "1: Test with loaded students from text file" << endl
			 << "2: Test with only one student" << endl
			 << "3: Test with empty linked list" << endl;

		cin >> input;

		switch(input)
		{
			case 0:
				

				break;

			case 1:
				head = loadDomStu();

				if(head == NULL)
				{
					cout << "Failed to load regular case linked list." << endl;
					break;
				}
				genericPrint(head);
				UNITTEST_removeStudent(head);
				genericPrint(head);

				break;

			case 2:
				head->setLink(NULL);
				head->setData(testStu);
				
				genericPrint(head);
				UNITTEST_removeStudent(head);
				genericPrint(head);
				break;

			case 3:
				head = NULL;

				genericPrint(head);
				UNITTEST_removeStudent(head);
				genericPrint(head);

				break;

			default:
				break;
		}
	}
	while(input != 0);

	delete head;
}

void UNITSWITCH_mergeStudents()
{
	int input;
	
	student* testStu = new DomesticStudent;
	*testStu = DomesticStudent("Chris", "Rosenauer", 3.3, 80, "BC", 20200000);

	NodePtr head 	= new Node;
	NodePtr intHead = new Node;
	string fName 	= "Chris";
	string lName 	= "Rosenauer";	

	do
	{
		cout << "Select Test Mode:" << endl
			 << "0: exit" << endl
			 << "1: Test with loaded students from text file" << endl
			 << "2: Test with only one student" << endl
			 << "3: Test with empty linked list" << endl;

		cin >> input;

		switch(input)
		{
			case 0:
				

				break;

			case 1:
				head = loadDomStu();
				intHead = loadIntStu();

				if(head == NULL)
				{
					cout << "Failed to load regular case linked list." << endl;
					break;
				}
				UNITTEST_mergeStudents(head, intHead);
				
				break;

			case 2:
				head->setLink(NULL);
				head->setData(testStu);
				intHead->setLink(NULL);
				intHead->setData(testStu);

				UNITTEST_mergeStudents(head, intHead);
				
				break;

			case 3:
				head = NULL;
				intHead = NULL;
				UNITTEST_mergeStudents(head, intHead);

				break;

			default:
				break;
		}
	}
	while(input != 0);

	delete head;
}

/* *****NOTE*****
 * Each funciton in the UNITTEST family of functions tests a specific function with the inputted linked list.
 * Function is called by the UNITSWITCH family of functions for testing with a variety of linked list cases.
 * See UNITSWITCH documentation for more detail.
*/

void UNITTEST_outputStuByNum(NodePtr& head)
{

	outputStuByNum(head, 20200062);
}

void UNITTEST_outputStuByName(NodePtr& head)
{
	string fName = "Chris";
	string lName = "Rosenauer";
	outputStuByName(head, fName, lName);
}

void UNITTEST_outputStuByResScore(NodePtr& head)
{
	outputStuByResScore(head, 80);
}

void UNITTEST_outputStuByCGPA(NodePtr& head)
{
	outputStuByCGPA(head, 3.3);
}

void UNITTEST_removeHeadAndTail(NodePtr& head, NodePtr& tail)
{
	removeHeadAndTail(head, tail);
	print_linked_list1(head);
}

void UNITTEST_insertStudent(NodePtr& head, student* stu)
{
	insert_node2(head, stu);
	print_linked_list1(head);
}

void UNITTEST_mergeStudents(NodePtr& domHead, NodePtr& intHead)
{
	NodePtr mergedHead = sort_student(domHead, intHead);
	genericPrint(mergedHead);
}

void UNITTEST_OUTPUT_threshholdOutput(NodePtr& stuListHead)
{
	bool b = outputStuByThreshold(stuListHead, 3.3, 80);
}

void UNITTEST_removeStudent(NodePtr& head)
{
	string fn = "Chris";
	string ln = "Rosenauer";
	removeStudent(head, fn, ln);
}

NodePtr loadIntStu()
{
	string line;
	ifstream File("international-stu.txt");
	if (!File.is_open()) {
		cout << "Unable to open file international-stu.txt" << endl;
		return NULL;
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
	 */

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
		 *error and exception handling of file format to Lab Assignment 4
		 */

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
			return NULL;
		}
		else if (check2 == 0)
		{
			cout << i->getFirstName() << " " << i->getLastName() << " " << i->getCountry() << " The country is not valid!" << endl;
			return NULL;
		}
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

	return intStuHead;
}

