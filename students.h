#ifndef STUDENTS_H
#define STUDENTS_H

struct students {
    int id;
    int age;
    char name[20];
    char surname[20];
    char kurs[10];
};

char addStudent();

#endif