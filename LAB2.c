#include <stdio.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char ch) {
    stack[++top] = ch;
}

char pop() {
    return stack[top--];
}

char peek() {
    return stack[top];
}

int precedence(char op) {
    if (op == '^')
        return 3;
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}

void infixToPostfix(char infix[], char postfix[]) {
    int i = 0, j = 0;
    char ch;

    while ((ch = infix[i++]) != '\0') {

        // If operand, add directly to postfix
        if (isalnum(ch)) {
            postfix[j++] = ch;
        }

        // If '(', push to stack
        else if (ch == '(') {
            push(ch);
        }

        // If ')', pop until '('
        else if (ch == ')') {
            while (top != -1 && peek() != '(') {
                postfix[j++] = pop();
            }

            if (top != -1)
                pop(); // Remove '('
        }

        // If operator
        else {
            while (top != -1 &&
                   peek() != '(' &&
                   (precedence(peek()) > precedence(ch) ||
                   (precedence(peek()) == precedence(ch) && ch != '^'))) {
                postfix[j++] = pop();
            }

            push(ch);
        }
    }

    // Pop remaining operators
    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter infix expression: ");
    scanf("%99s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
