//============================================================================
// Name        : listing_28_4.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : order of destruction of local objects in case of exception
//============================================================================

#include <iostream>

struct StructA
{
	StructA(){std::cout<<"Constructed a struct A"<<std::endl;}
	~StructA(){std::cout<<"Destroyed a struct A"<<std::endl;}
};

struct StructB
{
	StructB(){std::cout<<"Constructed a struct B"<<std::endl;}
	~StructB(){std::cout<<"Destroyed a struct B"<<std::endl;}
};

void FuncB() //transfer
{
	using std::cout;
	using std::endl;
	cout<<"In Func B"<<endl;
	StructA objA;
	StructB objB;
	cout<<"About to throw up!"<<endl;
	throw "Throwing for the heck of it";

}

void FuncA()
{
	using std::cout;
	using std::endl;
	try
	{
		cout<<"In Func A"<<endl;
		StructA objA;
		StructB objB;
		FuncB();
		cout<<"FuncA: returning to caller "<<endl;
	}
	catch(const char * exp)
	{
		cout<<"FuncA: Caught exception,it says: "<<exp<<endl;
		cout<<"FuncA: Handled it here,will not throw to caller"<<endl;
		//throw;//remove the comment for the transfer to main()
	}
}
int main()
{
	using namespace std;

	cout<<"main(): Started execution"<<endl;

	try
	{
		FuncA();
	}
	catch(const char * exp)
	{
		cout<<"Exception: "<<exp<<endl;
	}

	cout<<"main(): exiting gracefully"<<endl;

	return 0;
}
