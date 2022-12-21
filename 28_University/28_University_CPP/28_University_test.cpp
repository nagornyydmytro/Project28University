/* File 28_University_test.cpp
 * Realization of tests, input from the console and checking the operation 
 * of various methods of the main classes of the program
 *
 * The file contains some tests to illustrate 
 * the work of the university accounting system, 
 * individual methods of student classes, a grade book, etc.
 *
 * Made by Nagornyy Dmytro
 * Latest version date 20.12.2022
 *
 */

 /* Headers */

#define _CRT_SECURE_NO_WARNINGS

#include "28_University.h"

#include <windef.h>
#include <stdio.h>
#include <fcntl.h>
#include <windows.h>
#include <io.h>

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv) {
    int SubjectsCount = 0; //number of items in the register book
    int paymentValue = 2000;        // scholarship, grant amount (const)

    txt_green();  cout << "\nTest: Creating a student" << endl;       txt_white();
    Student s1("a",1,1,1);
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