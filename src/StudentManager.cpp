#include "../include/StudentManager.h"
#include <iostream>
#include <algorithm>
#include <cctype>
#include <fstream>
#include <sstream>
StudentManager::StudentManager()
{
    loadFromFile();
}
void StudentManager::saveToFile() const
{
    std::ofstream file("database/students.txt");

    if (!file)
    {
        std::cout << "Error opening file.\n";
        return;
    }

    for (const Student &student : students)
    {
        file << student.getId() << ","
             << student.getName() << ","
             << student.getDepartment() << ","
             << student.getSemester() << ","
             << student.getCgpa() << ","
             << student.getEmail() << ","
             << student.getPhone() << '\n';
    }
}

void StudentManager::loadFromFile()
{
    std::ifstream file("database/students.txt");

    if (!file)
    {
        return;
    }

    std::string line;

    while (std::getline(file, line))
    {
        std::stringstream ss(line);

        std::string idString;
        std::string name;
        std::string department;
        std::string semesterString;
        std::string cgpaString;
        std::string email;
        std::string phone;

        std::getline(ss, idString, ',');
        std::getline(ss, name, ',');
        std::getline(ss, department, ',');
        std::getline(ss, semesterString, ',');
        std::getline(ss, cgpaString, ',');
        std::getline(ss, email, ',');
        std::getline(ss, phone, ',');

        int id = std::stoi(idString);
        int semester = std::stoi(semesterString);
        double cgpa = std::stod(cgpaString);
        Student student(
            id,
            name,
            department,
            semester,
            cgpa,
            email,
            phone);
        students.push_back(student);
    }
}

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
    saveToFile();
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

void StudentManager::updateStudent()
{
    int id;

    std::cout << "\nEnter Student ID: ";
    std::cin >> id;

    for (Student &student : students)
    {
        if (student.getId() == id)
        {
            std::cout << "\n========== Student Found ==========\n";

            std::cout << "\nWhat do you want to update?\n";
            std::cout << "1. Name\n";
            std::cout << "2. Department\n";
            std::cout << "3. Semester\n";
            std::cout << "4. CGPA\n";
            std::cout << "5. Email\n";
            std::cout << "6. Phone\n";
            std::cout << "7. Everything\n";
            std::cout << "8. Cancel\n";

            int choice;
            std::cout << "\nEnter your choice: ";
            std::cin >> choice;
            switch (choice)
            {
            case 1:
            {
                std::string newName;

                std::cin.ignore();

                std::cout << "\nEnter New Name: ";
                std::getline(std::cin, newName);

                student.setName(newName);
                saveToFile();
                std::cout << "\nStudent name updated successfully!\n";

                break;
            }

            case 2:
            {
                std::string newDepartment;

                std::cin.ignore();

                std::cout << "\nEnter New Department: ";
                std::getline(std::cin, newDepartment);

                student.setDepartment(newDepartment);
                saveToFile();
                std::cout << "\nDepartment updated successfully!\n";

                break;
            }

            case 3:
            {
                int newSemester;

                std::cout << "\nEnter New Semester: ";
                std::cin >> newSemester;

                student.setSemester(newSemester);
                saveToFile();
                std::cout << "\nSemester updated successfully!\n";

                break;
            }

            case 4:
            {
                double newcgpa;

                std::cout << "\nEnter New CGPA: ";
                std::cin >> newcgpa;
                student.setCgpa(newcgpa);
                saveToFile();
                std::cout << "\nCGPA updated successfully!\n";
                break;
            }
            case 5:
            {
                std::string newEmail;

                std::cin.ignore();

                std::cout << "\nEnter New Email: ";
                std::getline(std::cin, newEmail);

                student.setEmail(newEmail);
                saveToFile();
                std::cout << "\nEmail updated successfully!\n";

                break;
            }
            case 6:
            {
                std::string newPhone;
                std::cin.ignore();
                std::cout << "\nEnter New Phone: ";
                std::getline(std::cin, newPhone);
                student.setPhone(newPhone);
                saveToFile();
                std::cout << "\nPhone updated successfully!\n";
                break;
            }
            case 7:
            {
                std::string newName;
                std::string newDepartment;
                int newSemester;
                double newCgpa;
                std::string newEmail;
                std::string newPhone;

                std::cin.ignore();

                std::cout << "\nEnter New Name: ";
                std::getline(std::cin, newName);

                std::cout << "Enter New Department: ";
                std::getline(std::cin, newDepartment);

                std::cout << "Enter New Semester: ";
                std::cin >> newSemester;

                std::cout << "Enter New CGPA: ";
                std::cin >> newCgpa;

                std::cin.ignore();

                std::cout << "Enter New Email: ";
                std::getline(std::cin, newEmail);

                std::cout << "Enter New Phone: ";
                std::getline(std::cin, newPhone);

                student.setName(newName);
                student.setDepartment(newDepartment);
                student.setSemester(newSemester);
                student.setCgpa(newCgpa);
                student.setEmail(newEmail);
                student.setPhone(newPhone);
                saveToFile();
                std::cout << "\nStudent updated successfully!\n";

                break;
            }

            case 8:
            {
                std::cout << "\nUpdate cancelled.\n";
                break;
            }

            default:
            {
                std::cout << "\nThis update option is under development.\n";
            }
            }
            return;
        }
    }

    std::cout << "\nStudent not found.\n";
}

void StudentManager::deleteStudent()
{
    int id;

    std::cout << "\nEnter Student ID: ";
    std::cin >> id;

    for (auto it = students.begin(); it != students.end(); ++it)
    {
        if (it->getId() == id)
        {
            std::cout << "\n========== Student Found ==========\n\n";

            it->display();

            std::string choice;

            while (true)
            {
                std::cout << "\nAre you sure you want to delete this student? (YES/NO): ";
                std::cin >> choice;

                std::transform(choice.begin(), choice.end(), choice.begin(),
                               [](unsigned char c)
                               {
                                   return std::tolower(c);
                               });

                if (choice == "yes")
                {
                    students.erase(it);
                    saveToFile();
                    std::cout << "\nStudent deleted successfully!\n";
                    break;
                }

                else if (choice == "no")
                {
                    std::cout << "\nDeletion cancelled.\n";
                    break;
                }

                std::cout << "\nInvalid input. Please enter YES or NO.\n";
            }
            return;
        }
    }

    std::cout << "\nStudent not found.\n";
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