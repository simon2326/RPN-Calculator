/*RPN Calculator - 3rd practice (Operating Systems)*/
#include <stdio.h>
#include <math.h>

float stack[8]; // Stack

/*Print the stack*/
void showstack(float _stack[])
{
    for (int i = 8; i > 0; i--)
    {
        printf("|%d| -> ", i);
        printf("%f\n", _stack[8 - i]);
    }
}

/*Move the stack up*/
void risestack()
{
    for (int i = 1; i < 8; i++)
    {
        stack[i - 1] = stack[i];
    }
}

/*Move the stack down*/
void downstack()
{
    for (int i = 7; i > 0; i--)
    {
        stack[i] = stack[i - 1];
    }
}

float degtorad(float degrees)
{
    float rad = (degrees * M_PI) / 180;
    return rad;
}

/*Operations menu offered by the RPN Calculatoror -chars*/
char operations()
{
    char op;
    printf("Select the operator\n [+] - Addition\n [-] - Subtraction\n [*] - Multiplication\n [/] - Division\n [r] - (√) Square root\n [p] - (x^y) Power\n [s] - Sin(x)\n [c] - Cos(x)\n [t] - Tan(x)\n [l] - Ln(x)\n");
    scanf("%s", &op);
    if (op != '+' && op != '-' && op != '*' && op != '/' && op != 'r' && op != 'p' && op != 's' && op != 'c' && op != 't' && op != 'l')
    {
        printf("You selected a non-defined operation, choose one of the operations below\n");
        operations();
    }
    return op;
}

/*Option menu*/
int menu(void)
{
    int opt;
    printf("Choose an option\n 1. Enter a number\n 2. Select operation\n 3. Clear last\n 4. Clear everything\n 5. Exit\n --> ");
    scanf("%d", &opt);
    return opt;
}

int main()
{
    int choice;
    float rad;
    float answer;
    do
    {
        choice = menu();
        switch (choice)
        {
        case 1: /*Enter a number to the stack*/
            float number;
            printf("Enter the number please");
            scanf("%f", &number);
            risestack(); /*When the user enters the number, the stack goes up so the input can be shown in the stack[7] position*/
            stack[7] = number;
            showstack(stack);
            break;

        case 2:
            switch (operations()) /*Switch for the chosen char (operation)*/
            {
            case '+': /*Addition*/
                answer = stack[6] + stack[7];
                downstack();
                stack[7] = answer;
                break;

            case '-': /*Substraction*/
                answer = stack[6] - stack[7];
                downstack();
                stack[7] = answer;
                break;

            case '*': /*Multiplication*/
                answer = stack[6] * stack[7];
                downstack();
                stack[7] = answer;
                break;

            case '/': /*Division*/
                answer = stack[6] / stack[7];
                downstack();
                stack[7] = answer;
                break;

            case 'r': /*Square root*/
                answer = sqrt(stack[7]);
                downstack();
                stack[7] = answer;
                break;

            case 'p': /*x to the power of y*/
                answer = pow(stack[6], stack[7]);
                downstack();
                stack[7] = answer;
                break;

            case 's': /*sin(x)*/
                rad = degtorad(stack[7]);
                answer = sin(rad);
                downstack();
                stack[7] = answer;
                break;

            case 'c': /*cos(x)*/
                rad = degtorad(stack[7]);
                answer = cos(rad);
                downstack();
                stack[7] = answer;
                break;

            case 't': /*tan(x)*/
                rad = degtorad(stack[7]);
                answer = tan(rad);
                downstack();
                stack[7] = answer;
                break;

            case 'l': /*ln(x)*/
                answer = log(stack[7]);
                downstack();
                stack[7] = answer;
                break;

            default:
                break;
            }
            showstack(stack);
            break;

        case 3: /*Clear the last value - stack[7]*/
            printf("holi");
            break;

        case 4: /*Clear everything - Clear the stack*/
            printf("holi");
            break;

        case 5: /*Exit*/
            printf("bai");
            break;

        default:
            break;
        }
    } while (choice != 5);
    printf("\n\n");
    return 0;
}