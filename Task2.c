#include <stdio.h>
#include<string.h>
int main() {
    char masterpassword[] = "password";
    char guessedpassword[100];
    int counter = 0;
    while (1){
        if (counter > 2) {
            printf("Enough tries!");
            break;
        }
        if (counter == 2) {
            printf("Partial match is\n");
            for (int i = 0; i < 3; i++) {
                if (masterpassword[i] == guessedpassword[i]) {
                    printf("%c",guessedpassword[i]);
                }
            }
            printf("\n");
        }

        printf("Enter your password: ");
        scanf("%s",guessedpassword);
        if(strcmp(masterpassword,guessedpassword)==0) {
            printf("Your password is valid.\n");
            return 0;
        }
        else if (strcmp(masterpassword,guessedpassword)!=0) {
            printf("Your password is invalid.\n");
            counter++;

        }
    }
}
