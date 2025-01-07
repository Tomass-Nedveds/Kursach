#ifndef STUDENTS_H
#define STUDENTS_H

typedef struct {
    int id;
    char name[50];
    char sname[50];
    int age;
    char course[50];
} Student;

void saveLastId(int id);
int addStudent(Student *student);
void ViewStudents();
void DeleteStudent(int id);
void sortStudents(int criterion);

#endif