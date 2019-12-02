/*internationalStudent.hpp
 *Written by: Chris Rosenauer, Yuchun He
 *Date Written: Sept 19, 2019
*/

#ifndef INTERNATIONALSTUDENT_H
#define INTERNATIONALSTUDENT_H

#include <string>
#include "student.hpp"
#include "toeflScore.hpp"

class internationalStudent : public student
{
/*Variables that carried over from student:
 * first name
 * last name
 * id
 * research score
 * cgpa
 *
 *Variables that carried over from toeflScore:
 * writing
 * reading
 * listening
 * speaking
 *
 *Variables that are unique to internationalStudent:
 * country
 * 
*/
private:
	string FirstName, LastName;
	float CGPA;
	int ResearchScore;
	int ID;
	string country;
	toeflScore englishScore;
public:	
	internationalStudent();
	/*internationStudent constructor without arguements
	 *sets FirstName, LastName and country to "null"
	 *sets CGPA, ResearchScore to 0
	 *and sets StudentNumber to 10000 (or above depending on how many students are currently in the system)
	*/
	internationalStudent(
		const string& fName,
		const string& lName,
		const string& Coun,
		const float& cgpa,
		const int& resScore,
		const int& stuNun,
		const int& read,
		const int& write,
		const int& listen,
		const int& speak);
	/*internationalStudent constructor with arguements
	 *sends fName, lName, cgpa, resScore, and stuNum + 10000 to set for the purpose of initializing varialbes.
	 *for more information see student.hpp
	 *then sets the varialbes for reading, writing, listening and speaking via toeflScore
	 *for more information see toeflScore.hpp
	 *sets member variable country to the inputted value Coun
	*/

	void set(const string& fir, const string& las, const float& cgpa, const int& res, const int& stuNum,
		const int& r, const int& w, const int& l, const int& s);

	void setCountry(const string& Coun);

	string getFirstName()const;

	string getLastName()const;

	string getCountry() const;

	string getProvince() const;

	float getCGPA()const;

	int getResearchScore()const;

	int getID()const;

	int getReading() const;
	//returns reading component of member structure toeflscore
	
	int getWriting() const;
	//returns writing component of member structure toeflscore
	
	int getSpeaking() const;
	//returns speaking component of member structure toeflscore
	
	int getListening() const;
	//returns listening component of member structure toeflscore
	
	int getTotal() const;
	//returns total component of member structure toeflscore

	internationalStudent& operator = (const internationalStudent& i);
    //precondition:  an internationalStudent i
	//postcondition: sets some internationalStudent to inputted internationalStudent i
	//ex internationalStudent stu = i;

	void print()const;
	
    friend ostream& operator << (ostream& os, const internationalStudent* intstu);
    //precondition:  ostream os and an internationalStudent intstu
	//postcondition: outputs all member variables of intstu to the console
};

#endif //INTERNATIONALSTUDENT_H
