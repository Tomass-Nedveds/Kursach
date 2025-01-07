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

    if (argc < 2) {
        printf("Usage: ./main <command> [args]\n");
        return 1;
    }

    if (strcmp(argv[1], "view") == 0) {
        printf("######################\n");
        printf("1. Add\n");
        printf("2. View Students\n");
        printf("3. Delete\n");
        printf("######################\n\n\n");
    }
    else if (strcmp(argv[1], "sort") == 0) {
        int criterion = atoi(argv[2]);
        sortStudents(criterion);
    }

    return 0;
}
