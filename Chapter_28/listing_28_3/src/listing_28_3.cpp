//============================================================================
// Name        : listing_28_3.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : passing special exception when trying to divide by zero
//============================================================================

#include <iostream>

double Divide(double Dividend, double Divizor)
{
	if (Divizor == 0)
		throw  "Dividing by 0 is a crime";

	return (Dividend/Divizor);
}

int main() {
	using namespace std;

	cout<<"Enter dividend: ";
	double Dividend = 0;
	cin>>Dividend;
	cout<<"Enter divisor:";
	double Divisor = 0;
	cin>>Divisor;

	try
	{
		cout<<"Result of division is: "
				<<Divide(Dividend,Divisor);
	}
	catch(const char * exp)
	{
		cout<<"Exception: "<<exp<<endl;
		cout<<"Sorry, can't continue!"<<endl;
	}

	return 0;
}
