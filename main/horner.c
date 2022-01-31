#include <stdio.h>
#include <stddef.h>

#include "horner.h"

long long horner_iter(p, x, deg, partial)
	long long p[], x, partial;
	int deg;
	// deg indicates the degree of the polynomial represented by p,
	// p[0] is the constant coefficient and the length of p is deg + 1
{
	while ( deg >= 0 ) {
		partial = partial * x + p[deg];
		deg--;
	}
	return partial;
}

long long horner(p, x, deg)
	long long p[], x;
	int deg;
{
	return horner_iter(p, x, deg, 0);
}

long long horner_modular_iter(p, x, deg, partial, mod)
	long long p[], x, partial, mod;
	int deg;
{
	while ( deg >= 0 ) {
		partial = modular_add(modular_multiply(partial, x, mod), \
				p[deg], mod);
		deg--;
	}
	return partial;
}

long long horner_modular(p, x, deg, mod)
	long long p[], x, mod;
	int deg;
{
	return horner_modular_iter(p, x, deg, 0, mod);
}

void derived_polynomial(deg, p, deg_derived, p_derived)
	long long p[], p_derived[];
	int deg, *deg_derived;
{
	if ( deg < 0 ) {
		*deg_derived = -1;
	} else {
		*deg_derived = deg - 1;
		while ( deg > 0 ) {
			p_derived[deg - 1] = deg * p[deg];
			deg--;
		}
	}
}
