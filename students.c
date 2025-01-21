#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "students.h"

char *stxt = "studenti.txt";

int addStudent(Student *student) {
    FILE *fp = fopen(stxt, "a");
    fprintf(fp, "%d %s %s %d %s\n", student->id, student->name, student->sname, student->age, student->course);
    fclose(fp);
    printf("======================\n");
    printf("Student added\n");
    printf("======================\n");
    return 0;
}

void viewStudents() {
    FILE *fp = fopen(stxt, "r");
    Student student;
    printf("=========================================================\n");
    printf("ID\tName\t\tSname\t\tAge\tCourse\n");
    printf("=========================================================\n");

    while (fscanf(fp, "%d %s %s %d %s", &student.id, student.name, student.sname, &student.age, student.course) == 5) {
        printf("%d\t%-11s\t%-11s\t%d\t%-11s\n", student.id, student.name, student.sname, student.age, student.course);
    }

    fclose(fp);
}

void renumberStudents() {
    FILE *fp = fopen(stxt, "r");
    Student students[50];
    int count = 0;

    while (fscanf(fp, "%d %s %s %d %s", &students[count].id, students[count].name, students[count].sname, &students[count].age, students[count].course) == 5) {
        count++;
    }
    fclose(fp);

    for (int i = 0; i < count; i++) {
        students[i].id = i + 1;
    }

    FILE *new_fp = fopen(stxt, "w");

    for (int i = 0; i < count; i++) {
        fprintf(new_fp, "%d %s %s %d %s\n", students[i].id, students[i].name, students[i].sname, students[i].age, students[i].course);
    }

    fclose(new_fp);

    int lastId = count;
    saveLastId(lastId);
}

void DeleteStudent(int DeleteId) {
    FILE *fp = fopen(stxt, "r");
    FILE *temp = fopen("temp.txt", "w");

    Student student;
    int found = 0;

    while (fscanf(fp, "%d %s %s %d %s", &student.id, student.name, student.sname, &student.age, student.course) == 5) {
        if (student.id != DeleteId) {
            fprintf(temp, "%d %s %s %d %s\n", student.id, student.name, student.sname, student.age, student.course);
        } 
        else {
            found = 1;
        }
    }

    fclose(fp);
    fclose(temp);

    if (found) {
        remove(stxt);
        rename("temp.txt", stxt);
        printf("Student deleted: %d\n", DeleteId);
        renumberStudents();
    } 
    else {
        printf("======================\n");
        remove("temp.txt");
        printf("Student: %d not found\n", DeleteId);
        printf("======================\n");
    }
}



    int compareId(const void *a, const void *b) {
        return ((Student *)a)->id - ((Student *)b)->id;
    }

    int compareName(const void *a, const void *b) {
        return strcmp(((Student *)a)->name, ((Student *)b)->name);
    }

    int compareSname(const void *a, const void *b) {
        return strcmp(((Student *)a)->sname, ((Student *)b)->sname);
    }

    int compareAge(const void *a, const void *b) {
        return ((Student *)a)->age - ((Student *)b)->age;
    }

    int compareCourse(const void *a, const void *b) {
        return strcmp(((Student *)a)->course, ((Student *)b)->course);
    }

    void sortStudents(int criterion) {
    FILE *fp = fopen(stxt, "r");

    Student students[100];
    int count = 0;

    while (fscanf(fp, "%d %s %s %d %s", &students[count].id, students[count].name, students[count].sname, &students[count].age, students[count].course) == 5) {
        count++;
    }
    fclose(fp);

    int (*compare)(const void *, const void *) = NULL;
    switch (criterion) {
        case 1:
            compare = compareId;
            printf("Invalid sort criterion\n");
            break;
        case 2:
            compare = compareName;
            break;
        case 3:
            compare = compareSname;
            break;
        case 4:
            compare = compareAge;
            break;
        case 5:
            compare = compareCourse;
            break;
    }

    qsort(students, count, sizeof(Student), compare);

    FILE *new_fp = fopen(stxt, "w");
    if (new_fp == NULL) {
        printf("Error writing to file\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(new_fp, "%d %s %s %d %s\n", students[i].id, students[i].name, students[i].sname, students[i].age, students[i].course);
    }
    fclose(new_fp);

    printf("Sorted students list:\n");
    for (int i = 0; i < count; i++) {
        printf("%d %s %s %d %s\n", students[i].id, students[i].name, students[i].sname, students[i].age, students[i].course);
    }
}



    void updateStudent(int studentId, const char *newName, const char *newSname, int newAge, const char *newCourse) {
    FILE *fp = fopen(stxt, "r");

    Student students[50];
    int count = 0;
    int found = 0;

    while (fscanf(fp, "%d %s %s %d %s", &students[count].id, students[count].name, students[count].sname, &students[count].age, students[count].course) == 5) {
        if (students[count].id == studentId) {
            found = 1;

            strncpy(students[count].name, newName, sizeof(students[count].name) - 1);
            strncpy(students[count].sname, newSname, sizeof(students[count].sname) - 1);
            students[count].age = newAge;
            strncpy(students[count].course, newCourse, sizeof(students[count].course) - 1);
        }
        count++;
    }
    fclose(fp);

    if (!found) {
        printf("Student with ID %d not found\n", studentId);
        return;
    }

    FILE *new_fp = fopen(stxt, "w");

    for (int i = 0; i < count; i++) {
        fprintf(new_fp, "%d %s %s %d %s\n", students[i].id, students[i].name, students[i].sname, students[i].age, students[i].course);
    }
    fclose(new_fp);
}