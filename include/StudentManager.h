#pragma once
#include <vector>
#include <stack>
#include <queue>
#include "Student.h"

class StudentManager
{
private:
    std::vector<Student> students;
    struct UndoAction
    {
        std::string actionType;
        Student student;
    };

    struct StudentRequest
    {
        int studentId;
        std::string requestType;
    };

    std::stack<UndoAction> undoStack;
    std::queue<StudentRequest> requestQueue;
    void loadFromFile();
    void saveToFile() const;

    void loadRequestsFromFile();
    void saveRequestsToFile() const;

    // Validation Helpers
    bool isValidName(const std::string &name) const;
    bool isValidDepartment(const std::string &department) const;
    bool isValidEmail(const std::string &email) const;
    bool isValidPhone(const std::string &phone) const;

    // Update Helpers
    void updateName(Student &student);
    void updateDepartment(Student &student);
    void updateSemester(Student &student);
    void updateCgpa(Student &student);
    void updateEmail(Student &student);
    void updatePhone(Student &student);
    void updateAll(Student &student);

public:
    StudentManager();

    void addStudent(const Student &student);
    void addStudentInteractive();

    void searchStudentById() const;
    void searchStudentByName() const;
    void searchStudentByDepartment() const;
    void updateStudent();
    void deleteStudent();
    void undoLastAction();

    void addRequest();
    void processRequest();
    void displayRequests() const;

    void displayStudents() const;
    void displayStudentsSortedByName() const;
    void displayStudentsSortedById() const;
    void displayStudentsSortedByDepartment() const;
    void displayStudentsSortedBySemester() const;
    void displayStudentsSortedByCgpa() const;

    bool isIdExists(int id) const;
};