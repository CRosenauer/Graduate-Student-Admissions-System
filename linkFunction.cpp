#ifndef LINKFUNCTION_CPP
#define LINKFUNCTION_CPP

#include "linkFunction.hpp"


void head_insert(NodePtr& h, studentPtr d)
{
	NodePtr temp = new Node();
	temp->setData(d);
	temp->setLink(h);
	h = temp;
}

void tail_insert(NodePtr& h, studentPtr d)
{
	if (h == NULL)
	{
		cout << "Empty Linked List. Nothing to print." << endl;
		return;
	}
	else
	{
		NodePtr n1 = h;
		while (n1->getLink() != NULL)
			n1 = n1->getLink();
		NodePtr temp = new Node();
		temp->setLink(NULL);
		temp->setData(d);
		n1->setLink(temp);
	}
}

void before_insert(NodePtr& h, NodePtr& n, studentPtr d)
{
	if (n == h)
		head_insert(h, d);
	else {
		NodePtr temp = h;
		while (temp->getLink() != n)
			temp = temp->getLink();
		NodePtr node = new Node();
		node->setData(d);
		node->setLink(n);
		temp->setLink(node);
	}
}

void print_linked_list1(const NodePtr& h)
{
	if (h == NULL)
	{
		cout << "Empty Linked List. Nothing to print." << endl;
		return;
	}
	else
	{
		int num = 0;
		NodePtr temp = h;
		while (temp != NULL)
		{
			if (temp->getData()->getCGPA() == 0 || temp->getData()->getResearchScore() == 0 ||                                  
				temp->getData()->getFirstName() == "null" || temp->getData()->getLastName() == "null" ||
				temp->getData()->getProvince() == "")
			{
				temp->getData()->print();
				cout << "\t" << "There are something missing!" << endl;
				break;
			}
                        //check out if there is anything missing.
			else
			{
				temp->getData()->print();
				cout << endl;
				temp = temp->getLink();
				num++;
			}
		}
		cout << num << endl;
	}
}

void print_linked_list2(const NodePtr& h)
{
	if (h == NULL)
	{
		cout << "Empty Linked List. Nothing to print." << endl;
		return;
	}
	else
	{
		int num = 0;
		NodePtr temp = h;
		while (temp != NULL)
		{
			if (temp->getData()->getCGPA() == 0 || temp->getData()->getResearchScore() == 0 ||
				temp->getData()->getFirstName() == "null" || temp->getData()->getLastName() == "null" ||
				temp->getData()->getCountry() == "")
			{
				temp->getData()->print();
				cout << "\t" << "There are something missing!" << endl;
				break;
			}
                        //check out if there is anything missing.
			else
			{
				temp->getData()->print();
				cout << endl;
				temp = temp->getLink();
				num++;
			}
		}
		cout << num << endl;
	}
}

void find_tail(NodePtr& t, NodePtr& h)
{
	t = h;
	while (t->getLink() != NULL)
		t = t->getLink();
}

NodePtr find_tail(NodePtr& h)
{
	NodePtr t = new Node;
	t = h;
	while (t->getLink() != NULL)
		t = t->getLink();
	return t;
}

void insert_node1(NodePtr& hi, const studentPtr i) //Complexity O(n)
{
	if (hi == NULL)
		head_insert(hi, i);
	else
	{
		NodePtr temp = hi;
		while (temp != NULL)
		{
			if (compareResearchScore(temp->getData(), i) == 0)
			{
				before_insert(hi, temp, i);
				break;
			}
			else if (compareResearchScore(temp->getData(), i) == 1)
			{
				if (compareCGPA(temp->getData(), i) == 0)
				{
					before_insert(hi, temp, i);
					break;
				}
				else if (compareCGPA(temp->getData(), i) == 1)
				{
					if (compareCountry(temp->getData(), i) == 2)
					{
						before_insert(hi, temp, i);
						break;
					}
					else
						temp = temp->getLink();
				}
				else
					temp = temp->getLink();
			}
			else
				temp = temp->getLink();
		}
		if (temp == NULL)
			tail_insert(hi, i);
	}
}

void insert_node2(NodePtr& hd, const studentPtr i) //complexity O(n)
{
	if (hd == NULL)
		head_insert(hd, i);
	else
	{
		NodePtr temp = hd;
		while (temp != NULL)
		{
			if (compareResearchScore(temp->getData(), i) == 0)
			{
				before_insert(hd, temp, i);
				break;
			}
			else if (compareResearchScore(temp->getData(), i) == 1)
			{
				if (compareCGPA(temp->getData(), i) == 0)
				{
					before_insert(hd, temp, i);
					break;
				}
				else if (compareCGPA(temp->getData(), i) == 1)
				{
					if (compareProvince(temp->getData(), i) == 2)
					{
						before_insert(hd, temp, i);
						break;
					}
					else
						temp = temp->getLink();
				}
				else
					temp = temp->getLink();
			}
			else
				temp = temp->getLink();
		}
		if (temp == NULL)
			tail_insert(hd, i);
	}
}

void outputStuByNum(NodePtr& head, const int& i) //comlexity O(n)
{
	if(i < 20200000)
	{
		cout << "Invalid application number" << endl
			 << "Application number must be greater than or equal to 20200000" << endl;
	}
	NodePtr temp = head;
	if (temp == NULL)
		cout << "Student linked list empty. Cannot output students of specified information." << endl;
	else if(temp->getLink() == NULL)
	{
		if (temp->getData()->getID() == i)
		{
			temp->getData()->print();
		}
		else
		{
			cout << "The stuednt does not exist!" << endl;
		}	
	}
	else
	{
		NodePtr temp = head;
		NodePtr temp2 = head;
		int num = 0, n = 0;
		while (temp != NULL)
		{
			if (temp->getData()->getID() != i)
				num++;
			temp = temp->getLink();
		}
		while (temp2 != NULL)
		{
			n++;
			temp2 = temp2->getLink();
		}
		if (num == n)
		{
			cout << "The ID does not exist!" << endl;
			return;
		}
                //check out if the student of this ID does exist. If not, give the feedback and stop the program.
		else
		{
			//cout << "pass 0" << endl;
			temp = head;
			while (temp != NULL)
			{
				if ((temp->getData()->getID()) == i)
				{	
					//cout << "pass n" << endl;
					temp->getData()->print();
					cout << endl;
				}
				temp = temp->getLink();
			}
		}
	}
}

void outputStuByResScore(NodePtr& head, const int& i) //comlexity O(n)
{
	if(i > 100 || i < 0)
	{
		cout << "Invalid research score" << endl
		     << "Research score must be between 0 and 100." << endl;
	}
	NodePtr s = head;
	if (s == NULL)
		cout << "Student linked list empty. Cannot output students of specified information." << endl;
	else if(s->getLink() == NULL)
	{
		if (s->getData()->getResearchScore() == i)
		{
			s->getData()->print();
		}
		else
		{
			cout << "The stuednt does not exist!" << endl;
		}	
	}
	else
	{
		NodePtr temp = head;
		NodePtr temp2 = head;
		int num = 0, n = 0;
		while (temp != NULL)
		{
			if (temp->getData()->getResearchScore() != i)
				num++;
			temp = temp->getLink();
		}
		while (temp2 != NULL)
		{
			n++;
			temp2 = temp2->getLink();
		}
		if (num == n)
		{
			cout << "The research score does not exist!" << endl;
			return;
		}
                //check out if the student of this reaserch score does exist. If not, give the feedback and stop the program.
		else
		{
			while (s != NULL)
			{
				if (s->getData()->getResearchScore() == i)
				{
					s->getData()->print();
					cout << endl;
				}
				s = s->getLink();
			}
		}
	}
}

void outputStuByCGPA(NodePtr& head, const float& i) //comlexity O(n)
{
	if(i > 4.3 || i < 0.0)
	{
		cout << "Invalid CPGA" << endl
			 << "CGPA must be between 0 and 4.3." << endl;
		return;
	}

	NodePtr s = head;
	if (s == NULL)
		cout << "Student linked list empty. Cannot output students of specified information." << endl;
	else if(s->getLink() == NULL)
	{
		if (s->getData()->getCGPA() == i)
		{
			s->getData()->print();
		}
		else
		{
			cout << "The stuednt does not exist!" << endl;
		}	
	}
	else
	{
		NodePtr temp = head;
		NodePtr temp2 = head;
		int num = 0, n = 0;
		while (temp != NULL)
		{
			if (temp->getData()->getCGPA()!=i)
				num++;
			temp = temp->getLink();
		}
		while (temp2 != NULL)
		{
			n++;
			temp2 = temp2->getLink();
		}
		if (num == n)
		{
			cout << "The CGPA does not exist!" << endl;
			return;
		}
                //check out if the student of this CGPA does exist. If not, give the feedback and stop the program.
		else
		{
			while (s != NULL)
			{
				if (s->getData()->getCGPA() == i)
				{
					s->getData()->print();
					cout << endl;
				}
				s = s->getLink();
			}
		}
	}
}


void outputStuByName(NodePtr& head, string& fName, string& lName) //comlexity O(n)
{
	NodePtr s = head;
	if (s == NULL)
		cout << "Student linked list empty. Cannot output students of specified information." << endl;
	else if(s->getLink() == NULL)
	{
	        CorrectName(fName);
		CorrectName(lName);
		string stuFName = s->getData()->getFirstName();
		string stuLName = s->getData()->getLastName();
		CorrectName(stuFName);
		CorrectName(stuLName);

		if ( stuFName == fName &&
			 stuLName == lName)
		{
			s->getData()->print();
		}
		else
		{
			cout << "The stuednt does not exist!" << endl;
		}	 
	}
	else
	{
		CorrectName(fName);
		CorrectName(lName);
		NodePtr temp = head;
		NodePtr temp2 = head;
		int num = 0, n = 0;
		while (temp != NULL)
		{
			string  name1 = temp->getData()->getFirstName(), name2 = temp->getData()->getLastName();
			CorrectName(name1);
			CorrectName(name2);
			if (name1 != fName || name2 != lName)
				num++;
			temp = temp->getLink();
		}
		while (temp2 != NULL)
		{
			n++;
			temp2 = temp2->getLink();
		}
		if (num == n)
		{
			cout << "The stuednt does not exist!" << endl;
			return;
		}
                //check out if the student of this name does exist. If not, give the feedback and stop the program.
		else
		{
			while (s != NULL)
			{
				string  name1 = s->getData()->getFirstName(), name2 = s->getData()->getLastName();
				CorrectName(name1);
				CorrectName(name2);
				if (name1 == fName && name2 == lName)
				{
					s->getData()->print();
					cout << endl;
				}
				s = s->getLink();
			}
			cout << "Successfully output all students of specified name." << endl;
		}
	}
}

bool removeHeadAndTail(NodePtr& head, NodePtr& tail)
{
	if (head == NULL)
	{//Check to make sure that the linked list is defined.
		cout << "Passed linked list is undefined. Cannot remove head and tail from list." << endl;
		return false;
	}
	else if (head->getLink() == NULL)
	{
		NodePtr n = head->getLink();
		head->setLink(NULL);
		delete n;
	}
	else
	{
		NodePtr n = head;
		head = head->getLink();
		n->setLink(NULL);

		delete n;
		//delete value at head as it is dynamic memory and is no longer used.

		NodePtr newTail = head;

		while (newTail->getLink() != tail)
		{
			newTail = newTail->getLink();
		}
		//Creates a new temperary node that becomes the node before the tail.
		//Tail is set to this new temperary node.

		tail = newTail;
		tail->setLink(NULL);
		//delete value at tail as it is dynamic memory and is no longer used.

		return true;
	}
}

bool removeStudent(NodePtr& head, string& fName, string& lName) //comlexity O(n)
{
	if (head == NULL)
	{
		cout << "head == NULL" << endl;
		return false;
	}
	else
	{
		CorrectName(fName);
		CorrectName(lName);
		NodePtr temp = head;
		NodePtr temp2 = head;
		int num = 0, s = 0;
		while (temp != NULL)
		{
			string  name1 = temp->getData()->getFirstName(), name2 = temp->getData()->getLastName();
			CorrectName(name1);
			CorrectName(name2);
			if (name1 != fName || name2 != lName)
				num++;
			temp = temp->getLink();
		}
		while (temp2 != NULL)
		{
			s++;
			temp2 = temp2->getLink();
		}
		if (num == s)
			return false;
                //Check out if the student of the name input does exist, if not it will give the feedback in the main function.
		else
		{
			NodePtr before = head;
			NodePtr current = head->getLink();
			while (current != NULL)
			{
				//check head node
				if (before->getData()->getFirstName() == fName && before->getData()->getLastName() == lName)
				{
					//cout << "Decapitate" << endl;
					NodePtr discard = before;
					before = before->getLink();
					current = current->getLink();
					discard->setLink(NULL);
					//sets the new value of head, the student after the previous head

					delete discard;
					//deletes the old head from memory
				}
				//if any member of the linked list contains a student with first name fName and last name lName
				//removes student from the linked list
				string  name1 = current->getData()->getFirstName(), name2 = current->getData()->getLastName();
				CorrectName(name1);
				CorrectName(name2);
				if (name1 == fName && name2 == lName)
				{
					before->setLink(current->getLink());
					delete current;

					current = before->getLink();
				}
				current = current->getLink();
				before = before->getLink();
				//sets the value at temp to the next value in the list, going down the list.
			}
			return true;
		}
	}
}
//change bool return to students removed, not fn void

void addStudent(NodePtr& head, const studentPtr& s)
{
	insert_node1(head, s);
}


NodePtr sort_student(NodePtr& hd, NodePtr& hi) //comlexity O(n^2)
{
	NodePtr hs = NULL;
	NodePtr n = hi;
	while (n != NULL)
	{
		NodePtr temp = hd;
		while (temp != NULL)
		{
			if (compareResearchScore(temp->getData(), n->getData()) == 0)
			{
				before_insert(hd, temp, n->getData());
				break;
			}
			else if (compareResearchScore(temp->getData(), n->getData()) == 1)
			{
				if (compareCGPA(temp->getData(), n->getData()) == 0)
				{
					before_insert(hd, temp, n->getData());
					break;
				}
				else if (compareCGPA(temp->getData(), n->getData()) == 1)
				{
					if (temp->getData()->getCountry() == "null")
					{
						NodePtr m = temp->getLink();
						before_insert(hd, m, n->getData());
						break;
					}
					else
					{
						if (compareCountry(temp->getData(), n->getData()) == 2)
						{
							before_insert(hi, temp, n->getData());
							break;
						}
						else
							temp = temp->getLink();
					}
				}
				else
					temp = temp->getLink();
			}
			else
				temp = temp->getLink();
		}
		if (temp == NULL)
			tail_insert(hd, n->getData());
		n = n->getLink();
	}
	hs = hd;

	return hs;
}

void find_student(NodePtr& hs, const float& cgpa_threshold, const int& researchScore_threshold, NodePtr& s)
//comlexity O(n)
{
	NodePtr temp = hs;
	while (temp != NULL)
	{
		if (temp->getData()->getCGPA() >= cgpa_threshold &&
			temp->getData()->getResearchScore() >= researchScore_threshold)
		{
			if (s == NULL)
				head_insert(s, temp->getData());
			else
				tail_insert(s, temp->getData());
		}
		temp = temp->getLink();
	}
	if (s == NULL)
		cout << "there is no match found" << endl;
}

bool outputStuByThreshold(NodePtr& head, const float& cgpa_threshold, const int& researchScore_threshold)
//comlexity O(n)
{
	bool studentsFound = false;

	//check for valid CGPA and research score
	//if not met outputs error message and returns false
	if(cgpa_threshold < 0 ||
	   cgpa_threshold > 4.3 ||
	   researchScore_threshold < 0 ||
	   researchScore_threshold > 100)
	{
		cout << "Invalid inputs." << endl
			 << "CGPA must be between 0 and 4.3." << endl
			 << "Research Score must be between 0 and 100." << endl;
		return studentsFound;
	}
	
	NodePtr temp = head;
	
	
	
	if(temp == NULL)
	{
		//checks if the inputted linked list has any values in it.
		cout << "Linked List empty, no students to output." << endl;
	}
	else
	{
		while(temp->getLink() != NULL)
		{
			//checks threshold requirements
			//if requirements met print student data
			//and set check that a student that meets requirement has been found
			if (temp->getData()->getCGPA() 			>= cgpa_threshold &&
				temp->getData()->getResearchScore() >= researchScore_threshold)
			{
				temp->getData()->print();
				cout << endl;
				studentsFound = true;
			}
			temp = (temp->getLink());
		}
	}
	
	//checks if any students were found that met threshold requirements
	//if not students were found outputs failure message.
	return studentsFound;
}

bool CheckOutField1(DomesticStudent* d)
{
	if (d->getResearchScore() == 0)
		return false;
	else
		return true;
}

bool CheckOutField2(internationalStudent* i)
{
	if (i->getWriting() == 0)
		return false;
	else
		return true;
}

bool CheckProvince(DomesticStudent* d)
{
	vector<string>::iterator p;
	vector<string> province;
	province.push_back("NL"); province.push_back("PE"); province.push_back("NS");
	province.push_back("NB"); province.push_back("QC"); province.push_back("ON");
	province.push_back("MB"); province.push_back("SK"); province.push_back("AB");
	province.push_back("BC"); province.push_back("YT"); province.push_back("NT");
	province.push_back("NU");
	string n1 = d->getProvince();
	int index = 0;
	while (n1[index] != '\0')
	{
		if (n1[index] >= 'a' && n1[index] <= 'z')
			n1[index] = n1[index] - 32;
		index++;
	}
	int num = 0;
	for (p = province.begin();p != province.end();p++)
	{
		if (n1 == *p)
			return true;
		else
			num++;
	}
	if (num == 13)
		return false;
}

bool CheckCountry(internationalStudent* i)
{
	vector<char>::iterator p;
	vector<char> India;
	India.push_back('i'); India.push_back('n'); India.push_back('d');
	India.push_back('i'); India.push_back('a');
	vector<char> Iran;
	Iran.push_back('i'); India.push_back('r'); Iran.push_back('a'); Iran.push_back('n');
	vector<char> China;
	China.push_back('c'); China.push_back('h'); China.push_back('i');
	China.push_back('n'); China.push_back('a');
	vector<char> Korea;
	Korea.push_back('c'); Korea.push_back('o'); Korea.push_back('r');
	Korea.push_back('e'); Korea.push_back('a');
	string n1 = i->getCountry();
	int index = 0;
	while (n1[index] != '\0')
	{
		if (n1[index] >= 'A' && n1[index] <= 'Z')
			n1[index] = n1[index] + 32;
		index++;
	}
	index = 0;
	if (i->getCountry() == "India" || i->getCountry() == "Iran" ||
		i->getCountry() == "China" || i->getCountry() == "Korea")
		return true;
	else
	{
		if (n1[0] == 'i')
		{
			if (n1.size() == 5)
			{
				int m = 0;
				for (int j = 0;j < 5;j++)
				{
					int n = 0;
					for (p = India.begin();p != India.end();p++)
					{
						if (n1[j] == *p)
							break;
						else
							n++;
					}
					if (n == 5)
						return false;
					else
						m++;
				}
				if (m == 5)
				{
					i->setCountry("India");
					cout << "Country automatically detected as India." << endl;
					return true;
				}
			}
			else if (n1.size() == 4)
			{
				int m = 0;
				for (int j = 0;j < 4;j++)
				{
					int n = 0;
					for (p = Iran.begin();p != Iran.end();p++)
					{
						if (n1[j] == *p)
							break;
						else
							n++;
					}
					if (n == 4)
						return false;
					else
						m++;
				}
				if (m == 4)
				{
					i->setCountry("Iran");
					cout << "Country automatically detected as Iran." << endl;
					return true;
				}
				else
					return false;
			}
			else
				return false;
		}
		else if (n1[0] == 'c')
		{
			if (n1.size() == 5)
			{
				int m = 0;
				for (int j = 0;j < 5;j++)
				{
					int n = 0;
					for (p = China.begin();p != China.end();p++)
					{
						if (n1[j] == *p)
							break;
						else
							n++;
					}
					if (n == 5)
						return false;
					else
						m++;
				}
				if (m == 5)
				{
					i->setCountry("China");
					cout << "Country automatically detected as China." << endl;
					return true;
				}
				else
					return false;
			}
			else
				return false;
		}
		else if (n1[0] == 'k')
		{
			if (n1.size() == 5)
			{
				int m = 0;
				for (int j = 0;j < 5;j++)
				{
					int n = 0;
					for (p = Korea.begin();p != Korea.end();p++)
					{
						if (n1[j] == *p)
							break;
						else
							n++;
					}
					if (n == 5)
						return false;
					else
						m++;
				}
				if (m == 5)
				{
					i->setCountry("Korea");
					cout << "Country automatically detected as Korea." << endl;
					return true;
				}
				else
					return false;
			}
			else
				return false;
		}
		else
		return false;
	}
}

void CorrectName(string& name)
{
	if (name[0] >= 'a' && name[0] <= 'z')
		name[0] = name[0] - 32;
	int index = 1;
	while (name[index] != '\0')
	{
		if (name[index] >= 'A' && name[index] <= 'Z')
			name[index] = name[index] + 32;
		index++;
	}
}

void genericPrint(NodePtr &head)
{
	NodePtr temp = head;

	if(temp == NULL)
		;
	else	
		while(temp != NULL)
		{
			temp->getData()->print();
			temp = temp->getLink();
		}
}

#endif
