//============================================================================
// Name        : listing_25_1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : create an instance of the class
//============================================================================

#include <iostream>
#include <bitset>


int main() {
	using namespace std;
	bitset <4> fourBits;
	cout<<"Initial contents of fourBits: "<<endl;

	bitset<5> fiveBits ("10101");
	cout<<"Initial contents of fiveBits:"<<fiveBits<<endl;
	bitset <8> eightBits(255);
	cout<<"Initial contents of eightBits: "<<eightBits<<endl;

	bitset <8> eightbits(eightBits);
	return 0;
}
