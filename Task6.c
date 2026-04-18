#include <stdio.h>

int main() {
    FILE *fptr;
    char name[50];
    int grade;
    fptr = fopen("grades.txt", "w");

    if (fptr == NULL) {
        printf("Error: Could not open file for writing.\n");
        return 1;
    }

    printf("Enter grades for 3 students:\n");
    for (int i = 0; i < 3; i++) {
        printf("\nStudent %d Name: ", i + 1);
        scanf("%s", name);
        printf("Student %d Grade: ", i + 1);
        scanf("%d", &grade);

        fprintf(fptr, "%s %d\n", name, grade);
    }

    fclose(fptr);
    printf("\n Data successfully saved to grades.txt!\n\n");

    fptr = fopen("grades.txt", "r");

    if (fptr == NULL) {
        printf("Error: Could not open file for reading.\n");
        return 1;
    }

    printf("--- Reading from grades.txt ---\n");
    while (fscanf(fptr, "%s %d", name, &grade) == 2) {
        printf("Name: %s | Grade: %d\n", name, grade);
    }

    fclose(fptr);

    return 0;
}
