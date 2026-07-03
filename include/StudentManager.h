#pragma once
#include <vector>
#include "Student.h"
class StudentManager
{
private:
    std::vector<Student> students;

public:
    void addStudent(const Student &student);
    void displayStudents() const;
};