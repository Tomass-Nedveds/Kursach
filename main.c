#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "students.h"

int LastId() {
    FILE *fp = fopen("id.txt", "r");
    int id = 0;
    
    fscanf(fp, "%d", &id);
    fclose(fp);
    
    return id;
}

void saveLastId(int id) {
    FILE *fp = fopen("id.txt", "w");
    if (fp != NULL) {
        fprintf(fp, "%d", id);
        fclose(fp);
    }
}

int main(int argc, char* argv[]) {

    if (strcmp(argv[1], "view") == 0) {
        printf("######################\n");
        printf("1. Add\n");
        printf("2. VStudents\n");
        printf("3. Delete\n");
        printf("4. Sort\n");
        printf("5. Change\n");
        printf("######################\n");
    }

    if (strcmp(argv[1], "add") == 0) {
        Student student;
        int id = LastId();

        student.id = ++id;
        strcpy(student.name, argv[2]);
        strcpy(student.sname, argv[3]);
        student.age = atoi(argv[4]);
        strcpy(student.course, argv[5]);

        addStudent(&student);
        saveLastId(id);
    }

    if (strcmp(argv[1], "vstudents") == 0) 
        viewStudents();

    if (strcmp(argv[1], "delete") == 0) {
        int DeleteId = atoi(argv[2]);
        DeleteStudent(DeleteId);
    }

    if (strcmp(argv[1], "sort") == 0) {
        int criterion = atoi(argv[2]);
        sortStudents(criterion);
    }

    if (strcmp(argv[1], "change") == 0) {
        int studentId = atoi(argv[2]);
        const char *newName = argv[3];
        const char *newSname = argv[4];
        int newAge = atoi(argv[5]);
        const char *newCourse = argv[6];

        updateStudent(studentId, newName, newSname, newAge, newCourse);
    }
    return 0;
}