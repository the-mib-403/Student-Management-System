#include "../include/Student.h"
#include <iostream>

Student::Student()
{
    id = 0;
    name = "";
    department = "";
    semester = 0;
    cgpa = 0.0;
    email = "";
    phone = "";
}

Student::Student(int id,
                 std::string name,
                 std::string department,
                 int semester,
                 double cgpa,
                 std::string email,
                 std::string phone)
{
    this->id = id;
    this->name = name;
    this->department = department;
    this->semester = semester;
    this->cgpa = cgpa;
    this->email = email;
    this->phone = phone;
}

int Student::getId() const
{
    return id;
}

std::string Student::getName() const
{
    return name;
}

std::string Student::getDepartment() const
{
    return department;
}

int Student::getSemester() const
{
    return semester;
}

double Student::getCgpa() const
{
    return cgpa;
}

std::string Student::getEmail() const
{
    return email;
}

std::string Student::getPhone() const
{
    return phone;
}

void Student::setName(std::string name)
{
    this->name = name;
}

void Student::setDepartment(std::string department)
{
    this->department = department;
}

void Student::setSemester(int semester)
{
    this->semester = semester;
}

void Student::setCgpa(double cgpa)
{
    this->cgpa = cgpa;
}

void Student::setEmail(std::string email)
{
    this->email = email;
}

void Student::setPhone(std::string phone)
{
    this->phone = phone;
}

void Student::display() const
{
    std::cout << "ID         : " << id << '\n';
    std::cout << "Name       : " << name << '\n';
    std::cout << "Department : " << department << '\n';
    std::cout << "Semester   : " << semester << '\n';
    std::cout << "CGPA       : " << cgpa << '\n';
    std::cout << "Email      : " << email << '\n';
    std::cout << "Phone      : " << phone << '\n';
}