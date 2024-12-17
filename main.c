#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "students.h"

int LastId() {
    FILE *fp = fopen("id.txt", "r");
    int id = 0;
    if (fp != NULL) {
        fscanf(fp, "%d", &id);
        fclose(fp);
    }
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
    printf("######################\n");
    printf("1. Add\n");
    printf("2. View\n");
    printf("3. Delete\n");
    printf("======================\n");


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

    return 0;
}
