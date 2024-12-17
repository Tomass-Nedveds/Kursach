#include <stdio.h>
#include <string.h>
#include "students.h"

char *stxt = "studenti.txt";

int addStudent(Student *student) {

    
    FILE *fp = fopen(stxt, "a");

    fprintf(fp, "%d %s %s %d %s\n", student->id, student->name, student->sname, student->age, student->course);

    fclose(fp);
    printf("Student added\n");

    return 0;
}
