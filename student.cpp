//student.cpp to implement your classes

#ifndef STUDENT_CPP
#define STUDENT_CPP

#include "student.hpp"

int compareCGPA(const student* s1, const student* s2)
{
	if (s1->getCGPA() < s2->getCGPA())
		return 0;
	else if (s1->getCGPA() == s2->getCGPA())
		return 1;
	else
		return 2;
}
int compareResearchScore(const student* s1, const student* s2)
{
	if (s1->getResearchScore() < s2->getResearchScore())
		return 0;
	else if (s1->getResearchScore() == s2->getResearchScore())
		return 1;
	else
		return 2;
}
int compareFirstName(const student* s1, const student* s2)
{
	string n1 = s1->getFirstName();
	string n2 = s2->getFirstName();
	int index = 0;
	while (n1[index] != '\0')
	{
		if (n1[index] >= 'A' && n1[index] <= 'Z')
			n1[index] = n1[index] + 32;
		index++;
	}
	index = 0;
	while (n2[index] != '\0')
	{
		if (n2[index] >= 'A' && n2[index] <= 'Z')
			n2[index] = n2[index] + 32;
		index++;
	}
	if (n1 < n2)
		return 0;
	else if (n1 == n2)
		return 1;
	else
		return 2;
}
int compareLastName(const student* s1, const student* s2)
{
	string n1 = s1->getLastName();
	string n2 = s2->getLastName();
	int index = 0;
	while (n1[index] != '\0')
	{
		if (n1[index] >= 'A' && n1[index] <= 'Z')
			n1[index] = n1[index] + 32;
		index++;
	}
	index = 0;
	while (n2[index] != '\0')
	{
		if (n2[index] >= 'A' && n2[index] <= 'Z')
			n2[index] = n2[index] + 32;
		index++;
	}
	if (n1 < n2)
		return 0;
	else if (n1 == n2)
		return 1;
	else
		return 2;
}
int compareProvince(const student* d1, const student* d2)
{
	string n1 = d1->getProvince();
	string n2 = d2->getProvince();
	int index = 0;
	while (n1[index] != '\0')
	{
		if (n1[index] >= 'a' && n1[index] <= 'z')
			n1[index] = n1[index] - 32;
		index++;
	}
	index = 0;
	while (n2[index] != '\0')
	{
		if (n2[index] >= 'a' && n2[index] <= 'z')
			n2[index] = n2[index] - 32;
		index++;
	}
	if (n1 < n2)
		return 0;
	else if (n1 == n2)
		return 1;
	else
		return 2;
}

int compareCountry(const student* i1, const student* i2)
{
	string n1 = i1->getCountry();
	string n2 = i2->getCountry();
	int index = 0;
	while (n1[index] != '\0')
	{
		if (n1[index] >= 'A' && n1[index] <= 'Z')
			n1[index] = n1[index] + 32;
		index++;
	}
	index = 0;
	while (n2[index] != '\0')
	{
		if (n2[index] >= 'A' && n2[index] <= 'Z')
			n2[index] = n2[index] + 32;
		index++;
	}
	if (n1 < n2)
		return 0;
	else if (n1 == n2)
		return 1;
	else
		return 2;
}

#endif //STUDENT_CPP
