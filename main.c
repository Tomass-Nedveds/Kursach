#include <stdio.h>

struct students {
    int age;
    char name[50];
    char sname[50];
    char class[50];
};

struct students studenti[20] = {
    {13, "Artem", "Stanko", "px-23"},
    {5, "Pavel", "Durov", "px-22"},
    {5, "Pavel", "Durak", "px-22"},
    {2, "Aetem", "Stanok", "px-23"},
    {40, "Name", "Surname", "px-24"},
    {52, "Timur", "FamilijuNeznaju", "px-24"}
};

int compare_names(char* name1, char* name2) {
    int i = 0;
    while (name1[i] != '\0' && name2[i] != '\0') {
        if (name1[i] < name2[i]) {
            return -1;
        } else if (name1[i] > name2[i]) {
            return 1;
        }
        i++;
    }
    if (name1[i] == '\0' && name2[i] != '\0') {
        return -1;
    } else if (name1[i] != '\0' && name2[i] == '\0') {
        return 1;
    }
    return 0;
}

void delete_student(int* n, char* name, char* sname) {
    int i, j;
    for (i = 0; i < *n; i++) {
        if (compare_names(studenti[i].name, name) == 0 && compare_names(studenti[i].sname, sname) == 0) {
            for (j = i; j < *n - 1; j++) {
                studenti[j] = studenti[j + 1];
            }
            *n--;
            printf("Student %s %s deleted.\n", name, sname);
        }
    }
}

int main() {
    int i, j;
    int n = 6;
    int num;
    char name[50], sname[50];

    printf("Add new student? (yes - 1, no - 0): ");
    scanf("%d", &num);

    if (num == 1) {
        printf("Name: ");
        scanf("%s", studenti[n].name);

        printf("Sname: ");
        scanf("%s", studenti[n].sname);

        printf("Age: ");
        scanf("%d", &studenti[n].age);

        printf("Class: ");
        scanf("%s", studenti[n].class);

        n++;
    }

    printf("Delete student? (yes - 1, no - 0): ");
    scanf("%d", &num);

    if (num == 1) {
        printf("Enter name: ");
        scanf("%s", name);

        printf("Enter surname: ");
        scanf("%s", sname);

        delete_student(&n, name, sname);
    }

    printf("=============== \n");
    printf("Sort by Name: 1\nSort by Surname: 2\nSort by Age: 3\nSort by Class: 4\n");
    printf("Enter your choice: ");
    scanf("%d", &num);

    if (num == 1) {
        for (i = 0; i < n - 1; i++) {
            for (j = 0; j < n - i - 1; j++) {
                if (compare_names(studenti[j].name, studenti[j + 1].name) > 0) {
                    struct students temp = studenti[j];
                    studenti[j] = studenti[j + 1];
                    studenti[j + 1] = temp;
                }
            }
        }
    }

    else if (num == 2) {
        for (i = 0; i < n - 1; i++) {
            for (j = 0; j < n - i - 1; j++) {
                if (compare_names(studenti[j].sname, studenti[j + 1].sname) > 0) {
                    struct students temp = studenti[j];
                    studenti[j] = studenti[j + 1];
                    studenti[j + 1] = temp;
                }
            }
        }
    }

    else if (num == 3) {
        for (i = 0; i < n - 1; i++) {
            for (j = 0; j < n - i - 1; j++) {
                if (studenti[j].age > studenti[j + 1].age) {
                    struct students temp = studenti[j];
                    studenti[j] = studenti[j + 1];
                    studenti[j + 1] = temp;
                }
            }
        }
    }

    else if (num == 4) {
        char enterclass[50];
        printf("Enter class: ");
        scanf("%s", enterclass);
        struct students filtered_students[10];
        int sum = 0;
        for (i = 0; i < n; i++) {
            if (compare_names(studenti[i].class, enterclass) == 0) {
                filtered_students[sum] = studenti[i];
                sum++;
            }
        }

        if (sum == 0) {
            printf("No students in class %s\n", enterclass);
            return 0;
        }

        printf("\nSort by Name: 1\nSort by Surname: 2\nSort by Age: 3\n");
        scanf("%d", &num);

        if (num == 1) {
            for (i = 0; i < sum - 1; i++) {
                for (j = 0; j < sum - i - 1; j++) {
                    if (compare_names(filtered_students[j].name, filtered_students[j + 1].name) > 0) {
                        struct students temp = filtered_students[j];
                        filtered_students[j] = filtered_students[j + 1];
                        filtered_students[j + 1] = temp;
                    }
                }
            }
        }
        
        else if (num == 2) {
            for (i = 0; i < sum - 1; i++) {
                for (j = 0; j < sum - i - 1; j++) {
                    if (compare_names(filtered_students[j].sname, filtered_students[j + 1].sname) > 0) {
                        struct students temp = filtered_students[j];
                        filtered_students[j] = filtered_students[j + 1];
                        filtered_students[j + 1] = temp;
                    }
                }
            }
        }
        
        else if (num == 3) {
            for (i = 0; i < sum - 1; i++) {
                for (j = 0; j < sum - i - 1; j++) {
                    if (filtered_students[j].age > filtered_students[j + 1].age) {
                        struct students temp = filtered_students[j];
                        filtered_students[j] = filtered_students[j + 1];
                        filtered_students[j + 1] = temp;
                    }
                }
            }
        }

        for (i = 0; i < sum; i++) {
            printf("- - - - - - - - \n");
            printf("Name: %s\nSname: %s\nAge: %d\nClass: %s\n",filtered_students[i].name, filtered_students[i].sname, filtered_students[i].age, filtered_students[i].class);
        }
        return 0;
    }

    printf("\nList of students:\n");
    for (i = 0; i < n; i++) {
        printf("- - - - - - - - \n");
        printf("Name: %s\nSname: %s\nAge: %d\nClass: %s\n", studenti[i].name, studenti[i].sname, studenti[i].age, studenti[i].class);
    }

    return 0;
}