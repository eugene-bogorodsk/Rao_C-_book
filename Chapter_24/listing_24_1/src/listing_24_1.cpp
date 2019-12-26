//============================================================================
// Name        : listing_24_1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : stack class function-member
//============================================================================

#include <iostream>
#include <stack>

int main() {
	using namespace std;
	stack<int> stackInts;

	cout<<"Pushing {25,10,-1,5} on stack in that order:"<<endl;
	stackInts.push(25);
	stackInts.push(10);
	stackInts.push(-1);
	stackInts.push(5);

	cout<<"Stack contains "<<stackInts.size()<<" elements "<<endl;

	while(stackInts.size() != 0)
	{
		cout<<"Popping topmost element: "<<stackInts.top()<<endl;
		stackInts.pop();
	}

	if (stackInts.empty())
		cout<<"Popping all elements empties stack!"<<endl;

	return 0;
}
