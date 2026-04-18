#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fptr;
    int score, val;
    int sum = 0;
    int count = 0;
    float average;

    fptr = fopen("survey.txt", "w");
    if (fptr == NULL) {
        printf("Error: Could not open survey.txt for writing.\n");
        return 1;
    }

    printf("--- Enter Survey Scores ---\n");
    for (int i = 1; i <= 5; i++) {
        printf("Enter score %d (1-10): ", i);
        scanf("%d", &score);

        fprintf(fptr, "%d\n", score);
    }

    fclose(fptr);
    printf("\nScores successfully saved to survey.txt.\n\n");

    fptr = fopen("survey.txt", "r");
    if (fptr == NULL) {
        printf("Error: Could not open survey.txt for reading.\n");
        return 1;
    }

    while (fscanf(fptr, "%d", &val) == 1) {
        sum += val;
        count++;
    }

    fclose(fptr);

    if (count > 0) {
        average = (float)sum / count;

        printf("Survey Results\n");
        printf("Total Scores Read: %d\n", count);
        printf("Sum: %d\n", sum);
        printf("Average: %.2f\n", average);
    } else {
        printf("No data found in the file.\n");
    }

    return 0;
}
