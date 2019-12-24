//============================================================================
// Name        : starcat.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : star catalog new try
//============================================================================

#include <vector>
#include <memory>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <cstdlib>
#include <iostream>

struct Star
{
	struct RightAscension
	{
		int hour;
		float minute;
	};
	struct Declination
	{
		int degree;
		int minute;
	};

	std::string m_star_name;
	float m_magnitude;
	RightAscension ra;
	Declination dc;

};

void Get(std::ifstream & fm,Star * st,std::string& name)
{


	st->m_star_name=name;
	fm>>st->m_magnitude;
	fm>>st->ra.hour;
	fm>>st->ra.minute;;
	fm>>st->dc.degree;
	fm>>st->dc.minute;
	fm.get();
	//while(fm.get()!='\n')continue;
}

void Show (std::vector<Star*>::iterator & st)
{
	using std::setw;

		std::cout<<std::fixed<<std::right;
			std::cout<<std::setw(12)<<(*st)->m_star_name;
		std::cout<<std::setw(8)<<std::setprecision(2)<<(*st)->m_magnitude
			<<std::setw(10)<<(*st)->ra.hour<<std::setw(8)<<std::showpoint<<std::setprecision(1)
			<<(*st)->ra.minute<<std::setw(8)<<(*st)->dc.degree<<std::setw(10)<<(*st)->dc.minute<<'\n';
}

void Set(Star* temp_pr,std::string & test)
{
	using std::cout;
	using std::cin;
	temp_pr->m_star_name=test;
	cout<<"Enter star_size: ";
	cin>>temp_pr->m_magnitude;
	cout<<"Enter RA hour:";
	cin>>temp_pr->ra.hour;
	cout<<"Enter RA minutes:";
	cin>>temp_pr->ra.minute;
	cout<<"Enter declination degree:";
	cin>>temp_pr->dc.degree;
	cout<<"Enter declination minutes:";
	cin>>temp_pr->dc.minute;
	cin.get();

}

void title()
{
	using std::setw;
	std::cout<<std::setw(10)<<"Name "<<std::setw(14)<<"Magnitude"<<std::setw(8)<<"RA,h"
				<<setw(8)<<"RA,min"<<setw(8)<<"Dec,d"<<setw(10)<<"Dec,min"<<std::endl;
}

bool star_sort (const Star *star1,const Star *star2)
{
		if(star1->ra.hour == star2->ra.hour)
				return star1->ra.minute<star2->ra.minute;
		else if (star1->ra.minute==star2->ra.minute)
			return star1->m_magnitude<star2->m_magnitude;
		else
			return star1->ra.hour <star2->ra.hour;
}

void Write(std::ofstream& out,Star * st)
{
	out<<st->m_star_name<<std::endl;
		out	<<' '<<st->m_magnitude<<' '<<st->ra.hour<<' '<<st->ra.minute
			<<' '<<st->dc.degree<<' '<<st->dc.minute<<std::endl;
}
int main() {
	using std::setw;

	std::vector<Star*> star_catalog;
	Star *temp;
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

			temp = new Star;
			Get(fin,temp,name);
			star_catalog.push_back(temp);
	}

	fin.close();

	sort(star_catalog.begin(),star_catalog.end(),star_sort);

	title();
	for (auto st=star_catalog.begin();st !=star_catalog.end();st++)
					Show(st);

	int last_len=star_catalog.size();
	std::cout<<"Enter star's name (or q for quit):\n";
		std::string test_string;
	getline(std::cin,test_string);
			while(test_string != "q")
			{
				if (test_string == "q")
				{
					std::cout<<"End of the enter!"<<std::endl;
					break;
				}
				Star *temp;
				temp=new Star;
				Set(temp,test_string);
				star_catalog.push_back(temp);
				std::cout<<"Enter next star's name (or q for quit):";
				getline(std::cin,test_string);
			}


	std::ofstream fout("Star_Track.txt",std::ios::out | std::ios::app);
	if (!fout.is_open())
	{
		std::cerr<<"Can't open star_track.txt file for output.\n"<<std::endl;
		exit(EXIT_FAILURE);
	}

	std::cout<<"You added new stars: "<<std::endl;
	title();
	for (auto st=star_catalog.begin()+last_len;st !=star_catalog.end();st++)
	{
					Show(st);
					Write(fout,*st);
	}
	fout.close();
	delete temp;
return 0;
}
