/* File 28_University.cpp 
 * 
 * Realization of a university accounting program
 * 
 * The file contains main methods and helper functions for accounting system.
 * Input / output methods to / from the console, file. 
 * Also, the student class has a scholarship calculation method (input parameters: gpa (average score, grade)), 
 * and the employee and teacher classes have salary calculation methods (input parameters: basic profession rate, length of service, grade)
 * This file contains the main methods for the program to work, 
 * input / output methods and calculation of the necessary data
 *
 * Made by Nagornyy Dmytro
 * Latest version date 20.12.2022
 *
 */

 /* Headers */

#define _CRT_SECURE_NO_WARNINGS

#include "28_University.h"

#include <fstream> 
#include <compare>
#include <windows.h>
#include <istream>
#include <map>
#include <ostream>
#include <cstdlib>
#include <limits>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <list>
#include <fcntl.h>
#include <io.h>

using namespace std;


/* Helper functions*/

void txt_red() {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
}
void txt_blue() {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);
}
void txt_white() {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
}
void txt_green() {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
}

/* Functions for Student class */

/* Constructor for Student class */
Student::Student(const std::string& Name, size_t Age, double GPA, double Grant) :        // GPA - average mark
    m_Name(Name), m_Age(Age), m_GPA(GPA), m_Grant(Grant) {}
/* Student c_input */
int Student::c_input() {
    cout << "\nInput lastname: ";
    cin >> this->m_Name;
    cout << "\nInput age: ";
    cin >> this->m_Age;
    cout << "\nInput student gpa: ";
    cin >> this->m_GPA;
    this->m_Grant = CalculateGrant(this->m_GPA);
    return 0;
}
/* Student c_output */
void Student::c_output() {
    cout << "\nName: " << m_Name << ", Age: " << m_Age << ", GPA: " << m_GPA << ", Grant: " << m_Grant << endl;
}
/* Student GetGPA */
double Student::GetGPA() const { return m_GPA; }       // average mark
/* Student GetGrant */
double Student::GetGrant(double premium) { return CalculateGrant(m_GPA); }
/* Student CalculateGrant */
double Student::CalculateGrant(double premium) { return (premium * 200); }


/* Functions for Employee class */

/* Constructor for Employee class */
Employee::Employee(const std::string& Name, size_t Age, double ProfessionBaseRate, double Experience, double Degree, double Salary) :
    m_Name(Name), m_Age(Age), m_ProfessionBaseRate(ProfessionBaseRate), m_Experience(Experience), m_Degree(Degree), m_Salary(Salary) {}
/* Employee c_input */
int Employee::c_input() {
    cout << "\nInput lastname: ";
    cin >> this->m_Name;
    cout << "\nInput age: ";
    cin >> this->m_Age;
    cout << "\nInput employee profession base rate: ";
    cin >> this->m_ProfessionBaseRate;
    cout << "\nInput employee experience (0-10): ";
    cin >> this->m_Experience;
    cout << "\nInput employee degree (0-3): ";
    cin >> this->m_Degree;
    this->m_Salary = CalculateSalary(m_ProfessionBaseRate, m_Experience, m_Degree);
    return 0;
}
/* Employee c_output */
void Employee::c_output() {
    cout << "\nName: " << m_Name << ", Age: " << m_Age << ", Profession Base Rate: " << m_ProfessionBaseRate << ", Experience: " << m_Experience << ", Degree: " << m_Degree << ", Salary: " << m_Salary << endl;
}
/* Employee GetProfessionBaseRate */
double Employee::GetProfessionBaseRate() const { return m_ProfessionBaseRate; }       // base salary
/* Employee GetExperience */
double Employee::GetExperience() const { return m_Experience; }         // 0 - 10 years
/* Employee GetDegree */
double Employee::GetDegree() const { return m_Degree; }                 // 0 - 3 degree
/* Employee GetSalary */
double Employee::GetSalary(double premium) { return CalculateSalary(m_ProfessionBaseRate, m_Experience, m_Degree); }
/* Employee CalculateSalary */
double Employee::CalculateSalary(double pbr, double exp, double deg) { return ((1 + (exp / 100) + (deg / 100))*pbr); }



/* Functions for Teacher class */

/* constructor for Teacher class */
Teacher::Teacher(const std::string& Name, size_t Age, double ProfessionBaseRate, double Experience, double Degree, double Salary) :
    m_Name(Name), m_Age(Age), m_ProfessionBaseRate(ProfessionBaseRate), m_Experience(Experience), m_Degree(Degree), m_Salary(Salary) {}
/* Teacher c_input */
int Teacher::c_input() {
    cout << "\nInput lastname: ";
    cin >> this->m_Name;
    cout << "\nInput age: ";
    cin >> this->m_Age;
    cout << "\nInput employee profession base rate: ";
    cin >> this->m_ProfessionBaseRate;
    cout << "\nInput employee experience (0-10): ";
    cin >> this->m_Experience;
    cout << "\nInput employee degree (0-3): ";
    cin >> this->m_Degree;
    this->m_Salary = CalculateSalary(m_ProfessionBaseRate, m_Experience, m_Degree);
    return 0;
}
/* Teacher c_output */
void Teacher::c_output() {
    cout << "\nName: " << m_Name << ", Age: " << m_Age << ", Profession Base Rate: " << m_ProfessionBaseRate << ", Experience: " << m_Experience << ", Degree: " << m_Degree << ", Salary: " << m_Salary << endl;
}
/* Teacher GetProfessionBaseRate */
double Teacher::GetProfessionBaseRate() const { return m_ProfessionBaseRate; }       // base salary
/* Teacher GetExperience */
double Teacher::GetExperience() const { return m_Experience; }         // 0 - 10 years
/* Teacher GetDegree */
double Teacher::GetDegree() const { return m_Degree; }                 // 0 - 3 degree
/* Teacher GetSalary */
double Teacher::GetSalary(double premium) { return CalculateSalary(m_ProfessionBaseRate, m_Experience, m_Degree); }
/* Teacher CalculateSalary */
double Teacher::CalculateSalary(double pbr, double exp, double deg) { return ((1 + (exp / 100) + (deg / 100)) * pbr); }
