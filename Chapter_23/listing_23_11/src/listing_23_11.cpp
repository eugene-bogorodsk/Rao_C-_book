//============================================================================
// Name        : listing_23_11.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : using partition() and stable_partition() for
//              dividing a range of integers into even and odd values
//============================================================================

#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

bool isEven (const int& nNumber)
{
	return ((nNumber % 2) == 0);
}

template <typename T>
void DisplayContents(const T& Input)
{
	for (auto iElement = Input.cbegin();
			iElement != Input.cend();++iElement)
		cout<<*iElement<<' ';
	cout<<" Number of elements: "<<Input.size()<<endl;
}

int main() {
	vector<int> vecIntegers;

	for (int nNum=0; nNum < 10; ++nNum)
		vecIntegers.push_back (nNum);

	cout<<"The initial contents: "<<endl;
	DisplayContents(vecIntegers);

	vector<int> vecCopy (vecIntegers);

	cout<<"The effect of using partition():"<<endl;
	partition (vecIntegers.begin(), vecIntegers.end(),isEven);
	DisplayContents(vecIntegers);

	cout<<" The effect of using stable_partition():"<<endl;
	stable_partition (vecCopy.begin(), vecCopy.end(), isEven);
	DisplayContents(vecCopy);

	return 0;
}
