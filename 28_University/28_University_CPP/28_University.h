//#pragma once
/* File 28_University.h
 *
 * Realization of classes and structures needed for main program:
 *
 * The file contains an abstract class person (personality) (fields: name, age),
 * classes student, employee, teacher (inherited from the class person),
 * each of which contains input / output methods to / from the console, file.
 * Also, the student class has a grant calculation method (input parameters: gpa (average mark, grade)),
 * and the employee and teacher classes have salary calculation methods (input parameters: basic profession rate, experience, degree
 * This file contains classes and structures of for the program to work,
 * input / output methods and calculation of the necessary data
 *
 * Made by Nagornyy Dmytro
 * Latest version date 20.12.2022
 *
 */

 /* Constants */

#define _CRT_SECURE_NO_WARNINGS

/* Headers */

#include <iostream>  
#include <string>
#include <stdio.h>
#include <windows.h>
#include <fcntl.h>
#include <io.h>


/* Helpers:
* change text in console from standard white to red, blue, green
*/

void txt_red();
void txt_blue();
void txt_white();
void txt_green();


/*Abstract base class of Person */

class Person {
public:

    /* Declaration of input person data from console (name, age)*/
    virtual int c_input() = 0;

    /* Declaration of output person data from console (name, age)*/
    virtual void c_output() = 0;

    /* Declaration of GetName function:
    * returns Person m_Name field value
    * @result - const string with person's name
    */
    const std::string& GetName() const;

    /* Declaration of GetAge function:
    * returns Person m_Agw field value
    * @result - int with person's age
    */
    size_t GetAge() const;
};

class Student : public Person {
public:
    /* Declaration of Student class */
    Student(const std::string& Name, size_t Age, double GPA, double Grant);        // GPA - average mark

    /* Declaration of input student's data from console (name, age, gpa)*/
    int c_input();

    /* Declaration of output student's data from console (name, age, gpa, grant)*/
    void c_output();

    /* Declaration of GetGPA function:
    * returns Student m_GPA field value
    * @result - int with student's gpa
    */
    double GetGPA() const;       // average mark

    /* Declaration of GetGrant function:
    * returns Student m_Grant field value
    * @result - double with student's grant
    */
    double GetGrant(double premium = 0);

private:
    /* Declaration of CalculateGrant function:
    * calculates Student m_Grant field value
    * @param[gpa] - double (student gpa)
    * @result - double with student's grant
    */
    double CalculateGrant(double gpa);
private:
    /* Fields */
    std::string m_Name;
    size_t      m_Age;
    double m_GPA;
    double m_Grant;
};

class Employee : public Person {
public:
    /* Declaration of Employee class */
    Employee(const std::string& Name, size_t Age, double ProfessionBaseRate, double Experience, double Degree, double Salary);

    /* Declaration of input employee's data from console (name, age, pbr, exp, deg)*/
    int c_input();

    /* Declaration of output employee's data from console (name, age, pbr, exp, deg)*/
    void c_output();

    /* Declaration of GetProfessionBaseRate function:
    * returns Employee m_ProfessionBaseRate field value
    * @result - double with profession base salary
    */
    double GetProfessionBaseRate() const;       // base salary

    /* Declaration of GetExperience function:
    * returns Employee m_Experience field value
    * @result - int with emloyee's experience (0-10)
    */
    double GetExperience() const;        // 0 - 10 years

    /* Declaration of GetDegree function:
    * returns Employee m_Degree field value
    * @result - int with employee's degree (0-3)
    */
    double GetDegree() const;                 // 0 - 3 degree

    /* Declaration of GetSalary function:
    * returns Employee m_Salary field value
    * @result - double with employee's salary
    */
    double GetSalary(double premium = 0);

private:
    /* Declaration of CalculateSalary function:
    * calculates Employee m_Salary field value
    * @param[pbr] - double (Employee's Profession Base Rate)
    * @param[exp] - double (Employee's Experience)
    * @param[deg] - double (Employee's Degree)
    * @result - double with employee's salary
    */
    double CalculateSalary(double pbr, double exp, double deg);
private:
    /* Fields */
    std::string m_Name;
    size_t      m_Age;
    double m_ProfessionBaseRate;
    double m_Experience;
    double m_Degree;
    double m_Salary;
};

class Teacher : public Person {
public:
    /* Declaration of Teacher class */
    Teacher(const std::string& Name, size_t Age, double ProfessionBaseRate, double Experience, double Degree, double Salary);

    /* Declaration of input teacher's data from console (name, age, pbr, exp, deg)*/
    int c_input();

    /* Declaration of output teacher's data from console (name, age, pbr, exp, deg)*/
    void c_output();

    /* Declaration of GetProfessionBaseRate function:
    * returns Teacher m_ProfessionBaseRate field value
    * @result - double with profession base salary
    */
    double GetProfessionBaseRate() const;       // base salary

    /* Declaration of GetExperience function:
    * returns Teacher m_Experience field value
    * @result - int with teacher's experience (0-10)
    */
    double GetExperience() const;        // 0 - 10 years

    /* Declaration of GetDegree function:
    * returns Teacher m_Degree field value
    * @result - int with teacher's degree (0-3)
    */
    double GetDegree() const;                 // 0 - 3 degree

    /* Declaration of GetSalary function:
    * returns Teacher m_Salary field value
    * @result - double with teacher's salary
    */
    double GetSalary(double premium = 0);

private:
    /* Declaration of CalculateSalary function:
    * calculates Teacher m_Salary field value
    * @param[pbr] - double (Teacher's Profession Base Rate)
    * @param[exp] - double (Teacher's Experience)
    * @param[deg] - double (Teacher's Degree)
    * @result - double with teacher's salary
    */
    double CalculateSalary(double pbr, double exp, double deg);
private:
    /* Fields */
    std::string m_Name;
    size_t      m_Age;
    double m_ProfessionBaseRate;
    double m_Experience;
    double m_Degree;
    double m_Salary;
};


/* Structure of Subject studied by the student
   SubjName - the name of the subject being studied by the student
   SurnameTeacher - the name of the teacher who teaches this subject
   Mark - student grade for this discipline*/

struct Subject {
    char SubjName[30];
    char SurnameTeacher[20];
    int Mark;
};


/* Structure of Recordbook
   Id - record book number
   SurnameStudent - student's last name (30 ssymb)
   Subjects - subjects in which the student receives grades
   Payment - student payment
   avgMark - average student score in all subjects*/

struct RecordBook {
    int Id;
    char SurnameStudent[30];
    Subject* Subjects;
    double Payment;
    double avgMark;
};
