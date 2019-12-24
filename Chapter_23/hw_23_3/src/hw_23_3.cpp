//============================================================================
// Name        : hw_23_3.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : star application
//============================================================================

#include <vector>
#include <memory>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <string>
#include <algorithm>
#include "stars.h"


void title()
{
	using std::setw;
	std::cout<<std::setw(10)<<"Name "<<std::setw(14)<<"Magnitude"<<std::setw(8)<<"RA,h"
				<<setw(8)<<"RA,min"<<setw(8)<<"Dec,d"<<setw(10)<<"Dec,min"<<std::endl;
}

class star_sort
{
public:
	bool operator()(const std::shared_ptr<Star> lhs,const std::shared_ptr<Star> rhs)
	{
		if( lhs->GetRAH() == rhs->GetRAH())
				return lhs->GetRAM()<rhs->GetRAM();
		else if (lhs->GetRAM() ==rhs->GetRAM())
			return lhs->GetMag() < rhs->GetMag();
		else
			return lhs->GetRAH() < rhs->GetRAH();
	}
};
int main() {
	using std::cout;
	using std::endl;
	using std::cin;

	std::vector<std::shared_ptr<Star>> star_catalog;
	std::shared_ptr<Star> temp;
	std::ifstream fin;
	fin.open("Star_Track.txt");

	if (!fin.is_open())
	{

			std::cerr<<"Can't open star_track.txt file for output.\n"<<std::endl;
			exit(EXIT_FAILURE);
	}
	std::string name;
	while(getline(fin,name))
		{
			temp=std::make_shared<Star>();
			temp->GetCatalog(fin,name);
			star_catalog.push_back(temp);
		}
	fin.clear();
	fin.close();

	std::sort(star_catalog.begin(),star_catalog.end(),star_sort());

	title();
	for (auto st=star_catalog.begin();st !=star_catalog.end();st++)
		(*st)->Show();


	size_t length_of_current_catalog=star_catalog.size();
 	cout<<"Enter star's name (or q for quit):\n";
 	std::string temp_name;
	while(temp_name != "q")
	{
		getline(cin,temp_name);
		if (temp_name == "q")
		{
			cout<<"End of the enter!"<<endl;
			break;
		}
		temp=std::make_shared<Star>();
		temp->Set(temp_name);
		star_catalog.push_back(temp);
		cout<<"Enter next star's name (or q for quit):";
		getline(cin,temp_name);
	}
	cin.clear();

	std::ofstream fout("Star_Track.txt",std::ios::out | std::ios::app);
		if (!fout.is_open())
		{
			std::cerr<<"Can't open star_track.txt file for output.\n"<<std::endl;
			exit(EXIT_FAILURE);
		}

		std::cout<<"You added followed stars: "<<std::endl;
		title();
		for (auto st=star_catalog.begin()+length_of_current_catalog;st !=star_catalog.end();st++)
		{
				(*st)->Show();
				(*st)->Write(fout);
		}
		fout.clear();
		fout.close();
	return 0;
}
