#include "stdafx.h"
#include "Employee.h"
#include <string>

#ifndef CHEF
#define CHEF

class Chef : public Employee
{
  public:
	  Chef(long id = 0, string last = "", string first = "", 
		   string expertise = "", double profit = 0);
	  void display(ostream &out) const;
	  void calc_salary();


  private:
	  double myProfit;
	  double mySalary;
	  string myExpertise;
};

inline Chef::Chef(long id, string last, string first, string expertise, double profit) 
			 : Employee(id, last, first), myExpertise(expertise), myProfit(profit)
{
	Chef::calc_salary();
	Employee::setMyType('C');
}

inline void Chef::display(ostream &out) const
{
	Employee::display(out);
	out<<"("<<myExpertise<<" cuisine) - $"<<mySalary<<endl;
}

inline void Chef::calc_salary()
{
	mySalary = 10000 + (myProfit*.2);
};

#endif