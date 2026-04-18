#include <stdio.h>
#include <string.h>
int getPrecedence(char x) {
    if (x == '+' || x == '-') {
        return 1;
    }
    else if (x == '*' || x == '/') {
        return 2;
    }


    int main(){
        char stack[10] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
        char infix[50];
        while (1) {
            int top = -1;
            printf("Enter infix expression: ");
            scanf("%s", infix);
            for (int i = 0; i < strlen(infix); i++) {
                if ((infix(i) > 'A' && infix(i) < 'Z') || (infix(i) > 'a' && infix(i) < 'z')) {
                    printf("%c", infix(i));
                }
                else if (infix(i) == '(') {
                    top++;
                    stack[top] = infix(i);
                }
                else if (infix(i) == ')') {
                    for (int j = top; j >= 0; j--) {

                        if (stack[j] == '(') {
                            printf("%c", stack[j]);
                            stack[j] = ' ';
                            top--;
                            break;
                        }
                        printf("%c", stack[j]);
                        stack[j] = ' ';
                        top--;

                    }
                }
                else {
                    while (top !=-1 && stack[top] != '(' && getPrecedence(stack[top]) >= getPrecedence(infix[i])) {
                        printf("%c", stack[top]);
                        stack[top] = ' ';
                        top--;
                    }
                }
            }
            for (int x = 0; x < top; x++) {
                stack[x] = ' ';
                top--;
            }
            printf("\n");
          }

    }

}
