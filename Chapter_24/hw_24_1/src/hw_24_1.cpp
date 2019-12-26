//============================================================================
// Name        : hw_24_1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description :priority queue
//============================================================================

#include <iostream>
#include <queue>
#include <memory>

class CPerson
{
public:
	int Age;
	bool IsFemale;

	CPerson():Age(0),IsFemale(true){}
	CPerson(int _age,bool _sex=true):Age(_age),IsFemale(_sex){}

	friend	 std::ostream & operator<<(std::ostream & os,const CPerson & cp )
	{
		os<<"age: "<<cp.Age<<" "<<"Sex :"<<cp.IsFemale<<'\n';
		return os;
	}
	bool operator <(const CPerson &  rhs) const
	{
		int lp=0;int rp=0;
		if (Age>50) lp++;
		if (IsFemale) lp++;
		if (rhs.Age > 50) rp++;
		if (rhs.IsFemale) rp++;
		if (lp<rp)
			return true;
		else
			return false;
	}

	friend bool operator <(const std::unique_ptr<CPerson> & lhs,const std::unique_ptr<CPerson> & rhs)
	{
		return lhs->Age > rhs->Age;
	}
	friend std::ostream & operator<<(std::ostream& os,const std::unique_ptr<CPerson> & cp)
	{
		os<<"age: "<<cp->Age<<" "<<"Sex :"<<cp->IsFemale<<'\n';
		return os;
	}
};
int main() {

	using namespace std;
		priority_queue<unique_ptr<CPerson>> pr_queue_person;

		priority_queue<CPerson> queue_person;

			queue_person.push(CPerson(40,0));
			queue_person.push(CPerson(20,1));
			queue_person.push(CPerson(55,0));
			queue_person.push(CPerson(30,0));
			queue_person.push(CPerson(14,1));

			pr_queue_person.push(make_unique<CPerson>(50,0));
			pr_queue_person.push(make_unique<CPerson>(20,1));
			pr_queue_person.push(make_unique<CPerson>(55,0));
			pr_queue_person.push(make_unique<CPerson>(30,0));
			pr_queue_person.push(make_unique<CPerson>(14,1));

	cout<<queue_person.size()<<endl;
	cout<<"we get: "<<queue_person.top()<<endl;
	while (!queue_person.empty())
	{
		cout<<queue_person.top()<<endl;;
		queue_person.pop();
	}
	cout<<pr_queue_person.size()<<endl;
	cout<<"We've got: "<<pr_queue_person.top()<<endl;

	return 0;
}
