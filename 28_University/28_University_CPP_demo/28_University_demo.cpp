/* File 28_University_demo.cpp
 * Realization of a university accounting program
 *
 * The file contains main classes (Person, Student, Employee, Teacher) and helper functions for accounting system.
 * Input / output methods to / from the console, file. 
 * Also, the student class has a grant calculation method (input parameters: gpa (average score, grade)), 
 * and the employee and teacher classes have salary calculation methods (input parameters: basic profession rate, length of service, grade)
 * This file contains the main methods for the program to work, 
 * input / output methods and calculation of the necessary data
 * 
 * The file contains some tests to illustrate
 * the work of the university accounting system,
 * individual methods of student classes, a grade book, etc.
 *
 * Made by Nagprnyy Dmytro
 * Latest version date 20.12.2022
 *
 */

/* Headers */

#include <iostream>  
#include <vector>
#include <string>
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

using namespace std;

/* Constants */

#define _CRT_SECURE_NO_WARNINGS
int SubjectsCount = 0; //number of items in the register book
int paymentValue = 2000;        // scholarship, grant amount (const)

/* Helper functions:
* change text in console from standard white to red, blue, green
*/

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

/*Base class of Person */
class Person {
private:
    /*void init(string name, size_t age) {
        if ((name == "") || (age <= 0)) {
            txt_red(); throw logic_error("Wrong input!");   txt_white();
        }
        else {
            this->m_Name = name; this->m_Age = age;
        }
    }*/
public:
    Person(const std::string& Name, size_t Age) :
        m_Name(Name), m_Age(Age) {}

    /* GetName function:
    * returns Person m_Name field value
    * result - const string with person's name
    */
    const std::string& GetName() const { return m_Name; }

    /* GetAge function:
    * returns Person m_Agw field value
    * result - int with person's age
    */
    size_t GetAge() const { return m_Age; }

    /* Input person data from console (name, age)*/
    int c_input() {
        cout << "\nInput lastname: ";
        cin >> this->m_Name;
        cout << "\nInput age: ";
        cin >> this->m_Age;
        return 0;
    }

    /* Output person data from console (name, age)*/
    void c_output() {
        cout << "\nName: " << m_Name << ", Age: " << m_Age << endl;
    }

protected:
    /* Fields */
    std::string m_Name;
    size_t      m_Age;
};

/*class of Student */
class Student : public Person {
private:
    /*void init(string name, size_t age, size_t gpa) {
        if ((name == "") || (age <= 0)) {
            txt_red(); throw logic_error("Wrong input!");   txt_white();
        }
        else {
            this->m_Name = name; this->m_Age = age; this->m_GPA = gpa;
        }
    }*/
public:
    Student(const std::string& Name, size_t Age, double GPA, double Grant) :        // GPA - average mark
        Person(Name, Age), m_GPA(GPA), m_Grant(Grant) {
    }

    /* Input student's data from console (name, age, gpa)*/
    int c_input() {
        cout << "\nInput lastname: ";
        cin >> this->m_Name;
        cout << "\nInput age: ";
        cin >> this->m_Age;
        cout << "\nInput student gpa: ";
        cin >> this->m_GPA;
        this->m_Grant = CalculateGrant(this->m_GPA);
        return 0;
    }

    /* Output student's data to console (name, age, gpa, grant)*/
    void c_output() {
        cout << "\nName: " << m_Name << ", Age: " << m_Age << ", GPA: " << m_GPA << ", Grant: " << m_Grant << endl;
    }

    /* GetGPA function:
    * returns Student m_GPA field value
    * result - int with student's gpa
    */
    double GetGPA() const { return m_GPA; }       // average mark

    /* GetGrant function:
    * returns Student m_Grant field value
    * result - double with student's grant
    */
    double GetGrant() { return CalculateGrant(m_GPA); }
private:
    /* CalculateGrant function:
    * calculates Student m_Grant field value
    * result - double with student's grant
    */
    double CalculateGrant(double gpa) { return (gpa * 200); }
private:
    /* Fields */
    double m_GPA;
    double m_Grant;
};

/*class of Employee */
class Employee : public Person {
private:
    /*void init(string name, size_t age, size_t pbr, size_t exp, size_t deg) {
        if ((name == "") || (age <= 0) || (pbr<=0) || (exp<=0) || (exp>10) || (deg<=0) || (deg>3)) {
            txt_red(); throw logic_error("Wrong input!");   txt_white();
        }
        else {
            this->m_Name = name; this->m_Age = age; this->m_ProfessionBaseRate = pbr;   this->m_Experience = exp;   this->m_Degree = deg;
        }
    }*/
public:
    Employee(const std::string& Name, size_t Age, double ProfessionBaseRate, size_t Experience, size_t Degree, double Salary) :
        Person(Name, Age), m_ProfessionBaseRate(ProfessionBaseRate), m_Experience(Experience), m_Degree(Degree), m_Salary(Salary) {}

    /* Input employee's data from console (name, age, pbr, exp, deg)*/
    int c_input() {
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

    /* Output employee's data from console (name, age, pbr, exp, deg)*/
    void c_output() {
        cout << "\nName: " << m_Name << ", Age: " << m_Age << ", Profession Base Rate: " << m_ProfessionBaseRate << ", Experience: " << m_Experience << ", Degree: " << m_Degree << ", Salary: " << m_Salary << endl;
    }

    /* GetProfessionBaseRate function:
    * returns Employee m_ProfessionBaseRate field value
    * result - double with profession base salary
    */
    double GetProfessionBaseRate() const { return m_ProfessionBaseRate; }       // base salary

    /* GetExperience function:
    * returns Employee m_Experience field value
    * result - int with emloyee's experience (0-10)
    */
    size_t GetExperience() const { return m_Experience; }         // 0 - 10 years

    /* GetDegree function:
    * returns Employee m_Degree field value
    * result - int with employee's degree (0-3)
    */
    size_t GetDegree() const { return m_Degree; }                 // 0 - 3 degree

    /* GetSalary function:
    * returns Employee m_Salary field value
    * result - double with employee's salary
    */
    double GetSalary(size_t premium = 0) { return CalculateSalary(m_ProfessionBaseRate, m_Experience, m_Degree); }
private:
    /* CalculateSalary function:
    * calculates Employee m_Salary field value
    * result - double with employee's salary
    */
    double CalculateSalary(double pbr, size_t exp, size_t deg) { return ((1 + (exp / 100) + (deg / 100) * pbr)); }
private:
    /* Fields */
    double m_ProfessionBaseRate;
    size_t m_Experience;
    size_t m_Degree;
    double m_Salary;
};

/*class of Teacher */
class Teacher : public Person {
private:
    /*void init(string name, size_t age, size_t pbr, size_t exp, size_t deg) {
        if ((name == "") || (age <= 0) || (pbr <= 0) || (exp <= 0) || (exp > 10) || (deg <= 0) || (deg > 3)) {
            txt_red(); throw logic_error("Wrong input!");   txt_white();
        }
        else {
            this->m_Name = name; this->m_Age = age; this->m_ProfessionBaseRate = pbr;   this->m_Experience = exp;   this->m_Degree = deg;
        }
    }*/
public:
    Teacher(const std::string& Name, size_t Age, double ProfessionBaseRate, size_t Experience, size_t Degree, double Salary) :
        Person(Name, Age), m_ProfessionBaseRate(ProfessionBaseRate), m_Experience(Experience), m_Degree(Degree), m_Salary(Salary) {}

    /* Input teacher's data from console (name, age, pbr, exp, deg)*/
    int c_input() {
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

    /* Output teacher's data from console (name, age, pbr, exp, deg)*/
    void c_output() {
        cout << "\nName: " << m_Name << ", Age: " << m_Age << ", Profession Base Rate: " << m_ProfessionBaseRate << ", Experience: " << m_Experience << ", Degree: " << m_Degree << ", Salary: " << m_Salary << endl;
    }

    /* GetProfessionBaseRate function:
    * returns Teacher m_ProfessionBaseRate field value
    * result - double with profession base salary
    */
    double GetProfessionBaseRate() const { return m_ProfessionBaseRate; }       // base salary

    /* GetExperience function:
    * returns Teacher m_Experience field value
    * result - int with teacher's experience (0-10)
    */
    size_t GetExperience() const { return m_Experience; }         // 0 - 10 years

    /* GetDegree function:
    * returns Teacher m_Degree field value
    * result - int with teacher's degree (0-3)
    */
    size_t GetDegree() const { return m_Degree; }                 // 0 - 3 degree

    /* GetSalary function:
    * returns Teacher m_Salary field value
    * result - double with teacher's salary
    */
    double GetSalary() { return CalculateSalary(m_ProfessionBaseRate, m_Experience, m_Degree); }
private:
    /* CalculateSalary function:
    * calculates Teacher m_Salary field value
    * result - double with teacher's salary
    */
    double CalculateSalary(double pbr, size_t exp, size_t deg) { return ((1 + (exp / 100) + (deg / 100) * pbr)); }
private:
    /* Fields */
    double m_ProfessionBaseRate;
    size_t m_Experience;
    size_t m_Degree;
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

int main(int argc, char** argv) {
    txt_green();  cout << "\nTest: Creating a person" << endl;        txt_white();
    Person p1("a", 1);
    p1.c_input();
    txt_blue();  p1.c_output(); txt_white();

    txt_green();  cout << "\nTest: Creating a student" << endl;       txt_white();
    Student s1("a", 1, 1, 1);
    s1.c_input();
    txt_blue();  s1.c_output();  txt_white();

    txt_green();  cout << "\nTest: Creating an employee" << endl;     txt_white();
    Employee e1("a", 1, 1, 1, 1, 1);
    e1.c_input();
    txt_blue();  e1.c_output();  txt_white();

    txt_green();  cout << "\nTest: Creating a teacher" << endl;       txt_white();
    Teacher t1("a", 1, 1, 1, 1, 1);
    t1.c_input();
    txt_blue();  t1.c_output();  txt_white();   
    cout << endl; 

    int StudentsCount;
    cout << "Input count of students: ";  
    cin >> StudentsCount;
    cout << "Input count of subject:"; 
    cin >> SubjectsCount;
    cout << endl; // Creation of blank gradebooks according to the number of students
    RecordBook* recordBooks = new RecordBook[StudentsCount]; // Memory allocation for items in the grade book
    for (int i = 0; i < StudentsCount; i++) {
        recordBooks[i].Subjects = new Subject[SubjectsCount];
    } // Filling information about items into a temporary container
    Subject* subjectsContainer = new Subject[SubjectsCount];
    for (int i = 0; i < SubjectsCount; i++) {
        cout << "Input #" << (i + 1) << " subject: ";
        cin >> subjectsContainer[i].SubjName;
        cout << "Input #" << (i + 1) << " teacher surname: ";
        cin >> subjectsContainer[i].SurnameTeacher;
    } // Filling in the record books of each student
    for (int i = 0; i < StudentsCount; i++) {
        cout << "\nInput #" << (i + 1) << " student's lastname: ";
        cin >> recordBooks[i].SurnameStudent;
        cout << "Input #" << (i + 1) << " record book id: ";
        cin >> recordBooks[i].Id; // The sum of grades for all subjects in the test
        int sumMark = 0; //C hecking whether this student will receive a grant
        bool needPayment = true; // Copying data from the container to the grade book and entering grades in subjects
        for (int j = 0; j < SubjectsCount; j++) {
            strcpy_s(recordBooks[i].Subjects[j].SubjName, subjectsContainer[j].SubjName);
            strcpy_s(recordBooks[i].Subjects[j].SurnameTeacher, subjectsContainer[j].SurnameTeacher);
            cout << "Input #" << (i + 1) << " student's mark of " << recordBooks[i].Subjects[j].SubjName << ": ";
            cin >> recordBooks[i].Subjects[j].Mark; // Setting grants for those who study at 4 and 5
            if (recordBooks[i].Subjects[j].Mark < 4) needPayment = false; // Ñalculation and filling in the average score in the grade book
            sumMark += recordBooks[i].Subjects[j].Mark;
            recordBooks[i].avgMark = (double)sumMark / (double)SubjectsCount;
        }
        if (needPayment == true) recordBooks[i].Payment = paymentValue;
        else recordBooks[i].Payment = 0;
    } // Sort type selection
    int sort_type;
    while (true) {

        cout << "Choose sort type (0 for ascending; 1 for descending): ";       // Sorting in ascending and descending order
        cin >> sort_type; cout << endl;
        if (sort_type != 0 && sort_type != 1) {
            cout << "Unknown sort type." << endl;
            continue;
        }
        break;
    } // Sorting
    for (int i = 0; i < StudentsCount - 1; i++) {
        for (int j = 0; j < StudentsCount - i - 1; j++) {
            RecordBook temp;
            if ((sort_type == 0 && recordBooks[j].avgMark > recordBooks[j + 1].avgMark) || (sort_type == 1 && recordBooks[j].avgMark < recordBooks[j + 1].avgMark)) {
                temp = recordBooks[j]; recordBooks[j] = recordBooks[j + 1]; recordBooks[j + 1] = temp;
            }
        }
    } // Output a sorted array of record books to console
    cout << "=========Sorted=record=books=============" << endl;
    for (int i = 0; i < StudentsCount; i++) {
        cout << "Student Surname: " << recordBooks[i].SurnameStudent << endl;
        cout << fixed; cout.precision(2);
        cout << "GPA: " << recordBooks[i].avgMark << endl;
        cout << "Record book Id: " << recordBooks[i].Id << endl;
        cout << "Payment: " << recordBooks[i].Payment << endl; // Subject information
        cout << "Subjects info:";
        cout << endl;
        for (int j = 0; j < SubjectsCount; j++) {
            cout << "\tSubject: " << recordBooks[i].Subjects[j].SubjName << ", Teacher: " << recordBooks[i].Subjects[j].SurnameTeacher << ", Mark: " << recordBooks[i].Subjects[j].Mark << endl;
        }
        cout << "==================" << endl;
    }

    txt_green();  cout << "\nTest: Group of students GPA" << endl;        txt_white();
    cout << "Input teacher's name: ";
    string teacher_name;
    cin >> teacher_name;

    double sum = 0;
    for (int i = 0; i < SubjectsCount; i++) {
        for (int j = 0; j < SubjectsCount; j++) {
            if (recordBooks[i].Subjects[j].SurnameTeacher == teacher_name) {
                sum += recordBooks[i].Subjects[j].Mark;
            }
        }
    }
    cout << "\nGPA in " << teacher_name << "'s group is: " << (sum / StudentsCount) << endl;

    for (int i = 0; i < StudentsCount; i++) {
        delete[] recordBooks[i].Subjects;
    }
    delete[] recordBooks;
    delete[] subjectsContainer;
    
    //getchar();
    return 0;
}
