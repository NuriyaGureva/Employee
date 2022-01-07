// Employee.cpp : 
#include<string>
#include <iostream>
using namespace std;


class Employee
{
	std::string last_name;
	std::string first_name;
	double salary; 

public:
	const std::string& get_last_name()const
	{
		return last_name;
	}
	const std::string& get_first_name()const
	{
		return first_name;
	}

	double get_salary()const
	{
		return salary;
	}
	
	void set_last_name(const std::string& last_name)
	{
		this->last_name = last_name;
	}
	void set_first_name(const std::string& first_name)
	{
		this->first_name = first_name;
	}
	void set_salary_p_p(double salary)
	{
		this->salary = salary;	
	}

	Employee(const std::string& last_name, const std::string& first_name,		
		double salary)		
	{
			set_last_name(last_name);
			set_first_name(first_name);
			set_salary_p_p(salary);		
			cout << " Constructor:\t" << this << endl;
	}
	virtual~Employee()
	{
			cout << " Destructor:\t" << this << endl;

	}
	 virtual void print()const
	 {	
		 cout << last_name << " " << first_name << " "  << endl;	
	 }

	 virtual double calculate_salary()const
	 {
		 return salary;
	 }
};
	 class MonthEmployee:public Employee
	 {

	 public:
		 MonthEmployee(const std::string& last_name, const std::string& first_name,
			 double salary)
			 :Employee(last_name, first_name, salary)
		 {
			 cout << "MConstructor:\t" << this << endl;
		 }
		 ~MonthEmployee()
		 {
			 cout << "MDestructor:\t" << this << endl;
		 }
		
	 };

	 class HourEmployee :public Employee
	 {
		 unsigned int count_hours;

	 public:
		 int get_count_hours()const
		 {
			 return count_hours;
		 }

		 void set_count_hours(int count_hours)
		 {
			 this->count_hours = count_hours;
		 }

		 double calculate_salary()const
		 {
			 return get_salary() * count_hours;
		 }
		 HourEmployee(const std::string& last_name, const std::string& first_name, double salary,
			 unsigned int count_hours)
			 :Employee(last_name, first_name, salary)
		 {
			 set_count_hours(count_hours);

			 cout << "HConstructor:\t" << this << endl;
		 }
		 ~HourEmployee()
		 {
			 cout << "HDestructor" << this << endl;
		 }
	 };

int main()
{
	setlocale(LC_ALL, "");

	Employee* department[] =
	{
		new MonthEmployee("Ivanov", "Ivan", (double)15000),
		new MonthEmployee("Ivanov", "Ivan", (double)15500),
		new MonthEmployee("Ivanov", "Ivan", (double)10000),
		new HourEmployee("Sidorov", "Ivan", 500, 30),	
	};
	cout << sizeof(department) / sizeof(Employee*) << endl;
	double sum = 0;
	for (int i = 0; i < sizeof(department) / sizeof(Employee*); i++)
	{
		cout << typeid(*department[i]).name() << endl;
		department[i]->print();
		double salary = department[i]->calculate_salary();
		sum += salary;
		cout << "Зарплата за этот месяц: " << salary << endl;
		cout << "\n-----------------------------\n";
	}

	cout << "Зарплата отдела за этот месяц: " << sum << endl;

	for (int i = 0; i < sizeof(department) / sizeof(department[0]); i++)
	{
		delete department[i];
	}

	
}

