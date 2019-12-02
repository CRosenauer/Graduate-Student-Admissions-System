/*
 * Lab 1
 * Written by  : Chris Rosenauer, Yuchun He
 * Date Written: Sept, 16, 2019
 *
 * toeflScore.hpp
 * 
*/

#ifndef TOEFLSCORE_H
#define TOEFLSCORE_H

class toeflScore
{
	public:
	toeflScore();
	toeflScore(int read, int listen, int speak, int write);
	/* class constructor.
	 * essentially sets int reading, listening, speaking, writing, and total upon inizialization
	 * based on the inputted variables read, listen, speak, and write.
	 *
	 * If no inputs are specified then the constructor is passed no values then it sets all 5 variables to 0.
	 *
	 * For more information see toeflScore::toeflScore 
	*/
	
	void printToeflScore();
	/* Function's only purpose is the output all of the values stored in reading, writting, listening, speaking, and total
	 * intended for debug purpose.
	*/
	
	int getReading() const;
	int getListening() const;
	int getSpeaking() const;
	int getWriting() const;
	int getTotal() const;
	/* The prior 5 "get" functions all have similar purposes.
	 * That is to return the values at reading, listening, speaking, writing, and total respectively.
	*/
	
	void setReading(int newReading);
	void setListening(int newListening);
	void setSpeaking(int newSpeaking);
	void setWriting(int newWriting);
	/* The prior 4 "set" funtions all have the purpose of setting a variable.
	 * Each "set" fn takes in 1 arguement and prodeeds to set the corresponding variable
	 * to the inputted variable
	*/
	
	void updateTotal();
	/* The purpose of update total, like the name implies is to update the total value
	 * total is updated as such because the total should always = the sum of individual toefl scores
	*/
	
	
	private:
	int reading, listening, speaking, writing, total;
	/* The prior integers co-respond to the scores of the toefl test.
	 * 
	 * reading is the stored value of the reading score of the toefl test.
	 * listening is the stored value of the listening score of the toefl test.
	 * speaking is the stored value of the speaking score of the toefl test.
	 * writing is the stored value of the writing score of the toefl test.
	 * each of the previous 4 values should range from 0 to 30.
	 *
	 * finally, total is the sum of the 4 previous components of the test.
	*/
};

#endif
