
#include<iostream>
#include<stdio.h>
using namespace std;

class Employee
{
private:
	int eid;
	char eName[50];
	double basic, da, hra, ta, gross;
public:
	void setData();
	void DisplayData();
	double CalculateSalary();
};

void Employee::setData()
{
	std::cout << "Enter Employee ID" << "\n";
	std::cin >> eid;
	std::cout << "Enter Employee Name" << "\n";
	std::cin >> eName;
	std::cout << "Enter Base Salary" << "\n";
	std::cin >> basic;
}

double Employee::CalculateSalary()
{
	da = .15*basic;
	hra = .25*basic;
	ta = .12*basic;
	gross = basic + da + hra + ta;
	return gross;
}

void Employee::DisplayData()
{
	std::cout << "Employee ID:	" << eid << endl;
	std::cout << "Employee Name:	" << eName << endl;
	std::cout << "Gross Salary	" << gross << endl;
}

int main()
{
	Employee obj[3];
	int i = 1;
	double totalsalary = 0.0, avgsalary = 0.0;
	double maxsalary = -999;
	double minsalary = 999999999999;
	int max, min = 0;
	char ch;
	for (i = 1; i <= 3; i++)
	{
		obj[i].setData();
		totalsalary += obj[i].CalculateSalary();
		if (maxsalary > obj[i].CalculateSalary())
		{
			maxsalary = obj[i].CalculateSalary();
			max = i;
		}
		if (minsalary < obj[i].CalculateSalary())
		{
			minsalary = obj[i].CalculateSalary();
			min = i;
		}
	}
	avgsalary = totalsalary / 3;
	std::cout << "Total Salary\t" << totalsalary << endl;
	std::cout << "Maximum Salary\t" << maxsalary << endl;
	std::cout << "Employee ID\t" << max << endl;
	std::cout << "Minimum Salary\t" << minsalary << endl;
	std::cout << "Employee ID\t" << min << endl;
	std::cout << "Average Salary\t" << avgsalary << endl;
	std::cout << "Enter space to continue";
	std::cin >> ch;
	return 0;
}

