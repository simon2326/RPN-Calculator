/*RPN Calculator - 3rd practice (Operating Systems)*/
#include <stdio.h>
#include <math.h>

float stack[8];

void showstack(float _stack[])
{
    for (int i = 8; i > 0; i--)
    {
        printf("|%d| -> ", i);
        printf("%f\n", _stack[8 - i]);
    }
}

void risestack()
{
    for (int i = 1; i < 8; i++)
    {
        stack[i - 1] = stack[i];
    }
}

void downstack()
{
    for (int i = 7; i > 0; i--)
    {
        stack[i] = stack[i - 1];
    }
}

char operations()
{
    char op;
    printf("Select the operator\n [+] - Addition\n [-] - Subtraction\n [*] - Multiplication\n [/] - Division\n [r] - (√) Square root\n [p] - (x²) Power\n [s] - Sin(x)\n [c] - Cos(x)\n [t] - Tan(x)\n [l] - Ln(x)\n");
    op = getchar();
    if (op != '+' && op != '-' && op != '*' && op != '/' && op != 'r' && op != 'p' && op != 's' && op != 'c' && op != 't' && op != 'l')
    {
        printf("You selected a non-defined operation\n");
        operations();
    }
    // printf("%c\n\n\n", op);
    return op;
}

int menu(void)
{
    int opt;
    printf("Choose an option\n 1. Enter a number\n 2. Select operation\n 3. Clear last\n 4. Clear everything\n 5. Exit\n --> ");
    scanf("%d", &opt);
    return opt;
}

int main()
{
    // showstack(stack);
    int choice;
    do
    {
        choice = menu();
        switch (choice)
        {
        case 1:
            float number;
            printf("Enter the number please");
            scanf("%f", &number);
            risestack();
            stack[7] = number;
            showstack(stack);
            break;
        case 2:
            // char op = operations();
            switch (operations())
            {
            case '+':
                stack[7] = stack[7] + stack[6];
                // downstack();
                break;

            default:
                break;
            }
            showstack(stack);
            break;
        case 3:
            printf("holi");
            break;
        case 4:
            printf("holi");
            break;
        case 5:
            printf("bai");
            break;
        default:
            break;
        }
    } while (choice != 5);
    printf("\n\n");
    return 0;
}