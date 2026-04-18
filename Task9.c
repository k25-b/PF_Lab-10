#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;

    file = fopen("config.txt", "r");

    if (file == NULL) {
        printf("Notice: config.txt not found.\n");
        printf("Creating default config.txt with placeholder settings...\n");

        file = fopen("config.txt", "w");

        if (file == NULL) {
            printf("Error: Could not create config.txt due to system permissions.\n");
            return 1;
        }

        fprintf(file, "max_users=50\n");
        fprintf(file, "timeout=30\n");
        fprintf(file, "debug_mode=1\n");

        fclose(file);

        printf("Success: Default config.txt created successfully.\n");

    } else {
        printf("Success: config.txt found. Loading settings...\n\n");
        printf("Current Settings\n");

        char ch;
        while ((ch = fgetc(file)) != EOF) {
            putchar(ch);
        }

        fclose(file);
    }

    return 0;
}
