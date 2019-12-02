#ifndef DOMESTICSTUDENT_CPP
#define DOMESTICSTUDENT_CPP

#include<iostream>
#include "DomesticStudent.hpp"

DomesticStudent::DomesticStudent()
{
	this->set("null","null", 0, 0, "null", 0);
}
DomesticStudent::DomesticStudent(const string& fir, const string& las, const float& cgpa, const int& res, const string& pro, const int& stuNum)
{
	this->set(fir, las, cgpa, res, pro, stuNum);
}
void DomesticStudent::set(const string& fir, const string& las, const float& cgpa, const int& res, const string& pro, const int& stuNum)
{
	this->FirstName = fir;
	this->LastName = las;
	this->CGPA = cgpa;
	this->ResearchScore = res;
	this->ID = stuNum;
	this->province = pro;
}

string DomesticStudent::getProvince()const
{
	return province;
}

string DomesticStudent::getFirstName()const
{
	return FirstName;
}

string DomesticStudent::getLastName()const
{
	return LastName;
}

string DomesticStudent::getCountry() const
{
	return "null";
}

float DomesticStudent::getCGPA()const
{
	return CGPA;
}

int DomesticStudent::getResearchScore()const
{
	return ResearchScore;
}

int DomesticStudent::getID()const
{
	return ID;
}

void DomesticStudent::print()const
{
	cout << endl << getFirstName()
		<< " " << getLastName() << endl << "Student Number: " << getID()
		<< " from " << getProvince() << " has cgpa of " << getCGPA() << endl
		<< "Research score of " << getResearchScore() << endl;
}

ostream& operator <<(ostream& os, const DomesticStudent& intstu)
{
    cout << intstu.getFirstName()
         << " " << intstu.getLastName() << endl<< "Student Number: " << intstu.getID()
         << " from " << intstu.getProvince() << " has cgpa of " << intstu.getCGPA() << endl
         << "Research score of " << intstu.getResearchScore();
    return os;
}

DomesticStudent& DomesticStudent::operator = (const DomesticStudent& d)
{
	this->set(d.getFirstName(), d.getLastName(), d.getCGPA(), d.getResearchScore(), d.getProvince(), d.getID());
	return *this;
}

#endif //DOMESTICSTUDENT_CPP
