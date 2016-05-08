#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

#ifndef EMPLOYEE
#define EMPLOYEE

class Employee
{
  public:
	  Employee(long id = 0, string last = "", string first = "");
	  virtual void display(ostream &out) const { out<<"ID: "<<myIdNum<<' '<<myLastName<<", "<<myFirstName<<" '"
		  <<myType<<"'"; };
	  void setMyType(char a);
  
  private:
	  long myIdNum;
	  string myLastName, 
			 myFirstName;
	  char myType;
};

inline Employee::Employee(long id, string last, string first) 
				: myIdNum(id), myLastName(last), myFirstName(first)
{

}

/*void Employee::display(ostream &out) const
{
	out<<myIdNum<<' '<<myLastName<<", "<<myFirstName<<" '"
		<<myType<<"'";
}*/

inline void Employee::setMyType(char a)
{
	myType = a;
}

inline ostream &operator<<(ostream &out, const Employee &emp)
{
	emp.display(out);
	return out;
};

#endif
