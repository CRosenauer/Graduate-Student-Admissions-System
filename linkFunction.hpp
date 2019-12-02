#ifndef LINKFUNCTION_H
#define LINKFUNCTION_H

#include <iostream>
#include "nodeClass.hpp"
#include "internationalStudent.hpp"
#include "DomesticStudent.hpp"
#include "student.hpp"
#include <vector>

using namespace std;
using std::vector;

void head_insert(NodePtr& h, studentPtr d);
//precondition:  a head, NodePtr h and a non-NULL studentPtr d.
//postcondition: inserts the studentPtr d at the head of the linked list.

void tail_insert(NodePtr& h, studentPtr d);
//precondition:  a head, NodePtr h and a non-NULL studentPtr d.
//postcondition: inserts the studentPtr d at the tail of the linked list.

void before_insert(NodePtr& h, NodePtr& n, studentPtr d);
//precondition:  the head of a linked list, h, a nodePtr, n, and a studentPtr d
//postcondition: inserts studentPtr d into the linked list after the member node n.

void print_linked_list1(const NodePtr& h);
//precondition:  a non--NULL NodePtr head, h
//postcondition: function traverses the linked list until the tail element is found
//				 outputs every student element of the linked list.

void print_linked_list2(const NodePtr& h);
//precondition:  a non--NULL NodePtr head, h
//postcondition: function traverses the linked list until the tail element is found
//				 outputs every student element of the linked list

void find_tail(NodePtr& tail, NodePtr& head);
//precondition:  a NodePtr head, h
//postcondition: function traverses the linked list until the tail element is found
//				 sets tail to the found tail node

NodePtr find_tail(NodePtr& h);
//precondition:  a NodePtr head, h
//postcondition: function traverses the linked list until the tail element is found
//				 returns tail node

void insert_node1(NodePtr& hi, const studentPtr i);
//precondition:  A NodePtr for the head of an international student linked list
//				 and an international student in studentPtr i
//postcondition: function creates a new node in the linked list and inserts i into the datea
//				 for said node.
//				 order is determined by research score, then cgpa, then alphabetical country
//				 nodes are inserted high to low

void insert_node2(NodePtr& hd, const studentPtr d);
//precondition:  A NodePtr for the head of an domestic student linked list
//				 and an domestic student in studentPtr d
//postcondition: function creates a new node in the linked list and inserts d into the datea
//				 for said node.
//				 order is determined by research score, then cgpa, then alphabetical province
//				 nodes are inserted high to low 

NodePtr sort_student(NodePtr& hd, NodePtr& hi);
//precondition:  2 NodePtrs, one for head of domestic student linked list (hd)
//				 one for head of international student linked list (hi)
//postcondition: function orderly combines hd and hi into a single linked list
//				 returns linked list
//				 sorting order of insertion based on research score, then cgpa, then alphabetical location

void outputStuByNum(NodePtr& s, const int& i);
//precondition:  a non-null Node pointer, s
//               and an ID to search i;
//postcondition: function goes through every member of the linked list and
//               outputs every member Student who has ID i
//               if no Student with ID i can be found outputs
//               error message


void outputStuByResScore(NodePtr& s, const int& i);
//precondition:  a non-null node pointer, s
//               and an research score to search i;
//postcondition: function goes through every member of the linked list and
//               outputs every member Student who has
//               researchScore i
//               if no Student with researchScore i can be found
//               outputs error message

void outputStuByCGPA(NodePtr& s, const float& i);
//precondition:  a non-null Node pointer, s
//               and a CGPA to search i;
//postcondition: function goes through every member of the linked list and
//               outputs every member student who has CGPA i
//               if no students with CGPA i can be found outputs
//               error message


void outputStuByName(NodePtr& s, string& fName, string& lName);
//precondition:  a non-null node pointer, s
//               and a first name string to search for, n
//postcondition: function goes through every member of the linked list and
//               outputs every member student pointer who has a firstName and
//               equal to fName, and lastName equal to lName.
//               if no internationalStudent can be found with firstName = n
//               outputs error message


bool removeHeadAndTail(NodePtr& head, NodePtr& tail);
//precondition:  two non-null domesticStudentNode pointer of a linked list, head
//               and tail
//postcondition: function attempts to remove both head and tail of the inputted
//               linked list head and tail pointers.
//               if removal successful function returns true, else returns false


bool removeStudent(NodePtr& head, string& fName, string& lName);
//precondition:  a non-null head pointer of an internationalStudent linked list
//               a two strings, fName and lName
//postcondition: function attempts to remove member node that contains the same 
//               firstName and lastName as fName and lName respectively.
//               if removal is successful returns true, else returns false.

void addStudent(NodePtr& head, const studentPtr& s);
//precondition:  a non-null head pointer of an internationalStudent linked list
//               an internationalStudent s to add to the linked list
//postcondition: function attempts to ordered insert student into the linked
//               list
//               function sorts based on research score,
//               if two students have the same research score, sorts by cgpa
//               if two students have the same cgpa, sorts by country

bool outputStuByThreshold(NodePtr& head, const float& cgpa_Threshold, const int& researchScore_threshold);
//precondition:  A non-NULL NodePtr head and valid cgpa, and research score thresholds.
//postcondition: Functions checks every member of the linked list
//				 Outputs every who meets inputted requirements
//				 If no students meed output requirements outputs error message.

bool CheckOutField1(DomesticStudent* d);
//check out if there is anything missing in the information of the domestic student. If there is somrthing missing, it will give feedback and stop the program.

bool CheckOutField2(internationalStudent* i);
//check out if there is anything missing in the information of the international student. If there is somrthing missing, it will give feedback and stop the program.

bool CheckProvince(DomesticStudent* d);
//Check out if the province of the domestic student is valid. If not it will give the feedback and stop the program.

bool CheckCountry(internationalStudent* i);
//Check out if the country of the international student is valid. If not, check it if it is can be correct. If it can, correct it. If not, give the feedback, and stop the program.


void CorrectName(string& name);
//Change the name to the correct form.

void genericPrint(NodePtr &head);
//precondition:  the head of a linked list, head.
//postcondition: prints every element of the passed linked list head to the console.

#endif
