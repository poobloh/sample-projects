#include "stdafx.h"
#include "Employee.h"
#include <string>

#ifndef WAITER
#define WAITER

class Waiter : public Employee
{
  public:
	  Waiter(long id = 0, string last = "", string first = "", 
		   int years = 0, double tips = 0);
	  void display(ostream &out) const;
	  void calc_salary();


  private:
	  double myProfit;
	  double mySalary;
	  int myYears;
	  double myTips;
};

inline Waiter::Waiter(long id, string last, string first, int years, double tips) 
			 : Employee(id, last, first), myYears(years), myTips(tips)
{
	Waiter::calc_salary();
	Employee::setMyType('W');
}

inline void Waiter::display(ostream &out) const
{
	Employee::display(out);
	out<<"("<<myYears<<" years of service) - $"<<mySalary<<endl;
}

inline void Waiter::calc_salary()
{
	mySalary = 3000 + myTips;
};

#endif