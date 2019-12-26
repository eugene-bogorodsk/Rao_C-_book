//============================================================================
// Name        : listing_27_10.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : writing the structure to the binary file and restoring from the same file
//============================================================================

#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>

struct Human
{
	Human():Name("none"),Age(0),DOB("none"){}
	Human(const char * inName,int inAge,const char* inDOB):Age(inAge)
	{
		strcpy(Name,inName);
		strcpy(DOB,inDOB);

	}

	char Name[30];
	int Age;
	char DOB[20];
};

int main() {
	using namespace std;

	Human Input("Siddhartha Rao",101,"May 1910");

	ofstream fsOut ("MyBinary.bin", ios_base::out | ios_base::binary);
	if (fsOut.is_open())
	{
		cout<<"Writing one object of Human to a binary file"<<endl;
		fsOut.write(reinterpret_cast <const char *>(&Input),sizeof(Input));
		fsOut.close();
	}

	ifstream fsIn ("MyBinary.bin",ios_base::in | ios_base::binary);
	if (fsIn.is_open())
	{
		Human somePerson;
		fsIn.read((char*) & somePerson,sizeof(somePerson));
		cout<<"Reading information from bynary file: "<<endl;
		cout<<"Name = "<<somePerson.Name<<endl;
		cout<<"Age = "<<somePerson.Age<<endl;
		cout<<"Date of birth = "<<somePerson.DOB<<endl;

	}
	return 0;
}
