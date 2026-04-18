#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    char productName[50];
    int quantity;

    file = fopen("inventory.txt", "a");

    if (file == NULL) {
        printf("Error: Could not open inventory.txt for appending.\n");
        return 1;
    }

    printf("Enter product name: ");
    scanf("%49s", productName);
    printf("Enter quantity: ");
    scanf("%d", &quantity);

    fprintf(file, "Product: %s | Quantity: %d\n", productName, quantity);

    fclose(file);

    printf("\nData successfully appended.\n");
    printf("Current Inventory Contents\n");

    file = fopen("inventory.txt", "r");

    if (file == NULL) {
        printf("Error: Could not open inventory.txt for reading.\n");
        return 1;
    }

    char ch;
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }

    fclose(file);

    return 0;
}
