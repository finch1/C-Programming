#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "Arrays.h"


int main() {

    printf("\n---------------------DUBLICATES IN AN INTEGER---------------------\n");
    // Initializing 1D arrays of integers
    int nums1[] = { 5,2,3,0,0,0 };
    int nums2[] = { 2,5,3 };

    // Find size of 1D arrays
    int a1 = sizeof(nums1) / sizeof(nums1[0]);
    int a2 = sizeof(nums2) / sizeof(nums2[0]);

    // Count repeating numbers
    unsigned int number;
    printf("Input a long integer number: \n");
    scanf_s("%u", &number);

    int rem = 0;
    int seen[10] = { 0 };

    while (number > 0)
    {
        rem = number % 10;
        if (seen[rem] > 0)
            seen[rem] += 1;
        else
            seen[rem] = 1;
        number /= 10;
    }

    for (int i = 0; i < 10; i++)
        printf("The number %d was seen %d times. \n", i, seen[i]);

    printf("\n---------------------INTEGER POINTER ARRAY---------------------\n");

    // Declare an array of integer pointers, i.e. pointers pointing to integers addresses
    int* arrOfPtr[3];
    int x = 1, y = 2, z = 3;

    arrOfPtr[0] = &x; // assign the address of the integer x
    printf("%d\n", *arrOfPtr[0]); // print the value of x by dereferencing

    arrOfPtr[1] = &y;
    printf("%d\n", *arrOfPtr[1]);

    arrOfPtr[2] = &z;
    printf("%d\n", *arrOfPtr[2]);

    printf("\n---------------------1D DYNAMIC INTEGER POINTER ARRAY---------------------\n");

    int stat_arr[] = { 1,2,3,4 }; // this goes on the STACK
    // return address to block of memory in heap of 4 integers. dyna_arr is a memory address holder
    int* dyna_arr = malloc(sizeof(int) * 4);

    if (dyna_arr == NULL)
    {
        assert(dyna_arr == NULL);
        printf("Memory not allocated!\n");
        exit(-1);
    }


    dyna_arr[0] = 1; dyna_arr[1] = 2; dyna_arr[2] = 3; dyna_arr[3] = 4;

    int arr_len = (sizeof(int) / stat_arr[0]);

    for (int i = 0; i < arr_len; i++)
        printf("Static: %d & Dynamic %d\n", stat_arr[i], dyna_arr[i]);

    free(dyna_arr);

    printf("\n---------------------2D DYNAMIC INTEGER POINTER ARRAY---------------------\n");

    int twoD_stat_arr[3][3] = { {1,2,3},{4,5,6},{7,8,9} }; // stored in STACK

    // pointers to memory blocks in the heap
        // MALLOC RETURNS A POINTER TO THE MEMORY SPACE
    // 
    // We need to allocate first memory vertically IN THE HEAP, to know how many rows we need.
    // First, we tell the program how many rows we want our matrix to have. Each row is an array of ints (aka int*).
    int** twoD_dyna_arr = malloc(sizeof(int*) * 3);

    // Then, we can allocate memory horizontally for each of these rows.To do that, we can simply use our case 1. So for the first week we would do:
    int* arr0 = malloc(sizeof(int) * 3);
    arr0 = (int[3]){ 1,2,3 };

    int* arr1 = malloc(sizeof(int) * 3);
    arr1 = (int[3]){ 4, 5, 6 };

    int* arr2 = malloc(sizeof(int) * 3);
    arr2 = (int[3]){ 7,8,9 };

    twoD_dyna_arr[0] = arr0; // arr0 = address of element 0. int* arr == arr[] == pointer to first element
    twoD_dyna_arr[1] = arr1; // we store the pointer in a mem block for pointers
    twoD_dyna_arr[2] = arr2;


    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
        {
            twoD_stat_arr[i][j] *= 10;
            twoD_dyna_arr[i][j] *= 10;
            printf("Static: %d & Dynamic: %d\n", twoD_stat_arr[i][j], twoD_dyna_arr[i][j]);
        }

    // FREE MEMORY FROM HEAP
    /*
        for (int f = 2; f > 0; f--)
            free(twoD_dyna_arr[f]);
    */

    free(twoD_dyna_arr);

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
    strcpy(name4, "Gladiator");
    printf("%s occupies %d elements because the null terminator is up until the end of the string.\n", name4, strlen(name4));

    // access elements - arr[index] => *(arr + index)
    name4[0] = 'g';
    for (int i = 0; i < strlen(name4); i++)
        printf("%c ", name4[i]);


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