#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main() {
    int name_validity = 0;
    int has_digit = 0;
    char name[20];

    printf("Enter your name: ");
    scanf("%s",name);

    if (strlen(name) > 20) {
        printf("Your name is too long\n");
        printf("\n invalid!");
    }
    else if (strlen(name) < 3){
        printf("Your name is too short\n");
        printf("\n invalid!");
    }
    else if (name[0] == ' ') {
        printf("Name cannot start with a space");
        printf("\n invalid!");
    }
    else if (name[strlen(name)-1] == ' ') {
        printf("Name cannot end with a space");
        printf("\n invalid!");
    }
    else {
        for(int i = 0; i < strlen(name); i++) {
            if (isdigit(name[i])) {
                has_digit = 1;
                break;
            }
        }
        if (has_digit == 1) {
            printf("Name cannot have a digit in it");
            printf("\n invalid!");
        }
        else {
            printf("Valid Name");
        }
    }

    return 0;
}
