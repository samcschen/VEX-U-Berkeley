#include <stdio.h>
#include <math.h>

double addition(double a, double b);
double subtraction(double a, double b);
double multiplication(double a, double b);
double division(double a, double b);

int main()
{
    double a = 0, b = 0, answer = 0;
    char function;
    printf("Calculator program, made by Julian Meyn.\n");
    
    printf("What math function do you want performed? (a,s,m,d allowed)\n");
    printf(">>> ");
    scanf("%c", &function);
    
    printf("What's your first number?\n");
    printf(">>> ");
    scanf("%lf", &a);
    
    printf("What's your second number?\n");
    printf(">>> ");
    scanf("%lf", &b);

    switch(function)
    {
        case 'a': answer = addition(a, b);
            break;
        case 's': answer = subtraction(a, b);
            break;
        case 'm': answer = multiplication(a, b);
            break;
        case 'd': answer = division(a, b);
            break;
        default: 
            printf("You did not give a proper math function! Ending program.");
            return -1;
    }

    printf("Your answer is %g", answer);

    return answer;
}

double addition(double a, double b)
{
    return a + b;
}

double subtraction(double a, double b)
{
    return a - b;
}

//Now without the use of *!
double multiplication(double a, double b)
{
    //if a or b are zero, return zero property of mult.
    if( a == 0 || b == 0 )
    {
        return 0;
    }

    int swap = 1;
    int i = 0;

    if( a < 0 )
    {
        if( b < 0 )
        {
            a = -a;
            b = -b;
        }
        else
        {
            a = -a;
            b = b;
            swap = -1;
        }
    }
    else if( b < 0 )
    {
        a = a;
        b = -b;
        swap = -1;
    }

    return (a / (1 / b)) * swap;
}

//Now without the use of /!
double division(double a, double b)
{
    if( b == 0 )
    {
        printf("Error dividing by 0! Ending program.");
        return -1;
    }
    
    if( a == 0 )
    {
        return 0;
    }

    unsigned int precision = 6;
    int exp = 0;
    b = frexp(b, &exp);
    double guess = sqrt(2.0);

    if( b < 0 )
    {
        guess = -guess;
    }

    while( precision-- )
    {
        guess *= 2 - b * guess;
    }

    return ldexp(a * guess, -exp);
}