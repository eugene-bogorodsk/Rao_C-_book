//============================================================================
// Name        : listing_27_3.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : setting the field width and fill characters using manipulators setw and setfill
//============================================================================

#include <iostream>
#include <iomanip>


int main() {
	using namespace std;

	cout<<"Hey - default! "<<endl;

	cout<<setw(35); //setting a field with a width of 25 characters
	cout<<"Hey = right aligned"<<endl;

	cout<<setw(35)<<setfill('*');
	cout<<"Hey = right aligned!"<<endl;

	cout<<"Hey = back to default!"<<endl;
	return 0;
}
