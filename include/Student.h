#pragma once
#include <string>

class Student
{
private:
    int id;
    std::string name;
    std::string department;
    int semester;
    double cgpa;
    std::string email;
    std::string phone;

public:
    // Constructors
    Student();
    Student(int id,
            std::string name,
            std::string department,
            int semester,
            double cgpa,
            std::string email,
            std::string phone);

    // Getters
    int getId() const;
    std::string getName() const;
    std::string getDepartment() const;
    int getSemester() const;
    double getCgpa() const;
    std::string getEmail() const;
    std::string getPhone() const;

    // Setters
    void setName(std::string name);
    void setDepartment(std::string department);
    void setSemester(int semester);
    void setCgpa(double cgpa);
    void setEmail(std::string email);
    void setPhone(std::string phone);

    // Display
    void display() const;
};