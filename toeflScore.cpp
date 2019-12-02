/*
 * Lab 1
 * Written by  : Chris Rosenauer, Yuchun He
 * Date Written: Sept, 16, 2019
 *
 * toeflCcore.cpp
 *
 * This file mainly contains the constructors for class toeflScore.
 * File contains 2 constructors, one for 0 arguements passed, one for 4 arguements passed (more information below)
 * 
*/

#include <iostream>
#include "toeflScore.hpp"
using namespace std;

toeflScore::toeflScore()
{
	setReading(0);
	setWriting(0);
	setSpeaking(0);
	setListening(0);
	
	updateTotal();
	}

/* 0 arguement toeflScore constructor.
 * value takes 0 arguements and sets all variables to 0
 * used if one of the inputted values for the 5 arguement constructor is invalid
*/

toeflScore::toeflScore(int read, int listen, int speak, int write)
{
		setReading(read);
		setListening(listen);
		setSpeaking(speak);
		setWriting(write);
		
		updateTotal();
}

void toeflScore::updateTotal()
{
	total = reading + listening + speaking + writing;
}

void toeflScore::setReading(int newReading)
{
	if(newReading >= 0 && newReading <= 30)
		reading = newReading;
	else
		reading = 0;
	updateTotal();
}

void toeflScore::setListening(int newListening)
{
	if(newListening >= 0 && newListening <= 30)
		listening = newListening;
	else
		listening = 0;
	updateTotal();
}

void toeflScore::setSpeaking(int newSpeaking)
{
	if(newSpeaking >= 0 && newSpeaking <= 30)
		speaking = newSpeaking;
	else
		speaking = 0;
	updateTotal();
}

void toeflScore::setWriting(int newWriting)
{
	if(newWriting >= 0 && newWriting <= 30)
		writing = newWriting;
	else
		writing = 0;
	updateTotal();
}

void toeflScore::printToeflScore()
{
		cout << "Reading:  " << toeflScore::reading << endl;
		cout << "Listing:  " <<toeflScore::listening << endl;
		cout << "Speaking: " <<toeflScore::speaking << endl;
		cout << "Writing:  " <<toeflScore::writing << endl;
		cout << "Total:    " <<toeflScore::total << endl;
}

int toeflScore::getReading() const
{
	return reading;
}

int toeflScore::getListening() const
{
	return listening;
}

int toeflScore::getSpeaking() const
{
	return speaking;
}

int toeflScore::getWriting() const
{
	return writing;
}

int toeflScore::getTotal() const
{
	return total;
}
