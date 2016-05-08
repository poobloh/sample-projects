#include "stdafx.h"
#include "Employee.h"
#include <string>

#ifndef OWNER
#define OWNER

class Owner : public Employee
{
  public:
	  Owner(long id = 0, string last = "", string first = "", double profit = 0);
	  void display(ostream &out) const;
	  void calc_salary();


  private:
	  double myProfit;
	  double mySalary;
};

inline Owner::Owner(long id, string last, string first, double profit) 
			 : Employee(id, last, first), myProfit(profit)
{
	Owner::calc_salary();
	Employee::setMyType('O');
}

inline void Owner::display(ostream &out) const
{
	Employee::display(out);
	out<<" - $"<<mySalary<<endl;
}

inline void Owner::calc_salary()
{
	Owner::mySalary = 15000 + (myProfit*.6);
};

#endif