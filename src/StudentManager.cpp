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
            size_t pos;
            id = std::stoi(input, &pos);

            if (pos != input.length())
            {
                std::cout << "\nInvalid input. Please enter a numeric Student ID.\n";
                continue;
            }
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

        if (!isValidName(name))
        {
            std::cout << "\nInvalid name. Name may contain only letters, spaces, periods (.), hyphens (-), and apostrophes (').\n";
            continue;
        }

        break;
    }

    while (true)
    {
        std::cout << "Enter Department: ";
        std::getline(std::cin, department);

        if (!isValidDepartment(department))
        {
            std::cout << "\nInvalid department. Department may contain only letters, spaces, and ampersands (&).\n";
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
            size_t pos;
            semester = std::stoi(input, &pos);

            if (pos != input.length())
            {
                std::cout << "\nInvalid input. Please enter a numeric semester.\n";
                continue;
            }
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
            size_t pos;
            cgpa = std::stod(input, &pos);

            if (pos != input.length())
            {
                std::cout << "\nInvalid input. Please enter a numeric CGPA.\n";
                continue;
            }
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

        if (!isValidEmail(email))
        {
            std::cout << "\nInvalid email. Please enter a valid email address.\n";
            continue;
        }

        break;
    }

    while (true)
    {
        std::cout << "Enter Phone: ";
        std::getline(std::cin, phone);

        if (!isValidPhone(phone))
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
    std::string input;

    while (true)
    {
        std::cout << "\nEnter Student ID: ";
        std::getline(std::cin, input);

        try
        {
            size_t pos;
            id = std::stoi(input, &pos);

            if (pos != input.length())
            {
                std::cout << "\nInvalid input. Please enter a numeric Student ID.\n";
                continue;
            }
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

        break;
    }

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

bool StudentManager::isValidName(const std::string &name) const
{
    if (name.empty())
    {
        return false;
    }

    for (char c : name)
    {
        if (!(std::isalpha(static_cast<unsigned char>(c)) ||
              c == ' ' ||
              c == '.' ||
              c == '-' ||
              c == '\''))
        {
            return false;
        }
    }

    return true;
}

bool StudentManager::isValidDepartment(const std::string &department) const
{
    if (department.empty())
    {
        return false;
    }

    for (char c : department)
    {
        if (!(std::isalpha(static_cast<unsigned char>(c)) ||
              c == ' ' ||
              c == '&'))
        {
            return false;
        }
    }

    return true;
}

bool StudentManager::isValidEmail(const std::string &email) const
{
    if (email.empty())
    {
        return false;
    }

    if (email.find(' ') != std::string::npos)
    {
        return false;
    }

    size_t atPos = email.find('@');
    size_t lastAtPos = email.rfind('@');

    if (atPos == std::string::npos || atPos != lastAtPos)
    {
        return false;
    }

    if (atPos == 0 || atPos == email.length() - 1)
    {
        return false;
    }

    size_t dotPos = email.find('.', atPos + 1);

    if (dotPos == std::string::npos)
    {
        return false;
    }

    if (dotPos == atPos + 1 || dotPos == email.length() - 1)
    {
        return false;
    }

    return true;
}

bool StudentManager::isValidPhone(const std::string &phone) const
{
    if (phone.length() != 11)
    {
        return false;
    }

    for (char c : phone)
    {
        if (!std::isdigit(static_cast<unsigned char>(c)))
        {
            return false;
        }
    }

    if (phone.substr(0, 2) != "01")
    {
        return false;
    }

    return true;
}

void StudentManager::updateStudent()
{
    int id;
    std::string input;

    while (true)
    {
        std::cout << "\nEnter Student ID: ";
        std::getline(std::cin, input);

        try
        {
            size_t pos;
            id = std::stoi(input, &pos);

            if (pos != input.length())
            {
                std::cout << "\nInvalid input. Please enter a numeric Student ID.\n";
                continue;
            }
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

        break;
    }

    for (Student &student : students)
    {
        if (student.getId() == id)
        {
            std::cout << "\n========== Student Found ==========\n";

            std::cout << "What do you want to update?\n";
            std::cout << "1. Name\n";
            std::cout << "2. Department\n";
            std::cout << "3. Semester\n";
            std::cout << "4. CGPA\n";
            std::cout << "5. Email\n";
            std::cout << "6. Phone\n";
            std::cout << "7. Everything\n";
            std::cout << "8. Cancel\n";

            int choice;

            while (true)
            {
                std::cout << "\nEnter your choice: ";
                std::getline(std::cin, input);

                try
                {
                    size_t pos;
                    choice = std::stoi(input, &pos);

                    if (pos != input.length())
                    {
                        std::cout << "\nInvalid input. Please enter a number between 1 and 8.\n";
                        continue;
                    }
                }
                catch (...)
                {
                    std::cout << "\nInvalid input. Please enter a number between 1 and 8.\n";
                    continue;
                }

                if (choice < 1 || choice > 8)
                {
                    std::cout << "\nChoice must be between 1 and 8.\n";
                    continue;
                }

                break;
            }
            switch (choice)
            {
            case 1:
            {
                std::string newName;

                while (true)
                {
                    std::cout << "Enter New Name: ";
                    std::getline(std::cin, newName);

                    if (!isValidName(newName))
                    {
                        std::cout << "\nInvalid name. Name may contain only letters, spaces, periods (.), hyphens (-), and apostrophes (').\n";
                        continue;
                    }

                    break;
                }

                student.setName(newName);
                saveToFile();

                std::cout << "\nStudent name updated successfully!\n";
                break;
            }

            case 2:
            {
                std::string newDepartment;

                while (true)
                {
                    std::cout << "Enter New Department: ";
                    std::getline(std::cin, newDepartment);

                    if (!isValidDepartment(newDepartment))
                    {
                        std::cout << "\nInvalid department. Department may contain only letters, spaces, and ampersands (&).\n";
                        continue;
                    }

                    break;
                }

                student.setDepartment(newDepartment);
                saveToFile();

                std::cout << "\nDepartment updated successfully!\n";
                break;
            }

            case 3:
            {
                int newSemester;
                std::string semesterInput;

                while (true)
                {
                    std::cout << "Enter New Semester: ";
                    std::getline(std::cin, semesterInput);

                    try
                    {
                        size_t pos;
                        newSemester = std::stoi(semesterInput, &pos);

                        if (pos != semesterInput.length())
                        {
                            std::cout << "\nInvalid input. Please enter a numeric semester.\n";
                            continue;
                        }
                    }
                    catch (...)
                    {
                        std::cout << "\nInvalid input. Please enter a numeric semester.\n";
                        continue;
                    }

                    if (newSemester < 1 || newSemester > 12)
                    {
                        std::cout << "\nSemester must be between 1 and 12.\n";
                        continue;
                    }

                    break;
                }

                student.setSemester(newSemester);
                saveToFile();

                std::cout << "\nSemester updated successfully!\n";
                break;
            }

            case 4:
            {
                double newCgpa;
                std::string cgpaInput;

                while (true)
                {
                    std::cout << "Enter New CGPA: ";
                    std::getline(std::cin, cgpaInput);

                    try
                    {
                        size_t pos;
                        newCgpa = std::stod(cgpaInput, &pos);

                        if (pos != cgpaInput.length())
                        {
                            std::cout << "\nInvalid input. Please enter a numeric CGPA.\n";
                            continue;
                        }
                    }
                    catch (...)
                    {
                        std::cout << "\nInvalid input. Please enter a numeric CGPA.\n";
                        continue;
                    }

                    if (newCgpa < 0.0 || newCgpa > 4.0)
                    {
                        std::cout << "\nCGPA must be between 0.00 and 4.00.\n";
                        continue;
                    }

                    break;
                }

                student.setCgpa(newCgpa);
                saveToFile();

                std::cout << "\nCGPA updated successfully!\n";
                break;
            }

            case 5:
            {
                std::string newEmail;

                while (true)
                {
                    std::cout << "Enter New Email: ";
                    std::getline(std::cin, newEmail);

                    if (!isValidEmail(newEmail))
                    {
                        std::cout << "\nInvalid email. Please enter a valid email address.\n";
                        continue;
                    }

                    break;
                }

                student.setEmail(newEmail);
                saveToFile();

                std::cout << "\nEmail updated successfully!\n";
                break;
            }

            case 6:
            {
                std::string newPhone;

                while (true)
                {
                    std::cout << "Enter New Phone: ";
                    std::getline(std::cin, newPhone);

                    if (!isValidPhone(newPhone))
                    {
                        std::cout << "\nPlease enter a valid Bangladeshi phone number.\n";
                        continue;
                    }

                    break;
                }

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

                // Name Validation
                while (true)
                {
                    std::cout << "Enter New Name: ";
                    std::getline(std::cin, newName);

                    if (!isValidName(newName))
                    {
                        std::cout << "\nInvalid name. Name may contain only letters, spaces, periods (.), hyphens (-), and apostrophes (').\n";
                        continue;
                    }

                    break;
                }

                // Department Validation
                while (true)
                {
                    std::cout << "Enter New Department: ";
                    std::getline(std::cin, newDepartment);

                    if (!isValidDepartment(newDepartment))
                    {
                        std::cout << "\nInvalid department. Department may contain only letters, spaces, and ampersands (&).\n";
                        continue;
                    }

                    break;
                }

                // Semester Validation
                while (true)
                {
                    std::cout << "Enter New Semester: ";
                    std::getline(std::cin, input);

                    try
                    {
                        size_t pos;
                        newSemester = std::stoi(input, &pos);

                        if (pos != input.length())
                        {
                            std::cout << "\nInvalid input. Please enter a numeric semester.\n";
                            continue;
                        }
                    }
                    catch (...)
                    {
                        std::cout << "\nInvalid input. Please enter a numeric semester.\n";
                        continue;
                    }

                    if (newSemester < 1 || newSemester > 12)
                    {
                        std::cout << "\nSemester must be between 1 and 12.\n";
                        continue;
                    }

                    break;
                }

                // CGPA Validation
                while (true)
                {
                    std::cout << "Enter New CGPA: ";
                    std::getline(std::cin, input);

                    try
                    {
                        size_t pos;
                        newCgpa = std::stod(input, &pos);

                        if (pos != input.length())
                        {
                            std::cout << "\nInvalid input. Please enter a numeric CGPA.\n";
                            continue;
                        }
                    }
                    catch (...)
                    {
                        std::cout << "\nInvalid input. Please enter a numeric CGPA.\n";
                        continue;
                    }

                    if (newCgpa < 0.0 || newCgpa > 4.0)
                    {
                        std::cout << "\nCGPA must be between 0.00 and 4.00.\n";
                        continue;
                    }

                    break;
                }

                // Email Validation
                while (true)
                {
                    std::cout << "Enter New Email: ";
                    std::getline(std::cin, newEmail);

                    if (!isValidEmail(newEmail))
                    {
                        std::cout << "\nInvalid email. Please enter a valid email address.\n";
                        continue;
                    }

                    break;
                }

                // Phone Validation
                while (true)
                {
                    std::cout << "Enter New Phone: ";
                    std::getline(std::cin, newPhone);

                    if (!isValidPhone(newPhone))
                    {
                        std::cout << "\nPlease enter a valid Bangladeshi phone number.\n";
                        continue;
                    }

                    break;
                }

                // Update all information
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
    std::string input;

    while (true)
    {
        std::cout << "\nEnter Student ID: ";
        std::getline(std::cin, input);

        try
        {
            size_t pos;
            id = std::stoi(input, &pos);

            if (pos != input.length())
            {
                std::cout << "\nInvalid input. Please enter a numeric Student ID.\n";
                continue;
            }
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

        break;
    }

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
                std::getline(std::cin, choice);

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