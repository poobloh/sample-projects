#include "stdafx.h"
#include <iostream>
using namespace std;

#include <string>
#include "Employee.h"
#include "Owner.h"
#include "Chef.h"
#include "Waiter.h"

int main()
{
	Owner own(12345, "Castro", "Brandon", 6000);
	Chef chef1(77777, "Doe", "John", "French", 6000);
	Chef chef2(62563, "Burg", "Mary", "Italian", 6000);
	Waiter wait1(96782, "PlusPlus", "C", 3, 1000);
	Waiter wait2(85732, "Inheritance", "Polly", 5, 1500);
	Waiter wait3(76543, "Oriented", "Object", 7, 1700);

	cout<<own<<chef1<<chef2<<wait1<<wait2<<wait3<<endl<<"\nFAULTY CODE: \n";
	
	/*I couldn't find the reason why the following code wouldn't work, 
	  it prints out all the members of the array but uses Employee's display(), 
	  not the corresponding class's display().

	  Employee's display() is virtual and correctly works (see above cout's).

	  I'm certain it had to do with making the set of arrays of class Employee 
	  and it might be a simple fix but I ran out of time.*/

	Employee database[6];
	database[0] = own;
	database[1] = chef1;
	database[2] = chef2;
	database[3] = wait1;
	database[4] = wait2;
	database[5] = wait3;

	for(int i = 0; i < 6; i++)
	{
		database[i].display(cout);
		cout<<endl;
	}
}