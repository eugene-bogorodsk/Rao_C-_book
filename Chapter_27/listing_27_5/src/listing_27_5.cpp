//============================================================================
// Name        : listing_27_5.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : inserting a C style buffer without going beyond its boundaries
//============================================================================

#include <iostream>


int main() {
	using namespace std;

	cout<<"Enter a line: "<<endl;
	char CStyleStr[10]= {0};
	cin.get(CStyleStr,9);
	cout<<"CStyleStr: "<<CStyleStr<<endl;

	return 0;
}
