
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <memory>
#include "stars.h"


Star::~Star(){}
Star::Star()
{
m_star_name="no name";
m_magnitude=0.0;
ra.hour=0; ra.minute=0.0;
dc.degree=0;dc.minute=0;
}
Star::Star(const std::string& str,float _mg,int _ra_h,float _ra_min,int _d_dg,int _d_min):
		m_star_name(str),m_magnitude(_mg),ra({_ra_h,_ra_min}),dc({_d_dg,_d_min}){}


Star::Star(const Star & st)
{
	m_star_name=st.m_star_name;
	m_magnitude=st.m_magnitude;
	ra.hour=st.ra.hour;
	ra.minute=st.ra.minute;
	dc.degree=st.dc.degree;
	dc.minute=st.dc.minute;
}

Star Star::operator = (const Star & st)
{
	if (this !=& st)
	{
		m_star_name=st.m_star_name;
		m_magnitude=st.m_magnitude;
		ra.hour=st.ra.hour;
		ra.minute=st.ra.minute;
		dc.degree=st.dc.degree;
		dc.minute=st.dc.minute;
	}
	return *this;
}
void Star:: GetCatalog(std::ifstream & fm,const std::string & name)
{
	m_star_name=name;
	fm>>m_magnitude;
	fm>>ra.hour;
	fm>>ra.minute;;
	fm>>dc.degree;
	fm>>dc.minute;
	fm.get();

}
void Star::Set(const std::string & name)
{
	using std::cout;
	using std::cin;
	m_star_name=name;
	cout<<"Enter star_size: ";
	cin>>m_magnitude;
	cout<<"Enter RA hour:";
	cin>>ra.hour;
	cout<<"Enter RA minutes:";
	cin>>ra.minute;
	cout<<"Enter declination degree:";
	cin>>dc.degree;
	cout<<"Enter declination minutes:";
	cin>>dc.minute;
	cin.get();
}
void Star::Show()
{
	using std::setw;

		std::cout<<std::fixed<<std::right;
			std::cout<<std::setw(12)<<m_star_name;
		std::cout<<std::setw(8)<<std::setprecision(2)<<m_magnitude
			<<std::setw(10)<<ra.hour<<std::setw(8)<<std::showpoint<<std::setprecision(1)
			<<ra.minute<<std::setw(8)<<dc.degree<<std::setw(10)<<dc.minute<<'\n';

}

void Star::Write(std::ofstream& out)
{
	out<<m_star_name<<std::endl;
		out	<<' '<<m_magnitude<<' '<<ra.hour<<' '<<ra.minute
			<<' '<<dc.degree<<' '<<dc.minute<<std::endl;
}
