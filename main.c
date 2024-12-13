#include <stdlib.h>
#include "students.h"


int main(int argc, char* argv[]) {
    char name[50]; 
    char sname[50];
    char kurs[50];
    int age;

    printf("Add\n");
    printf("View\n");
    printf("Delete\n");

    if(strcmp(argv[1], "Add") == 0){
        const char* name = argv[2];
        printf("Work");
    }

    printf("%s", name);

    addStudent();

    return 0;

}