//============================================================================
// Name        : listing_26_4.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : using unique_ptr class
//============================================================================

#include <iostream>
#include <memory>

class Fish
{
public:

	Fish(){std::cout<<"Fish: Constructed!"<<std::endl;}
	virtual ~Fish() {std::cout<<"Fish: Destructed!"<<std::endl;}
	virtual void Swim() const {std::cout<<"Fish swims in water"<<std::endl;}
};

class Carp:public Fish
{
public:
	Carp():Fish(){std::cout<<"Now Carp."<<std::endl;}
	Carp(const Fish & f):Fish(){}
	~Carp(){std::cout<<"Carp died."<<std::endl;}
	void Swim() const {std::cout<<"Carp can swim too."<<std::endl;}
};

void MakerFishSwim(const std::unique_ptr<Fish> & inFish)
{
	inFish->Swim();
}

int main() {
	using namespace std;

	unique_ptr<Fish> smartFish (new Fish);

	smartFish->Swim();
	MakerFishSwim(smartFish); //ok cause MekerFishSwim allows refer

	unique_ptr<Fish> copySmartFish;
	unique_ptr<Fish> pr_Carp (new Carp);
	pr_Carp->Swim();

	//unique_ptr<Carp> pr_carp_again (new Fish);
	//pr_carp_again->Swim();

	//copySmartFish =smartFish; //mistake: operator = closed


	return 0;
}
