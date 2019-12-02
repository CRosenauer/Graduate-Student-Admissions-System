#ifndef STUDENT_HPP
#define STUDENT_HPP

//header file student.hpp to declare your classes
using namespace std; //use namespace std


#include <string> //you will have to use string in C++
class student//set up the parent class named "student"
{
public://set up the public member functions
	virtual string getFirstName()const = 0;
	virtual string getLastName()const = 0;
	virtual float getCGPA()const = 0;
	virtual int getResearchScore()const = 0;
	virtual int getID()const = 0;
	virtual string getProvince()const = 0;
	virtual string getCountry()const = 0;
	virtual void print() const = 0;

	friend int compareCGPA(const student* s1, const student* s2);
	//precondition:  two objects of type student or a child of student
	//postcondition: returns 0 if s1's CGPA < s2's CGPA
	//				 returns 1 if s1'S CGPA = s2's CGPA
	//				 returns 2 if in all other cases (s1's CGPA > s2's CGPA)
	
	friend int compareResearchScore(const student* s1, const student* s2);
	//precondition:  two objects of type student or a child of student
	//postcondition: returns 0 if s1's ResearchScore < s2's ResearchScore
	//				 returns 1 if s1'S ResearchScore = s2's ResearchScore
	//				 returns 2 if in all other cases (s1's ResearchScore > s2's ResearchScore)
	
	friend int compareFirstName(const student* s1, const student* s2);
	//precondition:  two objects of type student or a child of student
	//postcondition: returns 0 if s1's first name is alphabetically before s2's first name
	//				 returns 1 if s1's first name is the same as s2's first name
	//				 returns 2 if s1's first name is alphabetically after s2's first name
	
	friend int compareLastName(const student* s1, const student* s2);
	//precondition:  two objects of type student or a child of student
	//postcondition: returns 0 if s1's last name is alphabetically before s2's last name
	//				 returns 1 if s1's last name is the same as s2's last name
	//				 returns 2 if s1's last name is alphabetically after s2's last name

	friend int compareProvince(const student* d1, const student* d2);

	friend int compareCountry(const student* i1, const student* i2);
};

typedef student*  studentPtr;

#endif //STUDENT_HPP
