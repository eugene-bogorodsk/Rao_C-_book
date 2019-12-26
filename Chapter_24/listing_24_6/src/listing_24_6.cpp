//============================================================================
// Name        : listing_24_6.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : priority queue and using push(),top() and pop() methods
//============================================================================

#include <iostream>
#include <queue>


int main() {
	using namespace std;
	priority_queue<int> pqIntegers;
	cout<<"Inserting {10,5,-1,20} into the priority_queue"<<endl;

	pqIntegers.push(10);
	pqIntegers.push(5);
	pqIntegers.push(-1);
	pqIntegers.push(20);

	cout<<"Deleting the "<<pqIntegers.size()<<" elements "<<endl;
	while(!pqIntegers.empty())
	{
		cout<<"Deleting topmost element: "<<pqIntegers.top()<<endl;
		pqIntegers.pop();
	}
	return 0;
}
