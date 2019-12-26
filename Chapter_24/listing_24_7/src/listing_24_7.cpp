//============================================================================
// Name        : listing_24_7.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : create an instance of the priority queue that stores the lowest value at the top
//============================================================================

#include <iostream>
#include <queue>


int main() {
	using namespace std;
	priority_queue <int,vector<int>,greater<int>> pqIntegers;//predicate greater<int>

	cout<<"Inserting {10,5,-1,20) int the priority queue"<<endl;
	pqIntegers.push(10);
	pqIntegers.push(5);
	pqIntegers.push(-1);
	pqIntegers.push(20);

	cout<<"Deleting "<<pqIntegers.size()<<" elements"<<endl;
	while (!pqIntegers.empty())
	{
		cout<<"Deleting topmost element "<<pqIntegers.top()<<endl;
		pqIntegers.pop();
	}
	return 0;
}
