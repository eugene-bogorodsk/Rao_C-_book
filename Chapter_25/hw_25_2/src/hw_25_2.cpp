//============================================================================
// Name        : hw_25_2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : inverting bit sets
//============================================================================

#include <iostream>
#include <bitset>

int main() {
	using namespace std;
	bitset <8> initial(199);
	bitset <8> inverting(initial);
	inverting.flip();
	cout<<"initial: "<<initial<<endl;
	cout<<"inverting: "<<inverting<<endl;
	return 0;
}
