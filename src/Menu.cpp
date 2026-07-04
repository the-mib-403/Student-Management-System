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
    std::cout << "4. Exit\n\n";

    std::cout << "Enter your choice : ";
}