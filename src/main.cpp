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
            size_t pos;
            choice = std::stoi(input, &pos);

            if (pos != input.length())
            {
                std::cout << "\nInvalid choice. Please enter a number between 1 and 6.\n";
                continue;
            }
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
        {
            bool backToMain = false;
            while (true)
            {
                menu.showDisplayMenu();

                std::string displayInput;
                std::getline(std::cin, displayInput);

                int displayChoice;

                try
                {
                    size_t pos;
                    displayChoice = std::stoi(displayInput, &pos);

                    if (pos != displayInput.length())
                    {
                        std::cout << "\nInvalid input. Please enter a number between 1 and 7.\n";
                        continue;
                    }
                }
                catch (...)
                {
                    std::cout << "\nInvalid input. Please enter a number between 1 and 7.\n";
                    continue;
                }

                switch (displayChoice)
                {
                case 1:
                    manager.displayStudents();
                    break;

                case 2:
                    manager.displayStudentsSortedByName();
                    break;

                case 3:
                    manager.displayStudentsSortedById();
                    break;

                case 4:
                    manager.displayStudentsSortedByDepartment();
                    break;

                case 5:
                    manager.displayStudentsSortedBySemester();
                    break;

                case 6:
                    manager.displayStudentsSortedByCgpa();
                    break;

                case 7:
                    backToMain = true;
                    break;

                default:
                    std::cout << "\nInvalid choice. Please enter a number between 1 and 7.\n";
                    continue;
                }
                if (backToMain)
                {
                    break;
                }
            }

            break;
        }

        case 3:
        {
            bool backToMain = false;
            while (true)
            {
                menu.showSearchMenu();

                std::string searchInput;
                std::getline(std::cin, searchInput);

                int searchChoice;

                try
                {
                    size_t pos;
                    searchChoice = std::stoi(searchInput, &pos);

                    if (pos != searchInput.length())
                    {
                        std::cout << "\nInvalid input. Please enter a number between 1 and 4.\n";
                        continue;
                    }
                }
                catch (...)
                {
                    std::cout << "\nInvalid input. Please enter a number between 1 and 4.\n";
                    continue;
                }

                switch (searchChoice)
                {
                case 1:
                    manager.searchStudentById();
                    break;

                case 2:
                    manager.searchStudentByName();
                    break;

                case 3:
                    manager.searchStudentByDepartment();
                    break;

                case 4:
                    backToMain = true;
                    break;

                default:
                    std::cout << "\nInvalid choice. Please enter a number between 1 and 4.\n";
                    continue;
                }

                if (backToMain)
                {
                    break;
                }
            }

            break;
        }
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