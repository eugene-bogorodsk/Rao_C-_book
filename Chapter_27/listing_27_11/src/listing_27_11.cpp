//============================================================================
// Name        : listing_27_11.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : converting an integer value in a string value and vice versa using stringstream class
//============================================================================

#include <iostream>
#include <sstream>
#include <fstream>


int main() {
	using namespace std;

	cout<<"Enter an integer: ";
	int Input = 0;
	cin>>Input;

	stringstream converterStream;
	converterStream<<Input;
	string strInput;
	converterStream>>strInput;

	cout<<"Integer Input = "<<Input<<endl;
	cout<<"String gained from integer, strInput = "<<strInput<<endl;

	stringstream anotherStream;
	anotherStream<<strInput;
	int Copy = 0;
	anotherStream>>Copy;

	cout<<"Integer gained from string, Copy = "<<Copy<<endl;

	return 0;
}
