#include <stdio.h>


int main() {

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
}