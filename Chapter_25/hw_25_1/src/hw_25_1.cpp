//============================================================================
// Name        : hw_25_1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : combining a set of bits
//============================================================================

#include <iostream>
#include <bitset>

int main() {
	using namespace std;
	bitset <4> halfByte1("1011");
	bitset <4> halfByte2("1101");
	bitset <8> byte;

	for (size_t index = byte.size();index>0; --index)
	{
		if (index >halfByte1.size())
			byte[index-1]=halfByte1[index-halfByte1.size()-1];
		else
			byte[index-1]=halfByte2[index-1];
	}

	cout<<"halfByte1: "<<halfByte1<<"  dex: "<<halfByte1.to_ulong()<<endl;
	cout<<"halfByte2: "<<halfByte2<<"  dex: "<<halfByte2.to_ulong()<<endl;
	cout<<"byte: "<<byte<<"  dex: "<<byte.to_ulong()<<endl;

	return 0;
}
