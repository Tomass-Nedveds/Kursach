#ifndef STUDENTS_H
#define STUDENTS_H

struct students {
    int id;
    int age;
    char name[50];
    char surname[50];
    char kurs[50];
    char path[] = "studenti.txt";
};

char addStudent(){
    if (num == 1) {
            FILE *fp = fopen(path "a");


        return 0;
    }
}
#endif