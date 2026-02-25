#ifndef COURSE_H
#define COURSE_H
#include <bits\stdc++.h>
#include "student.h"
using namespace std;

struct Course {
    std::string id; // e.g., "CS101"
    std::string title; // e.g., "Intro to C++"
    int credit_hours; // e.g., 3
    std::vector<std::pair<std::string, double>> grades; // pair<studentId, grade>
};
void addCourse(std::vector<Course>& courses);
Course* findCourseById(std::vector<Course>& courses, const std::string& id);
void recordGrade(std::vector<Course>& courses, std::vector<Student>& students);
void printCourseReport(std::vector<Course>& courses, std::vector<Student>&
students);
#endif