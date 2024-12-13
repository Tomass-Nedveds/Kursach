#include <stdio.h>
#include "students.h"

char *stxt = "data/studenti.txt";

int addStudent(int answer){
    if(answer == 1){
    FILE *fp = fopen(stxt,"a");

    printf("work");

    fclose(fp);
    }
    
};