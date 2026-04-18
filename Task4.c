#include <stdio.h>
#include <string.h>

int main() {
    char names[5][30];
    char search_name[30];
    int found = 0;

    // 1. Gather the names
    printf("Enter the names of 5 students:\n");
    for (int i = 0; i < 5; i++) {
        printf("Student %d: ", i + 1);
        fgets(names[i], 30, stdin);

        int len = strlen(names[i]);
        if (len > 0 && names[i][len - 1] == '\n') {
            names[i][len - 1] = '\0';
        }
    }

    for (int i = 0; i < 5; i++) {
        printf("Position %d: ", i);
        fputs(names[i], stdout);
        printf("\n");
    }
    printf("\nEnter a name to search for: ");
    fgets(search_name, 30, stdin);

    int search_len = strlen(search_name);
    if (search_len > 0 && search_name[search_len - 1] == '\n') {
        search_name[search_len - 1] = '\0';
    }

    for (int i = 0; i < 5; i++) {
        if (strcmp(names[i], search_name) == 0) {
            printf("Found at position %d\n", i);
            found = 1;
            break;
        }
    }

    if (found == 0) {
        printf("Student not found\n");
    }

    return 0;
}
