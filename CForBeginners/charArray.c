#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {

    printf("\n---------------------CHAR ARRAY---------------------\n");

    // string literal, stored as readonly data
    char* name1 = "Gladiator";
    printf("%s\n", name1); // output the whole string

    // character array initialized from a string literal, copied to and stored in the stack
    char name2[] = "Gladiator";
    name2[0] = 'g';
    printf("%s\n", name2); // output the whole string

    char* name3 = (char*)malloc(sizeof(char) * 10);
    name3 = "Gladiator";
    name3[0] = 'g';

    printf("%s\n", name3);

    free(name3);

    // pointer to char, holds 128 elements stored on the stack
    char name4[128];

    // copy string literal into name4, 12 bytes plus 1 for null terminator
    strcpy_s(name4, 10, "Gladiator");
    printf("%s occupies %d elements because the null terminator is up until the end of the string.\n", name4, strlen(name4));

    // access elements - arr[index] => *(arr + index)
    name4[0] = 'g';
    for (int i = 0; i < strlen(name4); i++)
        printf("%c ", name4[i]);
}