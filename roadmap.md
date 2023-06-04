## NASA Rules
1. Null pointer de-reference
2. Simple control flow
    x goto
    x setjump
    x longjumo
    x recursion
- Limit all loops
```C
int list_search(list_t *e, int search)
{
    int i = 0; // the limit
    while(e && i++ < MAX_ITER) // check for end of array and array length i.e. a simple integer
    {
        if(e -> val == search)
            return e;
        e = e -> fd;				
    }

    return null;
}
```
3. Do not use HEAP as leaks and overflows cannot be detected by the analyzer
    x malloc
    x free
    memory leaks
    use-after-free
    heap overflows
    heap exhaustion
```C
// the below is not good if i understood correctly
int alloc_message(msg_t **t)
{
    msg_t temp = malloc(sizeof(msg_t));
    if(temp!=NULL)
        *t = temp
    else
        return -1;

    temp->data = malloc(MAX_DATA);
    return 0;
}

int free_msg(msg_t **t)
{
    if(t)
        free(t);
    return 
}

// the below is better if i understood correctly
// memory allocation is deterministic
typedef struct
{
    int in_use;
    char data[DATA_SIZE];			
}msg_t;

void msg_task(){
    msg_t msg_buf[NUM_MSG] = {0};
    msg_process(msg_buff);
    //....
    return;
}
```
4. Limit function size/lines of code and do not use nesting
5. Practice data hiding by restricting data access to class members. This maintains data integrity.
6. Check return values for NULL 
    explicitly cast all return values that are ignored, to a void type if 
    ```C
    packet_t *p = &someValue;
    (void)printf("Num of messages %d", p->num_msgs);
    ```
7. Limit the C preprocessor. The C preprocessor is a powerful obfuscation tool that can destroy code clarity
    and befuddle many text-based checkers.
8. Restrict pointer use. No more than one layer of dereferencing should be used. dereference operations may not be hidden in macro definitions or 		inside typedef declarations. 
9. Compile in pedantic: gcc -Wall -Werror -Wpedantic
    Use different static code analyzers and perform tests. 

# ROADMAP
## Basics		
+ how C compilers work
+ Macros and Preprocessors in C
+ Compiling a C program: — Behind the Scenes
+ Is it fine to write “void main()” or “main()” in C/C++?
+ Difference between “int main()” and “int main(void)” in C/C++?
+ how linker works
+ header files
+ preporcessor
    + directives; #include
+ C/ C++ Tokens
+ macro substitution, file inclusion, compiler control directives
        + error handling during I/O operations
+ Program error signals


## File Handling
+ fseek() vs rewind() in C
+ EOF, getc() and feof() in C
+ fopen() for an existing file in write mode
+ Read/Write structure to a file
+ fgets() and gets() in C
+ Basics of File Handling
+ fsetpos() in C
+ rename function in C/C++
+ tmpfile() function in C
+ fgetc() and fputc() in C
+ fseek() in C/C++
+ ftell() in C
+ lseek() in C/C++
+ remove function in C/C++
+ Merge contents of two files into a third file
+ Print contents of file in C
+ file management and handling
    + fopen
    + fclose
    + fprintf
+ file and stream
    + Line Slicing in C
+ define, open and close a file
+ input output operations on files


## Variables
+ what happens in computer memory
+ what is an executable; args, parsing, command line arguments
+ variable naming convention
    + automatic variables
    + external variables
    + static variables
    + register variables
    + lifetime of variables
+ data types and their ranges
+ signed magnitude data; int (1 sign bit + 31 data bits) keyword in C
+ static vs global variables
+ How are variables scoped in C — Static or Dynamic?
+ Scope rules in C
+ How Linkers Resolve Multiple Defined Global Symbols?
+ Redeclaration of a global variable in C
+ Internal and External Linkage
+ Declare a variable as constant
+ Initialization of global and static variables		
+ size_t data type
+ typecast
+ operators
    + arithmetic
    + relational
    + logical
    + assignment
    + incremental and decremental
    + conditional
    + ***bitwise
    + special
+ precedence and associativity of operators
+ short circuit evaluation
+ loop control; break, continue
+ array definition, declaration, initialization and accessing  elements
+ designated initialization of arrays
+ multi dimensional arrays
+ searching and sorting in arrays
    + bubble sort
    + selection sort
    + insertion sort
    + linear search
    + binary search
+ string manipulation
    + strcpy
    + strcat
+ char array and string
+ declare and initialize string variables
+ string literals
+ useful string handling libraries; ctype.h, string.h, stdlib.h
+ float and double
+ character arithmetic
+ typecasting

## Functions
+ Functions that are executed before and after main() in C
+ return statement vs exit() in main()
+ How to Count Variable Numbers of Arguments in C?,
+ What is the evaluation order of function parameters in C?
+ Does C support function overloading?
+ How can we return multiple values from a function?
+ What is the purpose of a function prototype?
+ Static functions in C
+ exit(), _Exit(), abort() and assert()
+ Implicit return type int in C
+ What happens when a function is called before its declaration in C?
+ _Noreturn function specifier in C
+ __func__ identifier in C
+ Callback function in C
+ Nested functions in C
+ Parameter Passing Techniques
+ pow() function in C
+ time() function in C
+ functions
    + declaration and definition
    + parameters and arguments
    + function pointers and delegates
    + call by value and reference
    + static and dynamic scoping
    + passing arrays to functions
    + passing strings to functions
+ heap and stack
+ recursion
    + direct
    + indirect
    + tail
    + not-tail

## Pointers
+ Why does C treat array parameters as pointers?
+ Dangling, Void, Null, and Wild Pointers
+ How to declare a pointer to a function?
+ Pointer vs Array in C
+ void pointer in C
+ NULL pointer in C!
+ Function Pointer in C
+ near, far and huge pointers
+ Generic Linked List in C
+ restrict keyword in C
+ const char *p, char * const p, and const char * const p
+ Pointer to an Array
+ pointer definition, declaration, initialization and accessing
+ arrays and pointers
+ pointers and char strings
+ arrays of pointers
+ pointer as function arguments
+ pointer to function
+ pointer to 2D array
+ dynamic memory allocation
    + malloc
    + calloc
    + realloc
    + free
+ linked lists
+ list vs array

## Enum, Struct, and Union
+ strucs and unions
+ declaring and accessing struct members
+ array of structs
+ structs and functions
+ enums
+ Struct Hack
+ Structure Member Alignment, Padding, and Data Packing
+ Operations on struct variables in C
+ Bit Fields in C
+ Structure Sorting (By Multiple Rules) in C++
+ Flexible array of members in the structure
+ Difference between Structure and Union
+ Difference between C structures and C++ structures
+ Anonymous Union and Structure in C
+ Compound Literals in C

## Arrays & Strings
+ Introduction to Arrays in C Language
+ Strings in C Language
+ Properties of the array in C Language
+ Do not use sizeof for array parameters
+ Initialization of variables sized arrays in C
+ Are array members deeply copied?
+ What is the difference between single-quoted and double-quoted declaration 		+ of char array?
+ Initialization of multidimensional arrays in C/C++
+ Write one-line functions for strcat() and strcmp()
+ What’s the difference between char s[] and char *s in C
+ gets() is risky to use!
+ C function to Swap strings,
+ Storage for Strings in C
+ Difference between array and pointer
+ How to dynamically allocate a 2D array in C?
+ How to pass a 2D array as a parameter in C?
+ How to write long strings in Multi-lines C/C++?
+ What are the data types for which it is not possible to create an array?
+ Variable Length Arrays in C and C++
+ Shorthand array notation
+ Accessing an array out of bounds
+ strcpy() in C/C++
+ strcmp() in C/C++
+ strdup() and strdndup() in C/C++
+ Pass an array by value
+ Reverse a string in C/C++
+ strpbrk() in C
+ strcoll() in C/C++
+ ispunct() in C
+ strspn() in C
+ isalpha() and isdigit() in C/C++

## Storage Classes
+ Understanding the “extern” keyword in C
+ What are the default values of static variables in C?
+ Understanding the “volatile” qualifier in C
+ Understanding the “register” keyword in C

## Input/Output:
+ Returned values of printf() and scanf()
+ What is return type of getchar(), fgetc() and getc()?
+ Scansets in C
+ puts() vs printf() for printing a string
+ What is use of %n in printf()?
+ How to print % using printf()?
+ Quiz on Input-Output in C
+ Difference between printf, sprintf and fprintf?
+ Difference between getc(), getchar(), getch() and getche()
+ Difference between %d and %i format specifier
+ Use of fflush(stdin) in C
+ Clearing input buffer in C/C++
+ scanf() and fscanf() in C
+ getchar_unlocked() in C
+ Problem with scanf()
+ Differentiate printable and control character
+ rand() and srand() in C/C++

## Operators
+ Relational and Logical Operators in C
+ Bitwise Operators in C
+ Operator Precedence and Associativity in C
+ The evaluation order of operands
+ Comma in C and C++
+ sizeof operator in C
+ Operands for sizeof operator
+ Result of comma operator as l-value in C and C++
+ Order of operands for logical operators
+ Increment (Decrement) operators require L-value Expression
+ Precedence of postfix ++ and prefix ++ in C/C++
+ Modulus on Negative Numbers
+ C/C++ Ternary Operator — Some Interesting Observations
+ Pre-increment (or pre-decrement) in C++
+ Difference between ++*p, *p++ and *++p
+ Results of comparison operations in C and C++
+ To find the sum of two numbers without using any operator
+ Sequence Points in C
+ Execution of printf with ++ operators
+ Anything written in sizeof() is never executed
+ Difference between strlen() and sizeof()
+ Stringizing and Token-pasting operator

## Preprocessor
+ Write a C macro PRINT(x) which prints x
+ Variable-length arguments for Macros
+ Multiline macros in C
+ CRASH() macro — interpretation
+ The offsetof() macro,
+ Branch prediction macros in GCC
+ What is the difference between #define and const in C?
+ A-C Programming Language Puzzle
+ What’s the difference between header files “stdio.h” and “stdlib.h” ?
+ How to print a variable name in C?
+ Preprocessor Directives: Behind the scenes-1
+ Preprocessor Directives: Behind the scenes-2
+ isgraph() library function
+ write your own header file in C
+ difftime() library function
+ tmpnam() library function
+ _Generic keyword in C
+ math.h library functions
+ typedef versus #define in C
+ strftime() library function
+ exec family of functions

### Solve pyramids of starts
    https://www.youtube.com/watch?v=KdM6OrvcjPI
### Solve 1d arrays, matrix adding and multiplying
    https://www.youtube.com/watch?v=rowWM-MijXU
### Solve recursion 
### Library management project
    https://github.com/FahimMuntashir/Library-project-in-C
### Calendar project
    https://github.com/FahimMuntashir/Calendar-project-in-C-
### Computer Science
    https://github.com/ossu/computer-science/blob/master/README.md###cs-tools
### Simple database in C
    https://cstack.github.io/db_tutorial/
### Linux containers
    https://blog.lizzie.io/linux-containers-in-500-loc.html
### hash table
    https://github.com/jamesroutley/write-a-hash-table
### memory
    https://danluu.com/malloc-tutorial/
### shell
    https://brennan.io/2015/01/16/write-a-shell-in-c/

## Puzzles
+ C Program to print numbers from 1 to N without using semicolon?
+ How to find the sum of two numbers without using any operator
+ How will you show the memory representation of C variables?
+ Condition To Print “HelloWord”
+ Change/add only one character and print ‘*’ exactly 20 times
+ How can we sum the digits of a given number in a single statement?
+ What is the best way in C to convert a number to a string?
+ Calculate Logn in one line
+ Print “Even” or “Odd” without using a Conditional statement
+ How will you print numbers from 1 to 100 without using a loop?
+ How can we sum the digits of a given number in a single statement?
+ How will you print “Geeks for Geeks” without using a semicolon?
+ Write a one line C function to round floating point numbers
+ How will implement Your Own sizeof
+ How to count set bits in a floating-point number in C?
+ How to change the output of printf() in main() ?
+ How to find the length of a string without string.h and loop in C?
+ Implement your own itoa()
+ Write a C program that does not terminate when Ctrl+C is pressed
+ How to measure the time taken by a function in C?
+ Print a long int in C using putchar() only
+ Convert a floating-point number to string in C
+ How to write a running C code without main()?
+ Write your own memcpy()
+ C program to print characters without using format specifiers
+ C program to print a string without any quote (singe or double) in the + program
+ Execute both if and else statements simultaneously
+ Print “Hello World” without using any header file

### Misc
+ Quine — A self-reproducing program
+ Complicated declarations in C
+ Use of bool in C
+ Sequence Points in C
+ Optimization Techniques (swapping),
+ ASCII NUL, ASCII 0 (’0?) and Numeric literal 0
+ Little- and Big-Endian Mystery,
+ Comparator function of qsort() in C
+ Program to validate an IP address
+ Multithreading in C
+ Assertions in C/C++
+ fork() in C
+ Interesting Facts in C Programming
+ Precision of floating-point numbers in C++ (floor(), ceil(), trunc(), + round() and setprecision())
+ setjump() and longjump() in C
+ nextafter() and nexttoward() in C/C++
+ pthread_cancel() in C
+ pthread_equal() in C
+ pthread_self() in C
+ Local Labels in C
+ lvalue and rvalue in C
+ Get and set the stack size of the thread attribute
+ Difference between fork() and exec()
+ Errors in C/C++
+ Why is C considered faster than other languages?
+ Incompatibilities between C and C++
+ Convert C/C++ code to assembly language
+ Error Handling in C
+ Executing main() in C/C++ : Behind the scene
+ Hygienic Macros in C
+ Command-line arguments in C/C++
+ scanf(), fscanf(), sscanf(), scanf_s(), fscanf_s(), sscanf_s()
+ Some Interesting Facts in C Programming
+ Database Connectivity using C/C++
+ Function Interposition in C
+ Macros vs Functions
+ Write your own memcpy() and memmove()