//============================================================================
// Name        : hw_23_2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : using copy() algorithm
//============================================================================

#include <algorithm>
#include <vector>
#include <list>
#include <deque>
#include <iostream>
using namespace std;

int main() {
	vector <string> vcstr{"hren","vam","vsem"};
	list<string> lsstr{"get","ears","dead","donkey","but","pyetalovsky","district"};
	deque<string> dqstr(vcstr.size());
	auto end_of_deque=copy(vcstr.begin(),vcstr.end(),dqstr.begin());
	dqstr.resize(vcstr.size()+lsstr.size());
	for_each(dqstr.begin(),dqstr.end(),[](string & str){cout<<str<<" ";});
	copy(lsstr.begin(),lsstr.end(),end_of_deque);
	cout<<endl;
	for_each(dqstr.begin(),dqstr.end(),[](string & str){cout<<str<<" ";});
	return 0;
}
