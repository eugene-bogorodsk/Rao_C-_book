//============================================================================
// Name        : hw_23_1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {

	vector<string> vs1{"add","play","game","strike","bridge"};
	vector<string> vs2{" kaka"," football"," soker"," internet"," for Omsk"};
	vector<string> total(vs1.size());
	transform (vs1.begin(),vs1.end(),vs2.begin(),total.begin(),
				[](string &str1,string &str2){return str1+str2;});
	for_each(vs1.begin(),vs1.end(),[](string& str){cout<<str<<" ";});
	cout<<endl;
	sort(total.begin(),total.end(),[](string &str1,string &str2){return str1>str2;});
	for_each (total.begin(),total.end(),[](string &str){cout<<str<<" ";});

	return 0;
}
