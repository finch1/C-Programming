/*
* if this macro has not already been defined, define it and include all code 
* betwwen #ifndef and #endif
*/

#ifndef COMPLEX_H
#define COMPLEX_H

/* C Classes*/

/*
* A class consists of an instance type and a class object:
* An instance type is a struct containing variable memebers called instance variables
* and function members called instance methods. A variable of the instance type is
* called an instance ( object of type class ).

* A class object is a global const struct variable containing class variables and 
* class methods. Thses members belong to the whole class without any references to any
* instances.
*/

/*
* A class named "complex" should name the instance type struct complex and the class object complex, 
* complex, and put the interface definitions in complex.h and the implementaion in complex.c
*/

/* Constructors */

/*
* Instances must be initialized by constructors when declared and the constructors must
* be class methods. The constructor should preferably return an instance type, but
* may also return a pointer to an instance type

* The Complex class gets two instance variables re and im, and a contructor named new:
*/


// all your files need to be able to "see" the structure type definition;
// only one file must actually define the variables(as it is the definition which allocates storage)
// Define the structure so that all files can "see" it struct my_struct

// structure definition
struct Complex{ // this is a type - struct Complex - one thing
	double re, im;
	double(*my_abs)(struct Complex *this);
};

// structure definition
extern const struct ComplexClass {
	struct Complex (*new)(double real, double imag); //function pointer
}Complex; // this is a variable name. 

struct ComplexType2 {
	struct Complex(*new)(double real, double img);
};

extern struct ComplexType2 Complex2;

/*
	create another struct, with a function pointer that returns the original structure

	letting the compiler know that there is a variable of type struct ComplexType2 called Complex2 declared. 

	without extrn, here it exists, in timer.c it becomes. 
*/

#endif // !COMPLEX_H
