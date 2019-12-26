//============================================================================
// Name        : listing_24_4.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : insert,viewing and retrieval of items in the queue of integers
//============================================================================

#include <iostream>
#include <queue>

int main() {
	using namespace std;
	queue<int>	qIntegers;

	cout<<"Inserting {10,5,-1,20} into queue "<<endl;
	qIntegers.push(10);
	qIntegers.push(5);
	qIntegers.push(-1);
	qIntegers.push(20);

	cout<<"Queue contains "<<qIntegers.size()<<" elemets"<<endl;
	cout<<"Element at front: "<<qIntegers.front()<<endl;
	cout<<"Element at back: "<<qIntegers.back()<<endl;

	while(qIntegers.size() != 0)
	{
		cout<<"Deleting element: "<<qIntegers.front()<<endl;
		qIntegers.pop();
	}

	if (qIntegers.empty())
		cout<<"The queue is noe empty!"<<endl;

	return 0;
}
