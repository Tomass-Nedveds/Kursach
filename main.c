#include <stdlib.h>
#include <string.h>
#include "students.h"

int id = 0;

int main(int argc, char* argv[]) {

    printf("1.Add\n");
    printf("2.View\n");
    printf("3.Delete\n");
    printf("================\n");

    if(strcmp(argv[1], "add") == 0){
        char* name = argv[2];
        char* sname = argv[3];
        int age = atoi(argv[4]);
        char* course = argv[5];
        addStudent(name, sname, age, course, id);    
    }

    return 0;

}