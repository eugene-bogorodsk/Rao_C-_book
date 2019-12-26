//============================================================================
// Name        : listing_28_2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description :bad_alloc exception handling
//============================================================================

#include <iostream>
#include <exception>

int main() {
	using namespace std;

	cout<<"Enter number if integers you wish to reserve: ";
	try
	{
		//enter -1 to get exception
		int Input = 0;
		cin>>Input;
		int* pReservedInts = new int[Input];
		delete [] pReservedInts;

	}
	catch (bad_alloc & exp)
	{
		cout<<"Exeption incountered: "<<exp.what()<<endl;
		cout<<"Got to end,sorry!"<<endl;
	}
	catch(...)
	{
		cout<<"Exception encountered. Got to end, sorry!"<<endl;

	}
	return 0;
}
