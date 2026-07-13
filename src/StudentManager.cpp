#include "../include/StudentManager.h"
#include <iostream>
#include <algorithm>
#include <cctype>
#include <fstream>
#include <sstream>
#include <limits>
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
        if (line.empty())
        {
            continue;
        }

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

        try
        {
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
        catch (const std::exception &e)
        {
            std::cout << "Warning: Invalid record skipped.\n";
        }
    }
}

void StudentManager::addStudentInteractive()
{
    int id;
    int semester;
    double cgpa;
    std::string input;
    std::string name;
    std::string department;
    std::string email;
    std::string phone;

    while (true)
    {
        std::cout << "\nEnter Student ID: ";
        std::getline(std::cin, input);

        try
        {
            id = std::stoi(input);
        }
        catch (...)
        {
            std::cout << "\nInvalid input. Please enter a numeric Student ID.\n";
            continue;
        }

        if (id <= 0)
        {
            std::cout << "\nStudent ID must be greater than 0.\n";
            continue;
        }

        if (isIdExists(id))
        {
            std::cout << "\nStudent ID already exists. Please enter another ID.\n";
            continue;
        }

        break;
    }

    while (true)
    {
        std::cout << "Enter Student Name: ";
        std::getline(std::cin, name);

        bool isValid = true;

        for (char c : name)
        {
            if (!(std::isalpha(static_cast<unsigned char>(c)) ||
                  c == ' ' ||
                  c == '.' ||
                  c == '-' ||
                  c == '\''))
            {
                isValid = false;
                break;
            }
        }

        if (name.empty())
        {
            std::cout << "\nName cannot be empty.\n";
            continue;
        }

        if (!isValid)
        {
            std::cout << "\nName may contain only letters, spaces, periods (.), hyphens (-), and apostrophes (').\n";
            continue;
        }

        break;
    }

    while (true)
    {
        std::cout << "Enter Department: ";
        std::getline(std::cin, department);

        bool isValid = true;

        if (department.empty())
        {
            std::cout << "\nDepartment cannot be empty.\n";
            continue;
        }

        for (char c : department)
        {
            if (!(std::isalpha(static_cast<unsigned char>(c)) ||
                  c == ' ' ||
                  c == '&'))
            {
                isValid = false;
                break;
            }
        }

        if (!isValid)
        {
            std::cout << "\nDepartment may contain only letters, spaces, and ampersands (&).\n";
            continue;
        }

        break;
    }
    while (true)
    {
        std::cout << "Enter Semester: ";
        std::getline(std::cin, input);

        try
        {
            semester = std::stoi(input);
        }
        catch (...)
        {
            std::cout << "\nInvalid input. Please enter a numeric semester.\n";
            continue;
        }

        if (semester < 1 || semester > 12)
        {
            std::cout << "\nSemester must be between 1 and 12.\n";
            continue;
        }

        break;
    }

    while (true)
    {
        std::cout << "Enter CGPA: ";
        std::getline(std::cin, input);

        try
        {
            cgpa = std::stod(input);
        }
        catch (...)
        {
            std::cout << "\nInvalid input. Please enter a numeric CGPA.\n";
            continue;
        }

        if (cgpa < 0.0 || cgpa > 4.0)
        {
            std::cout << "\nCGPA must be between 0.00 and 4.00.\n";
            continue;
        }

        break;
    }

    while (true)
    {
        std::cout << "Enter Email: ";
        std::getline(std::cin, email);

        size_t atPos = email.find('@');
        size_t lastAtPos = email.rfind('@');
        size_t dotPos = email.find('.', atPos + 1);

        // Email cannot be empty
        if (email.empty())
        {
            std::cout << "\nEmail cannot be empty.\n";
            continue;
        }

        // Email cannot contain spaces
        if (email.find(' ') != std::string::npos)
        {
            std::cout << "\nEmail cannot contain spaces.\n";
            continue;
        }

        // Email must contain exactly one '@'
        if (atPos == std::string::npos)
        {
            std::cout << "\nEmail must contain exactly one at sign (@).\n";
            continue;
        }

        if (atPos != lastAtPos)
        {
            std::cout << "\nEmail must contain only one at sign (@).\n";
            continue;
        }

        // Username must exist before '@'
        if (atPos == 0)
        {
            std::cout << "\nEmail must contain a username before the at sign (@).\n";
            continue;
        }

        // Domain must exist after '@'
        if (atPos == email.length() - 1)
        {
            std::cout << "\nEmail must contain a domain after the at sign (@).\n";
            continue;
        }

        // Dot must exist after '@'
        if (dotPos == std::string::npos)
        {
            std::cout << "\nEmail must contain a valid domain extension.\n";
            continue;
        }

        // Domain name cannot be empty
        if (dotPos == atPos + 1)
        {
            std::cout << "\nEmail must contain a valid domain name.\n";
            continue;
        }

        // Extension cannot be empty
        if (dotPos == email.length() - 1)
        {
            std::cout << "\nEmail must contain a valid domain extension.\n";
            continue;
        }

        break;
    }

    while (true)
    {
        std::cout << "Enter Phone: ";
        std::getline(std::cin, phone);

        bool isValid = true;

        if (phone.length() != 11)
        {
            isValid = false;
        }

        for (char c : phone)
        {
            if (!std::isdigit(static_cast<unsigned char>(c)))
            {
                isValid = false;
                break;
            }
        }

        if (phone.substr(0, 2) != "01")
        {
            isValid = false;
        }

        if (!isValid)
        {
            std::cout << "\nPlease enter a valid Bangladeshi phone number.\n";
            continue;
        }

        break;
    }

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