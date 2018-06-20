#include <iostream>
#include <string>

using namespace std;

class Employee
{
private:
	string name;
public:
	string getName() const { return name; }
	void setName(string name) { this->name = name; }
	virtual void display()
	{
		cout << name << endl;
	}
};

class HourlyEmployee : public Employee
{
private:
	int hourlyWage;
public:
	int getHourlyWage() const { return hourlyWage; }
	void setHourlyWage(int hourlyWage) { this->hourlyWage = hourlyWage; }
	void display()
	{
		cout << getName() << " - $" << getHourlyWage() << "/hour";
	}
};

class SalaryEmployee : public Employee
{
private:
	int salary;
public:
	int getSalary() const { return salary; }
	void setSalary(int salary) { this->salary = salary; }
	void display()
	{
		cout << getName() << " - $" << getSalary() << "/year";
	}
};

int main()
{
	Employee * employees[3];
	char userChoice;

	for (int i = 0; i < 3; i++) // Employee Type Selection
	{
		cout << "Employee Type: ";
		cin >> userChoice;

		string name;
		cout << "Enter name: ";
		cin >> name;
		
		if (userChoice == 'h')
		{
			int wage;
			cout << "Enter hourly wage: ";
			cin >> wage;

			HourlyEmployee * hourlyEmployee = new HourlyEmployee;

			hourlyEmployee->setName(name);
			hourlyEmployee->setHourlyWage(wage);

			employees[i] = hourlyEmployee;

		}

		else
		{
			int salary;
			cout << "Enter yearly salary: ";
			cin >> salary;

			SalaryEmployee * salaryEmployee = new SalaryEmployee;

			salaryEmployee->setName(name);
			salaryEmployee->setSalary(salary);

			employees[i] = salaryEmployee;
		}
	}

	for (int i = 0; i < 3; i++)
	{
		employees[i]->display();
		cout << endl;
	}



	for (int i = 0; i < 3; i++)
	{
		delete employees[i];
	}



	system("pause");

	return 0;
}