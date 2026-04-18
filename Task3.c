#include <stdio.h>
#include <string.h>

int main() {
    char raw_email[100];
    char email_copy[100];
    char display_label[150] = "Email: ";
    char *at_ptr;

    printf("Enter an email address: ");
    scanf("%s", raw_email);

    strcpy(email_copy, raw_email);

    at_ptr = strchr(email_copy, '@');

    if (at_ptr == NULL) {
        printf("Error: Invalid email. Missing the '@' symbol.\n");
        return 1;
    }


    char *domain = at_ptr + 1;

    if (strstr(domain, ".") == NULL) {
        printf("Error: The domain portion must contain a '.' separator.\n");
        return 1;
    }

    strcat(display_label, email_copy);

    printf("%s\n", display_label);

    printf("Extracted Domain: %s\n", domain);

    return 0;
}
