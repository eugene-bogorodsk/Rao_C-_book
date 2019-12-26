//============================================================================
// Name        : listing_28_1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : using try and catch to supply the sustainability of the
//				exception when memory is reserved
//============================================================================

#include <iostream>


int main() {
	using namespace std;

	cout<<"Enter number of integers you wish to reserve: ";
	try
	{
		int Input = 0;
		cin>>Input;
		int* pReservedInts = new int [Input];
		delete [] pReservedInts;
	}
	catch (...)
	{
		cout<<"Exception encountered. Got to end, sorry!"<<endl;
	}
	return 0;
}
