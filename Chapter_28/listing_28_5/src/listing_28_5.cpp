//============================================================================
// Name        : listing_28_5.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : the CustomExeption class derived from the std::exception class
//============================================================================

#include <iostream>
#include <exception>

class CustomException:public std::exception
{
	std::string Reason;
public:
	CustomException(const char * why):Reason(why){}

	//overriding virtual function to return Reason
	virtual const char * what() const throw()
		{
		return Reason.c_str();
		}
};

double Divide (double Dividend, double Divisor)
{
	if (Divisor == 0)
		throw CustomException("CustomException: Dividing by 0 is a crime");
	return (Dividend/Divisor);
}

int main() {
	using namespace std;
	cout<<"Enter dividend: ";
	double Dividend = 0;
	cin>>Dividend;
	cout<<"Enter divisor: ";
	double Divisor = 0;
	cin>>Divisor;
	try
	{
		cout<<"Result of division is: "
				<<Divide(Dividend,Divisor);
	}
	catch(exception & exp) //handle CustomException,bad_alloc and etc.
	{
		cout<<exp.what()<<endl;
		cout<<"Sorry, can't continue!"<<endl;
	}
	return 0;
}
