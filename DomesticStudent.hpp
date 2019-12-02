#ifndef DOMESTICSTUDENT_H
#define DOMESTICSTUDENT_H


#include<string>
#include"student.hpp"//inherited from the "student" class

using namespace std;
class DomesticStudent :public student//set up the child class "DomesticStudent
{
private: //set up the private variable of the DomesticStudent
	string FirstName, LastName;
	float CGPA;
	int ResearchScore;
	int ID;
	string province;
public: //set up the public member functions
	//put the names, grades and province to the set function
	DomesticStudent(const string& fir, const string& las, const float& cgpa, const int& res, const string& pro, const int& stuNum);
	//put "0" and "NULL" to the set function
	DomesticStudent();
	//put the variables to the private variables
	void set(const string& fir, const string& las, const float& cgpa, const int& res, const string& pro, const int& stuNum);
	//return the province
	string getProvince()const;

	string getFirstName()const;

	string getLastName()const;

	string getCountry() const;

	float getCGPA()const;

	int getResearchScore()const;

	int getID()const;

	void print()const;

	//returns the member variable province of domesticStudent
	
    DomesticStudent& operator = (const DomesticStudent& d);
	//precondition:  DomesticStudent d
	//postcondition: sets DomesticStudent to inputted DomesticStudent d
	//ex: DomesticStudent domStu = anotherStu;
	
    friend ostream& operator <<(ostream& os, const DomesticStudent& intstu);
    //precondition:  inputted ostream& os, and DomesticStudent intstu
    //postcondition: outputs all of the member variables of inputted DomesticStudent, intstu to console
};

#endif //DOMESTICSTUDENT_H
