#include "../include/StudentManager.h"
#include <iostream>
void StudentManager::addStudentInteractive()
{
    int id;
    int semester;
    double cgpa;
    std::string name;
    std::string department;
    std::string email;
    std::string phone;

    std::cout << "\nEnter Student ID: ";
    std::cin >> id;

    if (isIdExists(id))
    {
        std::cout << "\nStudent ID already exists!\n";
        return;
    }

    std::cin.ignore();

    std::cout << "Enter Student Name: ";
    std::getline(std::cin, name);

    std::cout << "Enter Department: ";
    std::getline(std::cin, department);

    std::cout << "Enter Semester: ";
    std::cin >> semester;

    std::cout << "Enter CGPA: ";
    std::cin >> cgpa;

    std::cin.ignore();

    std::cout << "Enter Email: ";
    std::getline(std::cin, email);

    std::cout << "Enter Phone: ";
    std::getline(std::cin, phone);

    Student student(
        id,
        name,
        department,
        semester,
        cgpa,
        email,
        phone);

    addStudent(student);

    std::cout << "\nStudent added successfully!\n";
}

void StudentManager::addStudent(const Student &student)
{
    students.push_back(student);
}

void StudentManager::searchStudent() const
{
    int id;

    std::cout << "\nEnter Student ID: ";
    std::cin >> id;

    bool found = false;

    for (const Student &student : students)
    {
        if (student.getId() == id)
        {
            std::cout << "\nStudent Found!\n\n";
            student.display();

            found = true;
            break;
        }
    }

    if (!found)
    {
        std::cout << "\nStudent not found.\n";
    }
}

bool StudentManager::isIdExists(int id) const
{
    for (const Student &student : students)
    {
        if (student.getId() == id)
        {
            return true;
        }
    }

    return false;
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