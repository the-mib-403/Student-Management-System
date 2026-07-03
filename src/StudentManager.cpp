#include "../include/StudentManager.h"
#include <iostream>

void StudentManager::addStudent(const Student &student)
{
    students.push_back(student);
}

void StudentManager::displayStudents() const
{
    if (students.empty())
    {
        std::cout << "No students found.\n";
        return;
    }

    for (const Student &student : students)
    {
        std::cout << "----------------------------\n";
        student.display();
    }
}