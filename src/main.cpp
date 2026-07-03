#include "../include/StudentManager.h"

int main()
{
    StudentManager manager;

    Student s1(
        101,
        "Rahim",
        "CSE",
        3,
        3.85,
        "rahim@gmail.com",
        "01711111111"
    );

    Student s2(
        102,
        "Karim",
        "EEE",
        2,
        3.60,
        "karim@gmail.com",
        "01822222222"
    );

    manager.addStudent(s1);
    manager.addStudent(s2);

    manager.displayStudents();

    return 0;
}






// g++ src\main.cpp src\Student.cpp src\StudentManager.cpp -Iinclude -o StudentManagementSystem.exe
// .\StudentManagementSystem.exe (Powershell a program rum err command)