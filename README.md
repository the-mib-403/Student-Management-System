# 🎓 Student Management System

A terminal-based **Student Management System** developed in **C++** as a **Data Structure Lab Project**. The system demonstrates practical implementation of Object-Oriented Programming (OOP), file handling, and fundamental data structures including **Vector, Stack, and Queue**.

All student records are stored permanently using text files, allowing data to persist even after the program is closed.

---

# 📌 Features

### Student Management
- Add Student
- Update Student Information
- Delete Student
- Display All Students

### Search
- Search by Student ID
- Search by Name
- Search by Department

### Sorting
- Sort by ID
- Sort by Name
- Sort by Department
- Sort by Semester
- Sort by CGPA

### Request Management
- Add Student Request
- View Pending Requests
- Process Student Requests (Queue)

### Undo System
- Undo Last Add
- Undo Last Delete
- Undo Last Update

### Data Persistence
- Save student records to file
- Load records automatically on startup
- Save request queue
- Load request queue automatically

### Validation
- Student ID validation
- Name validation
- Department validation
- Semester validation
- CGPA validation
- Email validation
- Bangladeshi Phone Number validation

---

# 🧩 Data Structures Used

| Data Structure | Purpose |
|----------------|---------|
| **Vector** | Stores all student records |
| **Stack** | Undo last operation (Add, Delete, Update) |
| **Queue** | Handles pending student requests |

---

# 💻 Technologies Used

- C++
- Object-Oriented Programming (OOP)
- STL (Vector, Stack, Queue)
- File Handling
- Multi-file Project Structure
- CodeBlocks / GCC Compiler

---

# 📁 Project Structure

```
Student-Management-System
│
├── database
│   ├── students.txt
│   └── requests.txt
│
├── include
│   ├── Student.h
│   ├── StudentManager.h
│   └── Menu.h
│
├── src
│   ├── Student.cpp
│   ├── StudentManager.cpp
│   └── Menu.cpp
│
├── screenshots
│
├── main.cpp
├── README.md
├── LICENSE
└── .gitignore
```

---

# ▶️ How to Compile

Using **g++**

```bash
g++ main.cpp src/*.cpp -Iinclude -o StudentManagementSystem
```

Run:

```bash
./StudentManagementSystem
```

Or simply open the project in **CodeBlocks** and press **Build & Run**.

---

# 📋 Sample Main Menu

```
========== Student Management System ==========

1. Add Student
2. Search Student
3. Update Student
4. Delete Student
5. Display Students
6. Student Requests
7. Undo Last Action
8. Exit
```

---

# 📂 File Storage

The project stores data using text files.

**students.txt**

Stores:

- Student ID
- Name
- Department
- Semester
- CGPA
- Email
- Phone Number

**requests.txt**

Stores:

- Student ID
- Request Type

Both files are loaded automatically when the application starts.

---

# ✅ Input Validation

The system validates every important input.

- Student ID must be numeric and unique.
- Semester must be between **1–12**.
- CGPA must be between **0.00–4.00**.
- Email must follow a valid format.
- Phone number must be a valid **11-digit Bangladeshi mobile number**.
- Names and departments accept only valid characters.

---

# 📚 Concepts Demonstrated

- Object-Oriented Programming
- Encapsulation
- Modular Programming
- File Handling
- Exception Handling
- STL Containers
- Searching
- Sorting
- Input Validation
- Persistent Storage

---

# 🚀 Future Improvements

- Login System
- Admin Authentication
- GUI Version
- Database Integration (MySQL)
- Export Student List as PDF
- Advanced Search Filters

---

# 👨‍💻 Author

**Biplob**

Department of Computer Science & Engineering

Bangladesh University of Business & Technology (BUBT)

---

# 📄 License

This project is developed for educational purposes as part of a Data Structure Lab course.