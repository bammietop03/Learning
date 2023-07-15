#include <stdio.h>
#include <string.h>

char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
    int len1, len2;
    int i = 0;
    int j = 0;
    int carry = 0;
    int digit1, digit2, sum;

    len1 = strlen(n1);
    len2 = strlen(n2); 

    /*len1 = 0;
    while (n1[len1] != '\0')
        len1++;

    len2 = 0;
    while (n2[len2] != '\0')
        len2++; */
    
    
    

    if (len1 >= size_r || len2 >= size_r)
        return 0;

    while (i < len1 || i < len2 || carry)
    {
        if(i < len1)
            digit1 = n1[len1 - 1 - i] - '0';
        else
            digit1 = 0;

        if (i < len2)
            digit2 = n2[len2 - 1 - i] - '0';
        else
            digit2 = 0;

        sum = digit1 + digit2 + carry;

        carry = sum / 10;

        if (j < size_r - 1)
            r[j] = sum % 10 + '0';
        else
            return 0;

        i++;
        j++;
    }

    r[j] = '\0';

    int left = 0;
    int right = j - 1;
    
    while (left < right)
    {
        char temp = r[left];
        r[left] = r[right];
        r[right] = temp;
        left++;
        right--;
    }

    return r;
}


int main(void)
{
    char *n = "1234567892434574367823574575678477685785645685876876774586734734563456453743756756784458";
    char *m = "9034790663470697234682914569346259634958693246597324659762347956349265983465962349569346";
    char r[100];
    char r2[10];
    char r3[11];
    char *res;


    res = infinite_add(n, m, r, 100);
    if (res == 0)
    {
        printf("Error\n");
    }
    else
    {
        printf("%s + %s = %s\n", n, m, res);
    }

    n = "1234567890";
    m = "1";
    res = infinite_add(n, m, r2, 10);
    if (res == 0)
    {
        printf("Error\n");
    }
    else
    {
        printf("%s + %s = %s\n", n, m, res);
    }

    n = "999999999";
    m = "1";
    res = infinite_add(n, m, r2, 10);
    if (res == 0)
    {
                printf("Error\n");
        }
        else
        {
                printf("%s + %s = %s\n", n, m, res);
        }
        res = infinite_add(n, m, r3, 11);
        if (res == 0)
        {
                printf("Error\n");
        }
        else
        {
                printf("%s + %s = %s\n", n, m, res);
        }
        return (0);
}