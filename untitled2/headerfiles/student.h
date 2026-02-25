#ifndef STUDENT_H
#define STUDENT_H
#include <bits\stdc++.h>
#include "course.h"
using namespace std;

struct Student {
    std::string id; // Unique national ID
    std::string name; // Full name
    int year; // Academic year
    int numcourses;
    std::vector<std::string> enrolledCourseIds;
};
void addStudent(std::vector<Student>& students);
Student* findStudentById(std::vector<Student>& students, const std::string& id);
void printStudentGPA(std::vector<Student>& students, std::vector<Course>&
courses);
#endif