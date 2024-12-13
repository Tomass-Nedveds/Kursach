#include <stdio.h>
#include "students.h"

char *stxt = "studenti.txt";

int addStudent(char* name, char* sname, int age, char* course, int id){
    id++;
    FILE *fp = fopen(stxt, "a");

    fprintf(fp, "%d %s %s %d %s\n", id, name, sname, age, course);

    fclose(fp);
    }