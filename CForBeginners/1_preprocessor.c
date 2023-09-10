// preprocessor directive: pre-compiler replaces text(starting with #) with the actual content
// Source code -> Preprocessor -> Expanded Source code -> Compiler -> Machine code

// .h = header files which contain declarations (prototypes) of functions
// linker converts the declaration of functions into the actual functions
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello\n");

    int var; // declaration: announcing the properties of the variable to the compiler, i.e. size and name

    int a[] = {1};
    int b[] = {2};

    a[0] = a[0] + b[0];

    printf("%d",a[0]);
}