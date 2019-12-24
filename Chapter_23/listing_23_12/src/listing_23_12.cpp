//============================================================================
// Name        : listing_23_12.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : using lower_bound() and upper_bound() for insert into sorted collection
//============================================================================

#include <algorithm>
#include <list>
#include <iostream>
using namespace std;

template <typename T>
void DisplayContents(const T& input)
{
	for (auto el = input.begin(); el != input.end(); ++el)
		cout<<*el<<endl;

}

int main() {

	list <string> listNames{"Jhon Doe","Brad Pitt","Jack Nicholson","Sean Penn","Anna Hoover"};

	cout<< "The sorted contents of the list are: "<<endl;
	listNames.sort();
	DisplayContents(listNames);

	cout<<" The lowest index where \"Brad Pitt\" can be inserted is: ";
	auto iMinInsertPos = lower_bound (listNames.begin(), listNames.end(),"Brad Pitt");
	cout<<distance (listNames.begin(),iMinInsertPos)<<endl;

	cout<<" The highest index where \"Brad Pitt\" can be inserted is: ";
	auto iMaxInsertPos = upper_bound (listNames.begin (), listNames.end(), "Brad Pitt");
	cout<<distance (listNames.begin(), iMaxInsertPos)<<endl;

	cout<<endl;

	cout<<" List after inserting Brad Pitt in sorted order: "<<endl;
	listNames.insert (iMinInsertPos, "Brad Pitt");

	DisplayContents(listNames);
	return 0;
}
