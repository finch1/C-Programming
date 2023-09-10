#include <stdio.h>

int main() {

    printf("\n---------------------DUPLICATES INTEGER IN AN ARRAY---------------------\n");

    // Count repeating numbers
    unsigned int number;
    printf("Input a list of numbers: \n");
    scanf_s("%u", &number);

    int rem = 0;
    int seen[10] = { 0 };

    while (number > 0)
    {
        rem = number % 10;
        seen[rem] += 1;
        number /= 10;
    }

    for (int i = 0; i < 10; i++)
        printf("The number %d was seen %d times. \n", i, seen[i]);
}