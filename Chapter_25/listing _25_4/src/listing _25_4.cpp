//============================================================================
// Name        : listing.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : using class vector<bool>
//============================================================================

#include <iostream>
#include <vector>

int main() {
	using namespace std;

	vector<bool> vecBoolFlags(3);
	vecBoolFlags [0] = true;
	vecBoolFlags [1] = true;
	vecBoolFlags [2] = false;

	vecBoolFlags.push_back (true);

	cout<<"The contents of the vector are: "<<endl;
	for (size_t nIndex = 0; nIndex <vecBoolFlags.size(); ++nIndex)
		cout<<vecBoolFlags [nIndex]<<' ';

	cout<<endl;
	vecBoolFlags.flip();

	cout<<"The contents of the vector are: "<<endl;
	for (size_t nIndex = 0; nIndex <vecBoolFlags.size(); ++nIndex)
		cout<<vecBoolFlags [nIndex]<<' ';

	cout<<endl;

	return 0;
}
