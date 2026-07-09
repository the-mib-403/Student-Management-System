#pragma once
#include <vector>
#include "Student.h"

class StudentManager
{
private:
    std::vector<Student> students;

    
    void loadFromFile();
    void saveToFile() const;

public:
    StudentManager();

    void addStudent(const Student &student);
    void addStudentInteractive();

    void displayStudents() const;
    void searchStudent() const;

    bool isIdExists(int id) const;

    void updateStudent();
    void deleteStudent();
};