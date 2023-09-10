#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Arrays.h"


int main() {



    printf("\n---------------------CHAR POINTER ARRAY---------------------\n");

    // Initialize a character array to hold a string, i.e. an array of char pointers
    char* stringArray = { "FuckHumans!" };
    printf("Equivalent: %s  &  %s\n", *stringArray, stringArray[0]); // This prints the whole string as [0] contains the address pointing to the whole string. 


    printf("\n---------------------TEST---------------------\n");

    /*
        The memory associated with arr is freed automatically when arr goes out of scope. It is either a local variable, or allocated statically, but it is not dynamically allocated.
        A simple rule for you to follow is that you must only every call free() on a pointer that was returned by a call to malloc, calloc or realloc.
    */
    char* longerStringArray = malloc(3 * sizeof(char));

    char* string1 = "Humans", string2 = " are a", string3 = " virus!";

    longerStringArray[0] = string1;
    longerStringArray[1] = string2;
    longerStringArray[2] = string3;


    for (int i = 0; i < 3; i++)
        printf("%s", longerStringArray[i]);

    printf("\nIs Equivalent to: \n");

    for (int i = 0; i < 3; i++)
        printf("%s", *(longerStringArray + i));

    printf("\n---------------------TEST---------------------\n");

    // using the address of operator
    mergeArray(&nums1, a1, &nums2, a2);

    sortArrayAsc(nums1);
}