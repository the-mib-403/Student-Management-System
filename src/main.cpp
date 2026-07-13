#include <iostream>
#include "../include/StudentManager.h"
#include "../include/Menu.h"
int main()
{
    StudentManager manager;

    Menu menu;
    int choice = 0;

    while (true)
    {
        menu.showMainMenu();

        std::string input;
        std::getline(std::cin, input);

        try
        {
            choice = std::stoi(input);
        }
        catch (...)
        {
            std::cout << "\nInvalid choice. Please enter a number between 1 and 6.\n";
            continue;
        }

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
        std::getline(std::cin, input);
    }


    return 0;
}