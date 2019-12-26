//============================================================================
// Name        : listing_27_2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : using the cout object to display number pi and the area of the circle
//				in an exponential representation and with a fixed point
//============================================================================

#include <iostream>
#include <iomanip>

int main() {
	using namespace std;
	const double Pi = (double)22.0/7;
	cout<<"Pi = "<<Pi<<endl;

	cout<<endl<<"Setting precision to 7: "<<endl;
	cout<<setprecision(7)<<endl;
	cout<<fixed<<"Fixed Pi = "<<Pi<<endl;
	cout<<scientific<<"Sceintific"<<Pi<<endl;

	cout<<endl<<"Settings precision to 10:"<<endl;
	cout<<setprecision(10);
	cout<<"Pi = "<<Pi<<endl;
	cout<<fixed<<"Fixed Pi = "<<Pi<<endl;
	cout<<scientific<<"Scientific Pi = "<<Pi<<endl;

	cout<<endl<<"Enter a radius: ";
	double Radius = 0.0;
	cin>>Radius;
	cout<<"Area of circle: "<<Pi*Radius*Radius<<endl;

	return 0;
}
