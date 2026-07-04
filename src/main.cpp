#include<iostream>
#include "../include/StudentManager.h"
#include "../include/Menu.h"
int main()
{
    // Show Menu
    Menu menu;
    menu.showMainMenu();

    int choice;
    std::cin >> choice;

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

    if (choice == 2)
    {
        manager.displayStudents();
    }
    else if (choice == 4)
    {
        std::cout << "\nThank you for using Student Management System.\n";
    }
    else
    {
        std::cout << "\nThis feature is under development.\n";
    }
    
    return 0;
}