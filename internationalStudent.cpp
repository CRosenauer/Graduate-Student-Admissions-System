/*internationalStudent.cpp
 *written by: Chris Rosenauer, Yuchun He
 *date written: sept 19, 2019 
*/

#ifndef INTERNATIONALSTUDENT_CPP
#define INTERNATIONALSTUDENT_CPP

#include "internationalStudent.hpp"
#include<iostream>
#include <cstdio>

internationalStudent::internationalStudent()
{
	this->set("null", "null", 0, 0, 0, 0, 0, 0, 0);
	this->setCountry("null");
}

ostream& operator << (ostream& os, const internationalStudent intstu)
{
	cout << "International student: " << endl << intstu.getFirstName()
		<< " " << intstu.getLastName() << endl << "Student Number: " << intstu.getID()
		<< " from " << intstu.getCountry() << " has cgpa of " << intstu.getCGPA() << endl
		<< "Research score of " << intstu.getResearchScore() << " reading of "
		<< intstu.getReading() << " listening of " << intstu.getListening()
		<< " speaking of " << intstu.getSpeaking() << " and a writing of "
		<< intstu.getWriting() << " and a total TOEFLscore of "
		<< intstu.getTotal();

	return os;
}

void internationalStudent::print()const
{
	cout << getFirstName()
		<< " " << getLastName() << endl << "Student Number: " << getID()
		<< " from " << getCountry() << " has cgpa of " << getCGPA() << endl
		<< "Research score of " << getResearchScore() << " reading of "
		<< getReading() << " listening of " << getListening()
		<< " speaking of " << getSpeaking() << " and a writing of "
		<< getWriting() << " and a total TOEFLscore of "
		<< getTotal() << endl;
}

internationalStudent::internationalStudent(
		const string& fName,
		const string& lName,
		const string& Coun,
		const float& cgpa,
		const int& resScore,
		const int& stuNum,
		const int& read,
		const int& write,
		const int& listen,
		const int& speak)
{
	this->set(fName, lName, cgpa, resScore, stuNum + 10000, read, write, listen, speak);
	this->setCountry(Coun);
}

void internationalStudent::set(const string& fir, const string& las, const float& cgpa, const int& res, const int& stuNum,
	const int& r, const int& w, const int& l, const int& s)
{
	this->FirstName = fir;
	this->LastName = las;
	this->CGPA = cgpa;
	this->ResearchScore = res;
	this->ID = stuNum;
	this->englishScore.setReading(r);
	this->englishScore.setWriting(w);
	this->englishScore.setListening(l);
	this->englishScore.setSpeaking(s);
}
void internationalStudent::setCountry(const string& Coun)
{
	this->country = Coun;
}

string internationalStudent::getFirstName()const
{
	return FirstName;
}

string internationalStudent::getLastName()const
{
	return LastName;
}

string internationalStudent::getCountry() const
{
	return country;
}

float internationalStudent::getCGPA()const
{
	return CGPA;
}

int internationalStudent::getResearchScore()const
{
	return ResearchScore;
}

int internationalStudent::getID()const
{
	return ID;
}

int internationalStudent::getReading() const
{
	return englishScore.getReading();
}

int internationalStudent::getWriting() const
{
	return englishScore.getWriting();
}

int internationalStudent::getSpeaking() const
{
	return englishScore.getSpeaking();
}

int internationalStudent::getListening() const
{
	return englishScore.getListening();
}

int internationalStudent::getTotal() const
{
	return englishScore.getTotal();
}

string internationalStudent::getProvince()const
{
	return NULL;
}

internationalStudent& internationalStudent::operator = (const internationalStudent& i)
{
	this->set(i.getFirstName(), i.getLastName(), i.getCGPA(), i.getResearchScore(), i.getID(),
		i.getReading(), i.getWriting(), i.getListening(), i.getSpeaking());
	this->setCountry(i.getCountry());
	return *this;
}


#endif//INTERNATIONALSTUDENT_CPP