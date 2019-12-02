#ifndef UNITTESTS_H
#define UNITTESTS_H

#include "student.hpp"
#include "linkFunction.hpp"
#include "DomesticStudent.hpp"
#include <fstream> //file processing
#include <sstream> //formatted string processing
#include <cstdlib> //atof and atoi

//Note: These functions may not properly load students into linked lists,
//however they are for the purpose of testing linked list inputs, not testing
//if a student was added properly.

//Additionally, tests are not meant to test if functions perform operations correctly, as this has already been
//confirmed. Rather, the unit test functions are intended to ensure each function works based on a variety of
//inputted linked lists

NodePtr loadDomStu();
//Precondition:  Nothing.
//Postcondition: function used to load all students from domestic-stu.txt. returns head of said linked list.
//				 used to quickly load test linked lists for unit tests

NodePtr loadIntStu();
//Precondition:  Nothing.
//Postcondition: function used to load all students from international-stu.txt. returns head of said linked list.
//				 used to quickly load test linked lists for unit tests

void UNITSWITCH_outputStu();
//Precondition:  Nothing.
//Postcondition: Enters the user into a UI that allows them to test outputStuByNum, Name, ResScore and CGPA
//				 with the cases NULL linked list head, 1 memeber of linked list, and regular loaded linked list

void UNITSWITCH_removeHeadAndTail();
//Precondition:  Nothing.
//Postcondition: Enters the user into a UI that allows them to test removeHeadAndTail
//				 with the cases NULL linked list head, 1 memeber of linked list, and regular loaded linked list

void UNITSWITCH_insertStudent();
//Precondition:  Nothing.
//Postcondition: Enters the user into a UI that allows them to test insertStudent
//				 with the cases NULL linked list head, 1 memeber of linked list, and regular loaded linked list

void UNITSWITCH_thresholdOutput();
//Precondition:  Nothing.
//Postcondition: Enters the user into a UI that allows them to test thresholdOutput
//				 with the cases NULL linked list head, 1 memeber of linked list, and regular loaded linked list

void UNITSWITCH_removeStudent();
//Precondition:  Nothing.
//Postcondition: Enters the user into a UI that allows them to test removestudent
//				 with the cases NULL linked list head, 1 memeber of linked list, and regular loaded linked list

void UNITSWITCH_mergeStudents();
//Precondition:  Nothing.
//Postcondition: Enters the user into a UI that allows them to test mergeStudents
//				 with the cases NULL linked list head, 1 memeber of linked list, and regular loaded linked list

//unit tests for searching functions
void UNITTEST_outputStuByNum(NodePtr& head);
//Precondition:  a NodePtr for the head of a student linked list
//Postcondition: attempts to call outputStuByNum with the passed linked list head for id num 20100000.

void UNITTEST_outputStuByName(NodePtr& head);
//Precondition:  a NodePtr for the head of a student linked list
//Postcondition: attempts to call outputStuByName with the given linked list head for name Chris Rosenauer

void UNITTEST_outputStuByResScore(NodePtr& head);
//Precondition:  a NodePtr for the head of a student linked list
//Postcondition: attempts to call outputStuByResScore with the given linked list head for resScore 80.

void UNITTEST_outputStuByCGPA(NodePtr& head);
//Precondition:  a NodePtr for the head of a student linked list
//Postcondition: attempts to call outputStuByCGPA with the given linked list head for cgpa 3.3.

void UNITTEST_mergeStudents(NodePtr& domHead, NodePtr& domTail);
//Precondition:  the heads of a domestic, international linked lists, head of the to-be merged student linked list
//Postcondition: function merges both of the lists into the final linked list
//				 then checks every element of the domestic and international linked lists to ensure that 
//				 the merged list contains every student.
//				 outputs error message if student is not found in list

void UNITTEST_OUTPUT_threshholdOutput(NodePtr& stuListHead);
//Precondition:  the head of a merged student linked list
//Postcondition: function merges the linked lists, then attempts to output the linked lists
//				 with  CGPA and researchScore inputs: 3.3, 80

void UNITTEST_removeHeadAndTail(NodePtr& head, NodePtr& tail);
//Precondition:  the head and tail nodes of a student linked list
//Postcondition: funciton removes the head and tail of the linked list then prints the decapicated linked list.

void UNITTEST_removeStudent(NodePtr& head);
//Precondition:  the head and tail nodes of a student linked list
//Postcondition: funciton removes the head and tail of the linked list then prints the decapicated linked list.

void UNITTEST_insertStudent(NodePtr& head, student* stu);
//Precondition:  the head and tail nodes of a student linked list
//Postcondition: funciton removes the head and tail of the linked list then prints the decapicated linked list.


#endif //UNITTESTS_H
