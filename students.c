#include <stdio.h>
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

    printf("=================================================\n");
    printf("ID\tName\tSname\tAge\tCourse\n");
    printf("==================================================\n");

    while (fscanf(fp, "%d %s %s %d %s", &student.id, student.name, student.sname, &student.age, student.course) == 5) {
        printf("%d\t%s\t%s\t%d\t%s\n", student.id, student.name, student.sname, student.age, student.course);
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
        printf("Student deleted: %d", DeleteId);
        renumberStudents();
    } 
    else {
        printf("======================\n");
        remove("temp.txt");
        printf("Student: %d not found\n", DeleteId);
        printf("======================\n");

    }
}