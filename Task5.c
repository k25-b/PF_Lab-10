#include <stdio.h>
#include <string.h>

int main() {
    char words[6][20];
    int seen[6] = {0};

    printf("Enter 6 words (separated by spaces or pressing Enter):\n");
    for (int i = 0; i < 6; i++) {
        scanf("%s", words[i]);
    }

    printf("\n--- Text Analysis Results ---\n");

    for (int i = 0; i < 6; i++) {
        if (seen[i] == 1) {
            continue;
        }

        int count = 1;
        seen[i] = 1;

        for (int j = i + 1; j < 6; j++) {
            if (strcmp(words[i], words[j]) == 0) {
                count++;
                seen[j] = 1;
            }
        }

        printf("Word: %s (Appears %d times)\n", words[i], count);

        printf("Characters: ");

        for (int j = 0; words[i][j] != '\0'; j++) {
            printf("%c ", words[i][j]);
        }
        printf("\n\n");
    }

    return 0;
}
