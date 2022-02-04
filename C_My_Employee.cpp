// Sophia Godfrey
// Project 3: Employee Database

#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <iomanip>

using namespace std;

class Employee {
    public:  
    Employee(string name, string title);
    void SetEmployeeName(string name);	// Mutators
    void SetJobTitle(string title);	
    void SetHourlyRate(double wage);	
    void SetHoursWorked(double hours);	
    double GetHourlyRate();
    double GetHoursWorked();
    string GetJobTitle();
    string GetEmployeeName();

    private:
    string employeeName;
    string jobTitle;
    double hourlyRate;
    double hoursWorked;
};

Employee::Employee(string name = "Choose_Name", string title = "Choose_Title") {		// Default constructor
    employeeName = name;	// Default name: Choose_Name (indicating the name was not set)
    jobTitle = title;		// Default title: Choose_Title
    hourlyRate = 00.00;     // Default rate and hours are zeroed out
    hoursWorked = 00.00;
}

void Employee::SetEmployeeName(string name) {
    employeeName = name;
}

string Employee::GetEmployeeName() {
    return employeeName;
}

void Employee::SetJobTitle(string title) {
    jobTitle = title;
}

string Employee::GetJobTitle() {
    return jobTitle;
}

void Employee::SetHourlyRate(double wage) {
    if(wage > 0) {
        hourlyRate = wage;
    }
    else {
        cout << "Cannot set the wage to zero or below." << endl;
    }
}	

double Employee::GetHourlyRate() {
    return hourlyRate;
}

void Employee::SetHoursWorked(double hours) {
    if(hours >= 0 && hours <=168)  {
        hoursWorked = hours;
    } 
    else {
        cout << "Cannot work negative hours in a week." << endl;
    }
    hoursWorked = hours;
}	

double Employee::GetHoursWorked() {
    return hoursWorked;
}

// This function is used to create the vector of Employee objects (I just put in some names so the output would look nice)
void assign(vector<Employee> &employees) {	// "&" call by reference
    
    Employee e1("Neveah Knight", "Manager");
    e1.SetHourlyRate(32.05);  
   
    Employee e2("Nathalie Shannon", "Lawyer");
    e2.SetHourlyRate(48.00);
    
    Employee e3("Rachael Foster", "PR");
    e3.SetHourlyRate(29.50);
    
    Employee e4("Adam Brooks", "Marketing");
    e4.SetHourlyRate(30.00);
    
    Employee e5("Elena Galvan", "Custodian");
    e5.SetHourlyRate(12.90);
    
    Employee e6("Kymani Hatfield", "Groundskeeper");
    e6.SetHourlyRate(13.40);
    
    // Here the vector has all the objects pushed into it
    employees.push_back(e1);
    employees.push_back(e2);
    employees.push_back(e3);
    employees.push_back(e4);
    employees.push_back(e5);
    employees.push_back(e6);

}

// The "Print list of employees" should print each employee name, job title, and associated hourly wages. 
void PrintEmployeeList(vector<Employee> employees) {
    cout << "   -Employee Name-  -Job Title- -Hourly Wage-" << endl;
    for(int i=0; i < employees.size(); i++) { // this loop goes through the values and outputs them
        cout << right << setw(2) << i+1 << ". ";
        cout << setw(18) << left << employees.at(i).GetEmployeeName();
        cout << setw(14) << left << employees.at(i).GetJobTitle();
        cout << setw(13) << left << employees.at(i).GetHourlyRate() << endl;
    }
    cout << endl;
}

// The "Calculate total wages" option will iterate through each employee
// and ask the user to input the total number of hours worked for the that employee,
// multiplying that by the employee's hourly wages, and adding that to the total.
// After iterating through all employees, the total wages for that week should be displayed.
void CalculateTotalWages(vector<Employee> employees) {
    string hoursWorked;
    double hoursDouble;
    bool valid;
    cout << "Input the hours worked this week for each employee:" << endl;
    cout << "   -Employee Name-  -Job Title- -Hourly Wage- -Hours-" << endl;
    for(int i=0; i < employees.size(); i++) {
        valid = false;
        cout << right << setw(2) << i+1 << ". ";
        cout << setw(18) << left << employees.at(i).GetEmployeeName();
        cout << setw(14) << left << employees.at(i).GetJobTitle();
        cout << setw(13) << left << employees.at(i).GetHourlyRate();
        while(valid == false) {
            cin >> hoursWorked;
            hoursDouble = atof(hoursWorked.c_str());
            if(hoursDouble > 0 || hoursWorked.find("0") < hoursWorked.length()) {
                valid = true;
            }
            else {
                cout << "Please enter a valid hours worked: ";
            };
        }
        employees.at(i).SetHoursWorked(hoursDouble);
    }
    cout << endl;
    cout << "   -Employee Name-  -Job Title- -Hourly Wage- -Hours- -Pay Due-" << endl;
    for(int j=0; j < employees.size(); j++) {
        cout << right << setw(2) << j+1 << ". ";
        cout << setw(18) << left << employees.at(j).GetEmployeeName();
        cout << setw(14) << left << employees.at(j).GetJobTitle();
        cout << setw(13) << left << employees.at(j).GetHourlyRate();
        cout << setw(7) << left << employees.at(j).GetHoursWorked();
        cout << setw(5) << left << employees.at(j).GetHoursWorked()*employees.at(j).GetHourlyRate();;
        cout << endl;
    }
    cout << endl;
}

void AddEmployee(vector<Employee> &employees) {
    string name, title, rate;
    double rateDouble;
    bool valid = false;
    cout << "Input employee name: ";
    cin >> name;
    cout << "Input employee title: ";
    cin >> title;
    cout << "Input employee's hourly wage: ";
    while(valid == false) {
        cin >> rate;
        rateDouble = atof(rate.c_str());
        if(rateDouble > 0) {
            valid = true;
        }
        else {
            cout << "Please enter a valid wage: ";
        };
    }
    Employee newEmployee(name, title);
    newEmployee.SetHourlyRate(rateDouble);
    employees.push_back(newEmployee);
}

// Greet the user with a program description
void ApplicationDescription() {
    cout << "Hello! This is an application called -C MY EMPLOYEE-" << endl;    // haha pun :P
    cout << "This program allows you to easily keep track of your employees ";
    cout << "by allowing you to track employee's names, job titles, and wages. ";
    cout << "You can even determine weekly salary for each of your employees by inputting their hours! " << endl;
    cout << "Let's get started!" << endl << endl;
}

// Present the user with a numbered list of options
void OptionsList() {
    cout << "1. Print list of employees" << endl;
    cout << "2. Calculate total wages" << endl;
    cout << "3. Add new employee" << endl;
    cout << "4. Exit application" << endl << endl;
}

// User selects option by entering number value
int InputNumber() {
    int intInput;
    string listNumberStr;
    bool valid = false;
    while(valid == false) {
    cin >> listNumberStr;      // user inputs number
    cout << endl;
    intInput = atoi(listNumberStr.c_str());
    if(intInput <= 4 && intInput > 0){
        valid = true;
    }
	else {
        cout << "Please enter a valid option from the list: " << endl;
	}
    }
    return intInput;
}

int main() {
    
    bool exitApp = false;    // when the user presses "4" for their option, the bool is set to true and the loop exits
    int listNumberInt;      // the user chosen list number as a number
    vector<Employee> employees;   // create the list of employees

    ApplicationDescription();   // output program synopsis

    assign(employees);
    while(exitApp == false) {       // while loop to ensure that the program will continue until stopped 
    cout << "Choose an option from the list below:" << endl;
    OptionsList();  // outputs list of options
    listNumberInt = InputNumber();
    if(listNumberInt == 1) {		// 1. Print list of employees
        PrintEmployeeList(employees);
    }
    else if(listNumberInt == 2) {		// 2. Calculate total wages
        CalculateTotalWages(employees);
    }
    else if(listNumberInt == 3) {		// 3. Add new employee
        AddEmployee(employees);
    }
    else if(listNumberInt == 4) {		// 4. Exit application
        exitApp = true;
    }

    }
    
    return 0;
}

