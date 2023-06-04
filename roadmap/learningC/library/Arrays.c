#include <stdio.h>

/*

    The one place where pointers and arrays become almost exactly synonomous is when they are used as parameters to functions.This is because arrays as arguments pass only the address of the array to the function.
    In other words, arrays as passed as pointers!

    In C, most values are passed using call - by - value, which means that the function gets a copy of the value.If the function modifies the parameter, the original variable used as a parameter does not get modified.
    However, arrays are passed call - by - reference, which means that a reference(i.e., pointer) to the array is passed rather than the array itself.

    Since arrays are passed by reference, the function can equally be declared in the two following ways :

    int func(int A[]);
    int func(int* A);

    Both of these declarations say essentially the same thing.The first says that an array is going to be passed in by reference, and the reference to an array is simply a pointer to the first element.
    The second says we are going to get a pointer to an integer, and we are left to guess that the pointer will refer to an array of ints. 
    I THINK THAT'S WHY WE NEED TO SEND THE SIZE OF THE ARRAY, CAUSE WE ONLY HAVE THE POINTER REFERENCE TO WRK WITH.
*/

// resize int array
void reset(int* array, int size) {
    memset(array, 0, size * sizeof(*array));
}

// replaces the last part of the first array with the second array
// using the address of operator: mergeArray(&arr1, &arr);
void mergeArray(int *arr1, size_t a1, int* arr2, size_t a2)
{

    // arr1 has to be the full combined length of both arrays.
    // i.e. arr2 must fit in arr1

    if (a1 != 0 && a2 != 0)
    {
        int i = a1 + a2 - 1;

        for (; i >= a1; i--)
        {
            arr1[i] = arr2[i - a1];
        }
    }

}

// sort array in asc order
// using the address of operator: sortArrayAsc(&arr1);
void sortArrayAsc(int *arr, size_t a1)
{
    int i, j, temp;

    // compare one element with the rest of the array, then advance one element
    if (a1 != 0)
    {
        for (i = 0; i < a1; i++)
        {
            for (j = i + 1; j < a1; j++)
            {
                if (arr[i] > arr[j])
                {
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }
    
}


// sort array in asc order
// using the address of operator: xorSwapAsc(&arr1);
void xorSwapAsc(int *arr, size_t a1)
{
    int i, j, temp;

    // compare one element with the rest of the array, then advance one element

    if (a1 != 0)
    {
        for (i = 0; i < a1; i++)
        {
            for (int j = i + 1; j < a1; j++)
            {
                if (arr[i] > arr[j])
                {
                    arr[i] = arr[i] ^ arr[j];
                    arr[j] = arr[i] ^ arr[j];
                    arr[i] = arr[i] ^ arr[j];
                }
            }
        }
    }
}

