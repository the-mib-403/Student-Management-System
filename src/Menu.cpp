#include "../include/Menu.h"
#include <iostream>

void Menu::showMainMenu() const
{
    std::cout << "\n";
    std::cout << "=========================================\n";
    std::cout << "       STUDENT MANAGEMENT SYSTEM\n";
    std::cout << "=========================================\n\n";

    std::cout << "1. Add Student\n";
    std::cout << "2. Display Students\n";
    std::cout << "3. Search Student\n";
    std::cout << "4. Update Student\n";
    std::cout << "5. Delete Student\n";
    std::cout << "6. Exit\n";
    std::cout << "Enter your choice: ";
}

void Menu::showDisplayMenu() const
{
    std::cout << "\n";
    std::cout << "=========================================\n";
    std::cout << "            DISPLAY STUDENTS\n";
    std::cout << "=========================================\n\n";

    std::cout << "1. Display All Students\n";
    std::cout << "2. Sort by Name\n";
    std::cout << "3. Sort by Student ID\n";
    std::cout << "4. Sort by Department\n";
    std::cout << "5. Sort by Semester\n";
    std::cout << "6. Sort by CGPA\n";
    std::cout << "7. Back to Main Menu\n";
    std::cout << "Enter your choice: ";
}

void Menu::showSearchMenu() const
{
    std::cout << "\n";
    std::cout << "=========================================\n";
    std::cout << "             SEARCH STUDENTS\n";
    std::cout << "=========================================\n\n";

    std::cout << "1. Search by Student ID\n";
    std::cout << "2. Search by Name\n";
    std::cout << "3. Search by Department\n";
    std::cout << "4. Back to Main Menu\n";
    std::cout << "Enter your choice: ";
}