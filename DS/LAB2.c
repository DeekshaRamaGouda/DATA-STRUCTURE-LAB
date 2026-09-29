#include <stdio.h>

int priority(char ch)
{
    if (ch == '*' || ch == '/')
        return 2;
    if (ch == '+' || ch == '-')
        return 1;
    return 0;
}

int main()
{
    char infix[20], postfix[20], stack[20];
    int top = -1, i, j = 0;
    char ch;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    for (i = 0; infix[i] != '\0'; i++)
    {
        ch = infix[i];

        if (ch >= 'A' && ch <= 'Z')
        {
            postfix[j] = ch;
            j++;
        }
        else if (ch == '(')
        {
            top++;
            stack[top] = ch;
        }
        else if (ch == ')')
        {
            while (stack[top] != '(')
            {
                postfix[j] = stack[top];
                j++;
                top--;
            }
            top--;
        }
        else
        {
            while (top != -1 && stack[top] != '(' && priority(stack[top]) >= priority(ch))
            {
                postfix[j] = stack[top];
                j++;
                top--;
            }

            top++;
            stack[top] = ch;
        }
    }

    while (top != -1)
    {
        postfix[j] = stack[top];
        j++;
        top--;
    }

    postfix[j] = '\0';

    printf("Postfix expression: %s", postfix);

    return 0;
}
