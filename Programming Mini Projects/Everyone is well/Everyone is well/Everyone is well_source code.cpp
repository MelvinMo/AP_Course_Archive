#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream> 

using namespace std;

class Person
{
protected:
	string name;
	long long nationalcode = 0;
	string gender;
	long long salary = 0;
	long long basesalary = 0;
public:
	void setBasesalary(long long a)
	{
		basesalary = a;
	}
};

class Student :public Person
{
protected:
	long long studentnumber;
public:
	Student(string n, long long nc, string g, long long sn)
	{
		basesalary = 500000;
		name = n;
		nationalcode = nc;
		gender = g;
		studentnumber = sn;
	}
	long long expenses(long int c)
	{
		return salary - c;
	}
};

class Academics:public Person
{
protected:
	long long academicnumber;
	int workinghourperweek;
	string ranking;
public:
	float taxrate = 0.1;
	long long salary = (this->basesalary + (this->workinghourperweek * 150000)) - (taxrate * (this->basesalary + (this->workinghourperweek * 150000)));
	Academics(string n, long long nc, string g, long long an, int wh, string rank)
	{
		name = n;
		nationalcode = nc;
		gender = g;
		academicnumber = an;
		workinghourperweek = wh;
		ranking = rank;
	}
	long long salaryCal()
	{
		return this->basesalary + (this->workinghourperweek * 150000);
	}
	long long taxCal()
	{
		return taxrate * (this->basesalary + (this->workinghourperweek * 150000));
	}
	long long salaryPay()
	{
		return (this->basesalary + (this->workinghourperweek * 150000)) - (taxrate * (this->basesalary + (this->workinghourperweek * 150000)));
	}
	long long expenses(long int c)
	{
		return salary - c;
	}
};

class Employee :public Person
{
protected:
	long long employeenumber;
public:
	float taxrate = 0.15;
	long long salary = (this->basesalary) - (taxrate * (this->basesalary));
	Employee(string n, long long nc, string g, long long en, long long bs)
	{
		name = n;
		nationalcode = nc;
		gender = g;
		employeenumber = en;
		basesalary = bs;
	}
	long long salaryCal()
	{
		return this->basesalary;
	}
	long long taxCal()
	{
		return taxrate * this->basesalary;
	}
	long long salaryPay()
	{
		return (this->basesalary) - (taxrate * (this->basesalary));
	}
	long long expenses(long int c)
	{
		return salary - c;
	}
};

class ParttimeEmployee :public Person
{
protected:
	long long employeenumber;
	int workinghourperweek;
public:
	float taxrate = 0.15;
	long long salary = (this->basesalary) - (taxrate * (this->basesalary));
	ParttimeEmployee(string n, long long nc, string g, long long en, int wh)
	{
		name = n;
		nationalcode = nc;
		gender = g;
		employeenumber = en;
		workinghourperweek = wh;
		basesalary = 0;
	}
	long long salaryCal()
	{
		return this->workinghourperweek * 100000;
	}
	long long taxCal()
	{
		return taxrate * (this->workinghourperweek * 100000);
	}
	long long salaryPay()
	{
		return (this->workinghourperweek * 100000) - (taxrate * (this->workinghourperweek * 100000));
	}
	long long expenses(long int c)
	{
		return salary - c;
	}
};

class WorkingStudent :public Person
{
protected:
	long long studentnumber;
	long long employeenumber;
	int workinghourperweek;
public:
	long long salary = (this->workinghourperweek * 30000);
	WorkingStudent(string n, long long nc, string g, long long sn, int wh)
	{
		basesalary = 500000;
		name = n;
		nationalcode = nc;
		gender = g;
		studentnumber = sn;
		employeenumber = studentnumber;
		workinghourperweek = wh;
		basesalary = 0;
	}
	long long salaryCal()
	{
		return this->workinghourperweek * 30000;
	}
	long long salaryPay()
	{
		return this->workinghourperweek * 30000;
	}
	long long expenses(long int c)
	{
		return salary - c;
	}
};

int main()
{
	string type;
	cout << "Please enter the type of person: (student/academics/employee/parttimeemployee/workingstudent)" << endl;
	cin >> type;
	system("cls");
	if (type == "student")
	{
		Student std("ali",1234567890,"male",9876543);
		cout << "Poor student without salary!!!";
	}
	if (type == "academics")
	{
		string typeacadamics;
		cout << "Please enter the type of academics: (instructor/assistantprofessor/associateprofessor/fullprofessor)" << endl;
		cin >> typeacadamics;
		system("cls");
		if (typeacadamics == "instructor")
		{
			Academics acd("sadeghi", 1324567890, "female", 345678, 16, "instructor");
			acd.setBasesalary(3000000);
			cout << acd.salaryCal() << endl;
			cout << acd.taxCal() << endl;
			cout << acd.salaryPay() << endl;
		}
		if (typeacadamics == "assistantprofessor")
		{
			Academics acd("mahmoudi", 1432567890, "female", 354678, 14, "assistantprofessor");
			acd.setBasesalary(4000000);
			cout << acd.salaryCal() << endl;
			cout << acd.taxCal() << endl;
			cout << acd.salaryPay() << endl;
		}
		if (typeacadamics == "associateprofessor")
		{
			Academics acd("karimizade", 4132567890, "male", 336547, 12, "associateprofessor");
			acd.setBasesalary(5000000);
			cout << acd.salaryCal() << endl;
			cout << acd.taxCal() << endl;
			cout << acd.salaryPay() << endl;
		}
		if (typeacadamics == "fullprofessor")
		{
			Academics acd("samavati", 3142567890, "male", 326547, 10, "fullprofessor");
			acd.setBasesalary(6000000);
			cout << acd.salaryCal() << endl;
			cout << acd.taxCal() << endl;
			cout << acd.salaryPay() << endl;
		}
	}
	if (type == "employee")
	{
		Employee emp("amini", 2134567890, "female", 675432, 2700000);
		emp.setBasesalary(3000000);
		cout << emp.salaryCal() << endl;
		cout << emp.taxCal() << endl;
		cout << emp.salaryPay() << endl;
	}
	if (type == "parttimeemployee")
	{
		ParttimeEmployee pte("davoodian", 5432167890, "male", 76543, 18);
		cout << pte.salaryCal() << endl;
		cout << pte.taxCal() << endl;
		cout << pte.salaryPay() << endl;
	}
	if (type == "workingstudent")
	{
		WorkingStudent vst("bahman", 9876543210,"male", 9232423, 8);
		cout << vst.salaryCal() << endl;
	}
	return 0;
}