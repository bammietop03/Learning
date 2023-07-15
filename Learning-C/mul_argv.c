#include <stdio.h>
#include <stdlib.h>

int lenght(char *str)
{
    int len = 0;
    while (str[len] != '\0')
    {
        len++;
    }
    return len;
}

int is_digit(char *str)
{
    int len1;
    int i;

    len1 = lenght(str);

    for (i = 0; i < len1; i++)
    {
        if (str[i] >= '0' || str[i] <= '9')
        {
            return (1);

        }
        
    }
    return (0);

}

int main(int argc, char *argv[])
{
    int num1, num2, mul;

    if ( argc != 3)
    {
        printf("invalid parameters\n");
        return (98);
    }

    if (!is_digit(argv[1]) || !is_digit(argv[2]))
    {
        printf("invalid parameters\n");
        return (98);
    }

    if(is_digit(argv[1]) || is_digit(argv[2]))
    {
        num1 = atoi(argv[1]);
        num2 = atoi(argv[2]);

        mul = num1 * num2;

        printf("%d\n", mul);
    }

    
}