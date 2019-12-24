//============================================================================
// Name        : listing_23_10.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : using sort(), binary_search() and unique()
//============================================================================

#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

template <typename T>
void DisplayContents(const T& Input)
{
	for (auto iElement = Input.cbegin();
			iElement !=Input.cend();
			++iElement)
		cout<<*iElement<<endl;
}
int main() {
	vector<string> vecNames{"Jhon Doe","Jack Nicholson",
		"Sean Penn","Anna Hoover"};
	//inserting dublicates into a vector
	vecNames.push_back("Jack Nicholson");

	cout<<"The initial contents of the vector are: "<<endl;
	DisplayContents(vecNames);

	cout<<"The sorted vector contains neames in the order: "<<endl;
	sort(vecNames.begin(),vecNames.end());
	DisplayContents(vecNames);

	cout<<"Searching for \"John Doe\" using 'binary_search':"<<endl;
	bool bElementFound = binary_search (vecNames.begin(),
			vecNames.end(), "John Doe");

	if (bElementFound)
		cout<<"Result: \"John Doe\" was found in the vector!"<<endl;
	else
		cout<<"Element not found "<<endl;

	//delete adjacent duplicates
	auto iNewEnd = unique (vecNames.begin(), vecNames.end());
	vecNames.erase (iNewEnd,vecNames.end());
	cout<<"The contents of he vector after using 'unique':"<<endl;
	DisplayContents(vecNames);

	return 0;
}
