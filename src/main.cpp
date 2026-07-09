#include <iostream>
#include "../include/StudentManager.h"
#include "../include/Menu.h"

int main()
{
    StudentManager manager;

    Menu menu;
    int choice;

    while (true)
    {
        menu.showMainMenu();

        std::cin >> choice;

        switch (choice)
        {
        case 1:
            manager.addStudentInteractive();
            break;

        case 2:
            manager.displayStudents();
            break;

        case 3:
            manager.searchStudent();
            break;

        case 4:
            manager.updateStudent();
            break;

        case 5:
        
            manager.deleteStudent();
            break;
        
        case 6:
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