#ifndef HORNER_H
#define HORNER_H

#include <stdio.h>
#include <stddef.h>

#include "modulararithmetic.h"
/* polynomials are represented by a pair (deg, p)
 * 	deg of type int
 * 	p[] of type long long
 * p should be a list of length deg + 1, p[0] represents the constant
 * coefficient; p[deg] should be nonzero (this might become troublesome when
 * treating polynomials modulo an integer)
 */

long long horner_iter(long long p[], long long x, int deg, long long partial);
	// returns the value of the polynomial represented by p at x
	// using Horner's iterative method; deg indicates the degree of p, the
	// length of p is deg + 1
long long horner(long long p[], long long x, int deg);

long long horner_modular_iter(long long p[], long long x, int deg, long long partial, long long mod);

long long horner_modular(long long p[], long long x, int deg, long long mod);

void derived_polynomial(int deg, long long p[], int *deg_derived, long long p_derived[]);
	// in : deg, an integer representing the degree of p;
	// 	length(p) = deg + 1
	// in(out) : p, a list representing a polynomial
	// inout : deg_derived, a int representing the degree of p_derived
	// inout : p_derived, a list representing the derivative of the
	// 	polynomial represented by p
	// updates p_derived and deg_derive so that they represent the
	// derivative of p

#endif
