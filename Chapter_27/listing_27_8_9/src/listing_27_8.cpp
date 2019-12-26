//============================================================================
// Name        : listing_27_8.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : creating a new text file and writing to it using "ofstream" class object
//============================================================================

#include <iostream>
#include <fstream>


int main() {
	using namespace std;

	ofstream myFile;
	myFile.open("HelloFile.txt",ios_base::out);

	if(myFile.is_open())
	{
		cout<<"File open successful"<<endl;
		myFile<<"My first text file!"<<endl;
		myFile<<"Hello file!";

		cout<<"Finished writing to file, will close now"<<endl;
		myFile.close();

	}

	ifstream myfile;
	myfile.open("HelloFile.txt",ios_base::in);

	if (myfile .is_open())
	{
		cout<<"File open successful. It contains: "<<endl;
		string fileContents;
		while (myfile.good())
		{
			getline(myfile,fileContents);
			cout<<fileContents<<endl;
		}

		cout<<"Finished reading file, will close now "<<endl;
		myfile.close();
	}
	else
		cout<<"open() failed: check if file is in rights folder"<<endl;


	return 0;
}
