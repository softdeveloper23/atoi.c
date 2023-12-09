#include "cs50.h"
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int convert_helper(string input, int index);
int convert(string input);

int main(void)
{
    string input = get_string("Enter a positive integer: ");

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (!isdigit(input[i]))
        {
            printf("Invalid Input!\n");
            return 1;
        }
    }

    // Convert string to int
    printf("%i\n", convert(input));
}

int convert_helper(string input, int index)
{
    if (index < 0)
    {
        return 0;
    }

    int digit = input[index] - '0';
    return digit * pow(10, strlen(input) - 1 - index) + convert_helper(input, index - 1);
}

int convert(string input)
{
    return convert_helper(input, strlen(input) - 1);
}