// source: http://www.pvv.ntnu.no/~hakonhal/main.cgi/c/classes/#instance_methods
#include <stdio.h>
#include "../include/complex.h"

int main() {
	struct Complex c = Complex.new(3.0, -4.0);
	printf_s("%g\n", c.my_abs(&c));
	

	struct Bing b = Bing.new("Whatever");

	char wait;
	wait = getc(stdin);
}