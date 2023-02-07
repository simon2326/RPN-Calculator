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
    printf("\n\n");
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

/*Parse degrees to radians*/
double degtorad(float degrees)
{
    double rad = (degrees * M_PI) / 180;
    return rad;
}

/*Operations menu offered by the RPN Calculatoror -chars*/
char operations()
{
    char op;
    printf("Select the operator\n [+] - Addition\n [-] - Subtraction\n [*] - Multiplication\n [/] - Division\n [r] - (√) Square root\n [p] - (x^y) Power\n [s] - Sin(x)\n [c] - Cos(x)\n [t] - Tan(x)\n [l] - Ln(x)\n");
    scanf(" %c", &op);
    printf("\033[2J");
    if (op != '+' && op != '-' && op != '*' && op != '/' && op != 'r' && op != 'p' && op != 's' && op != 'c' && op != 't' && op != 'l')
    {
        printf("\033[2J");
        printf("You selected a non-defined operation, choose one of the operations below\n");
        operations();
    }
    return op;
}

/*Option menu*/
int menu(void)
{
    int opt;
    char x;
    do
    {
        printf("Choose an option\n 1. Enter a number\n 2. Select operation\n 3. Clear last\n 4. Clear everything\n 5. Exit\n --> ");
        scanf("%d", &opt);
        printf("\n");
    } while ((x = getchar()) != '\n' && x != EOF); /*Do while for avoiding chars and infinite loops*/

    if (opt != 1 && opt != 2 && opt != 3 && opt != 4 && opt != 5)
    {
        printf("You selected an option thats is not on the menu, please select other\n\n");
        menu();
    }
    return opt;
}

int main()
{
    int choice;
    float answer;
    double rad;
    printf("\033[2J");
    showstack(stack);
    do
    {
        choice = menu();
        switch (choice)
        {
        case 1: /*Enter a number to the stack*/
            float number;
            printf("Enter the number please\n");
            scanf("%f", &number);
            risestack(); /*When the user enters the number, the stack goes up so the input can be shown in the stack[7] position*/
            stack[7] = number;
            printf("\033[2J");
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
                if (stack[7] == 0)
                {
                    printf("\033[2J");
                    printf("Math Error!\n");
                    printf("Division by 0 isn't defined\n\n");
                }
                else
                {
                    answer = stack[6] / stack[7];
                    downstack();
                    stack[7] = answer;
                }
                break;

            case 'r': /*Square root*/
                if (stack[7] >= 0)
                {
                    answer = sqrt(stack[7]);
                    stack[7] = answer;
                }
                else
                {
                    printf("\033[2J");
                    printf("Math Error!\n");
                    printf("The domain of the square root is only defined for positive numbers and 0\n");
                    printf("This calculator doesn't operate with imaginary numbers, try with a positive number\n\n");
                }
                break;

            case 'p': /*x to the power of y*/
                answer = pow(stack[6], stack[7]);
                downstack();
                stack[7] = answer;
                break;

            case 's': /*sin(x)*/
                rad = degtorad(stack[7]);
                answer = sin(rad);
                stack[7] = answer;
                break;

            case 'c': /*cos(x)*/
                rad = degtorad(stack[7]);
                answer = cos(rad);
                stack[7] = answer;
                break;

            case 't':                   /*tan(x)*/
                if (cos(stack[7]) == 0) // tan(x) = sin(x)/cos(x) -> If cos(x) == 0 then tan(x) doesn't exist.
                {
                    printf("\033[2J");
                    printf("Math Error!\n");
                    printf("Tan(x) function isn't defined for 90 neither 270 ...\n\n");
                }
                else
                {
                    rad = degtorad(stack[7]);
                    answer = tan(rad);
                    stack[7] = answer;
                }
                break;

            case 'l': /*ln(x)*/
                if (stack[7] <= 0)
                {
                    printf("\033[2J");
                    printf("Ln isn't defined for negative numbers or 0 Domain -> (0,inf)\n\n");
                }
                else
                {
                    answer = log(stack[7]);
                    stack[7] = answer;
                }
                break;

            default:
                break;
            }
            showstack(stack);
            break;

        case 3: /*Clear the last value - stack[7]*/
            downstack();
            printf("\033[2J");
            showstack(stack);
            break;

        case 4: /*Clear everything - Clear the stack*/
            for (int i = 7; i >= 0; i--)
            {
                stack[i] = 0;
            }
            printf("\033[2J");
            showstack(stack);
            break;

        case 5: /*Exit*/
            printf("Thanks for using the RPN Calculator");
            break;

        default:
            break;
        }
    } while (choice != 5);
    printf("\n\n");
    return 0;
}