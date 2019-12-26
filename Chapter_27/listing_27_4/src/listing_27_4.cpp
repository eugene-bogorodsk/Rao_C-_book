//============================================================================
// Name        : listing_27_4.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : using cin object to read in a integer variable, double variable in an
//				exponential form and three characters
//============================================================================

#include <iostream>


int main() {
	using namespace std;

	cout<<"Enter an integer: ";
	int inputInt = 0;
	cin>>inputInt;

	cout<<"Enter the value of Pi: ";
	double Pi = 0.0;
	cin>>Pi;

	cout<<"Enter three characters separated by space: "<<endl;
	char Char1 = '\0',Char2 = '\0',Char3 = '\0';
	cin>>Char1>>Char2>>Char3;

	cout<<"The recoreded variable values are: "<<endl;
	cout<<"inputInt: 	"<<inputInt<<endl;
	cout<<"Pi: "<<Pi<<endl;
	cout<<"The three characters: "<<Char1<<Char2<<Char3<<endl;

	return 0;
}
