#include <iostream>
#include <string>

using namespace std;

//employee structure with name, hours worked (5 values), $/hour, and total pay
struct Employee
{
  string name;
  double hours[5];
  double rate;
  double pay;
};

//function to initialize the array with user inputed values
void initialize(Employee e[])
{
  for (int i = 0; i < 4; i++)
  {
    cout << "Last name of employee #" << i + 1 << ": ";
    cin >> e[i].name;
    cout << "Hours worked on Monday: ";
    cin >> e[i].hours[0];
    cout << "Hours worked on Tuesday: ";
    cin >> e[i].hours[1];
    cout << "Hours worked on Wednesday: ";
    cin >> e[i].hours[2];
    cout << "Hours worked on Thursday: ";
    cin >> e[i].hours[3];
    cout << "Hours worked on Friday: ";
    cin >> e[i].hours[4];
    cout << "Hourly rate of employee #" << i + 1 << ": ";
    cin >> e[i].rate;
    cout << endl;
  }
}

//compute total pay for employee
void compute(Employee &e)
{
  int baseHours = 0, overHours = 0;
  for (int h = 0; h < 5; h++)
  {
    baseHours += e.hours[h];
  }
  if (baseHours > 40)
  {
    overHours = baseHours - 40;
    baseHours = 40;
  }
  e.pay = (baseHours * e.rate) + (overHours * (e.rate * 1.5));
}

//output the pay of the employee
void result(Employee e)
{
  cout << e.name << " payroll check ammount: $" << e.pay << endl;
}

int main()
{
  Employee employees[4];
  initialize(employees);
  for (int i = 0; i < 4; i++)
  {
    compute(employees[i]);
  }
  cout << endl;
  for (int i = 0; i < 4; i++)
  {
    result(employees[i]);
  }
}
