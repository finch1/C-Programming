#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main() {

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
}