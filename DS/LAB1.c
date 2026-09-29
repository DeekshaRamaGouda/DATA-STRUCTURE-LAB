#include <stdio.h>

int main()
{
    int stack[5], top = -1;
    int choice, value, i;

    while (1)
    {
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            if (top == 4)
                printf("Stack Overflow");
            else
            {
                printf("Enter value: ");
                scanf("%d", &value);
                top++;
                stack[top] = value;
            }
        }
        else if (choice == 2)
        {
            if (top == -1)
                printf("Stack Underflow");
            else
            {
                printf("Popped value = %d", stack[top]);
                top--;
            }
        }
        else if (choice == 3)
        {
            if (top == -1)
                printf("Stack is empty");
            else
            {
                printf("Stack elements are: ");
                for (i = top; i >= 0; i--)
                    printf("%d ", stack[i]);
            }
        }
        else if (choice == 4)
            break;
        else
            printf("Invalid choice");
    }

    return 0;
}
