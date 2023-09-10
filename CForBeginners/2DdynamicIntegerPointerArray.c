#include <stdio.h>
#include <stdlib.h>

int main() {
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

   free(twoD_dyna_arr);
}