//============================================================================
// Name        : listing_25_2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : logical operations with a set of bits
//============================================================================

#include <iostream>
#include <bitset>


int main() {
	using namespace std;
	bitset <8> inputBits;
	cout<<"Enter a 8-bit sequence: ";

	cin>>inputBits;//save the user input in the set of bits
	cout<<"You entered: "<<inputBits<<endl;
	cout<<"Number of 1s you supplied: "<<inputBits.count()<<endl;
	cout<<"Number of 0s you supplied: ";
	cout<<inputBits.size()-inputBits.count()<<endl;

	bitset <8> inputFlipped (inputBits);
	inputFlipped.flip();

	cout<<"Flipped version is: "<<inputFlipped<<endl;

	cout<<"Result of AND,OR and XOR vetween the two: "<<endl;
	cout<<inputBits<<" & "<<inputFlipped<<" = ";
	cout<<(inputBits & inputFlipped) <<endl;

	cout<<inputBits<<" | "<<inputFlipped<<" = ";
	cout<<(inputBits | inputFlipped )<<endl;

	cout<<inputBits<<" ^ "<<inputFlipped<<" = ";
	cout<<(inputBits ^ inputFlipped)<<endl;

	return 0;
}
