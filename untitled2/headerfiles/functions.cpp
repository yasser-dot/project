#include <bits\stdc++.h>
#include "course.h"
#include "student.h"
using namespace std;

void addStudent(std::vector<Student>& students) {
   Student s1 ;
   cout << "Enter name: ";
   getline( cin,s1.name);
   cout << "enter id: ";
   cin >> s1.id;
   cout << "enter academic year: ";
   cin>>s1.year;
   cout << "enter number of courses: ";
   cin >> s1.numcourses;
cout << "enter courses IDs: ";
   for (int i = 0; i < s1.numcourses;++i) {
      string idcourse;
      cin >> idcourse;
      s1.enrolledCourseIds.push_back(idcourse);
   }
   students.push_back(s1);
cout << "student added"<< endl;;
}

Student* findStudentById(std::vector<Student>& students, const std::string& id) {
   for (int i = 0;i<students.size();++i) {
      if (id == students[i].id) {
         return &students[i];
      }
   }
   return nullptr;
}
void addCourse(std::vector<Course>& courses) {
   Course c1;
   cout << "Enter name: ";
   getline( cin,c1.title);
   cout << "enter id: ";
   cin >> c1.id;
   cout << "enter credit hours: ";
   cin >> c1.credit_hours;
   double grade;
   string studentId;
   cout << "Enter Student ID and the Grade: ";
   cin >> studentId;
   cin >> grade;
   c1.grades.push_back({studentId,grade});
   courses.push_back(c1);
   cout << "Course added"<< endl;
}
Course* findCourseById(std::vector<Course>& courses, const std::string& courseid) {
   for (int i = 0; i < courses.size(); ++i) {
      if (courses[i].id == courseid) {
         return &courses[i];
      }
   }
   return nullptr;
}
void printStudentGPA(std::vector<Student>& students, std::vector<Course>&
courses) {

}




int main() {


}



