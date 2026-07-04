#include <iostream>
#include "../include/StudentManager.h"
#include "../include/Menu.h"

int main()
{
    StudentManager manager;

    // Demo Students
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

    Menu menu;
    int choice;

    while (true)
    {
        menu.showMainMenu();

        std::cin >> choice;

        switch (choice)
        {
        case 1:
            std::cout << "\nAdd Student feature is under development.\n";
            break;

        case 2:
            manager.displayStudents();
            break;

        case 3:
            std::cout << "\nSearch Student feature is under development.\n";
            break;

        case 4:
            std::cout << "\nThank you for using Student Management System.\n";
            return 0;

        default:
            std::cout << "\nInvalid Choice!\n";
        }

        std::cout << "\nPress Enter to continue...";
        std::cin.ignore();
        std::cin.get();
    }

    return 0;
}