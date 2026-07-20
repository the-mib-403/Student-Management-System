#pragma once
#include <vector>
#include "Student.h"

class StudentManager
{
private:
    std::vector<Student> students;

    void loadFromFile();
    void saveToFile() const;
    bool isValidName(const std::string &name) const;
    bool isValidDepartment(const std::string &department) const;
    bool isValidEmail(const std::string &email) const;
    bool isValidPhone(const std::string &phone) const;

public:
    StudentManager();

    void addStudent(const Student &student);
    void addStudentInteractive();

    void searchStudentById() const;
    void searchStudentByName() const;
    void updateStudent();
    void deleteStudent();

    void displayStudents() const;
    void displayStudentsSortedByName() const;
    void displayStudentsSortedById() const;
    void displayStudentsSortedByDepartment() const;
    void displayStudentsSortedBySemester() const;
    void displayStudentsSortedByCgpa() const;

    bool isIdExists(int id) const;
    
};