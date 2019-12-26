/*
 * stars.h
 *
 *  Created on: 23 дек. 2019 г.
 *      Author: Eugene
 */

#ifndef STARS_H_
#define STARS_H_

#include <string>
#include <fstream>

class Star
{
private:
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

public:
	Star();
	Star(const std::string& str,float _mg,int _ra_h,float _ra_min,int _d_dg,int _d_min);
	~Star();
	Star(const Star & st);
	Star operator = (const Star & st);
	void GetCatalog(std::ifstream & fm,const std::string & name);
	void Set(const std::string & name);
	void Show();
	void Write(std::ofstream & fout);
	int GetRAH(){return ra.hour;}
	float GetRAM(){return ra.minute;}
	float GetMag(){return m_magnitude;}

};




#endif /* STARS_H_ */
