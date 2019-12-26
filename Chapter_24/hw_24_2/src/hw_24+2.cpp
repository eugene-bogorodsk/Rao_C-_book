//============================================================================
// Name        : hw_24+2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : using stack
//============================================================================

#include <iostream>
#include <stack>
#include <memory>
#include <sstream>


int main() {

	using namespace std;
	stack<unique_ptr<string>> storage;
	string temp;
/*
	getline(cin,temp);
	istringstream instr(temp);
	string word;
	while (instr>>word)
	{
		storage.push(make_unique<string>(word));

	}
*/// you can some way but it's better so
	do{
		cin>>temp;
		storage.push(make_unique<string>(temp));

	}while (cin.get() != '\n');

	while(!storage.empty())
	{
		cout<<*storage.top()<<" ";
		storage.pop();
	}

	return 0;
}
