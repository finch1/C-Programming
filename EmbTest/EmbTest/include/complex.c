#include "complex.h"
#include <math.h>
/*
* Static here implies that access is restriceted to the file where they are declared.
* This acts as 'private' in OOP. 
* Encapsulation: stuff that should not be poked at by any thing outside the unit, is hidden away so it cant be. 
*/
static double my_abs(struct Complex *this){
	return sqrt(this->re*this->re + this->im*this->im);
}
//static here is making possible reusing the word 'new' in another file but not in this one. 
static struct Complex new(double real, double imag){
		return(struct Complex) { .re = real, .im = imag, .my_abs=&my_abs };
}

// The header is needed for the struct definition;
// It doesn't hurt to include the externs,
// and ensures that declarations & definitions match!

//this is a factory pattern, complex class instantiates complex. 
const struct ComplexClass Complex = { .new = &new }; //where is the address comming from here?

/*
defining a type: making a blue print. define a circuit with a diagram doesnt mean one has the actual physical circuit
typedef 
defining a variable: to the compiler, I want an instance of this type and i want to call it this.
int var; is defining an instance of type int called var. 
*/