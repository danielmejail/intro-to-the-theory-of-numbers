#include <stdio.h>
#include <stddef.h>

#include "modulararithmetic.h"

long long modular_add_residues(a, b, mod)
	long long a, b, mod;
{
	long long res = a + b;
	if ( res >= mod ) {
		res -= mod;
	}
	return res;
}

long long modular_add(a, b, mod)
	long long a, b, mod;
{
	return modular_add_residues(findremainder(a, mod), \
			findremainder(b, mod), mod);
}

long long modular_multiply_residues(a, b, mod, X)
	long long a, b, mod, X;
{
	long long k, c, g, r, s;
	k = b;
	c = 0;
	g = X / mod; // >= 2
	while ( a > 0 ) {
		r = findremainder(a, g);
		s = findremainder(k * r, mod);
		c = modular_add_residues(c, s, mod);
		k = findremainder(k * g, mod);
		a = (a - r) / g;
	}
	return c;
}

long long modular_multiply(a, b, mod)
	long long a, b, mod;
{
	return modular_multiply_residues(findremainder(a, mod), \
			findremainder(b, mod), mod, UPPERBOUNDFORCOMPUTATIONS);
}

long long modular_square_residues(a, mod)
	long long a, mod;
{
	return modular_multiply(a, a, mod);
}

long long modular_power_residues_iter(a, pow, mod, partial)
	long long a, mod, partial;
	long long pow;
{
	// en cada iteraci'on del ciclo, res * a ^ pow es igual al resultado
	while ( pow > 0 ) {
		if ( euclid(pow, 2) == 1 ) {
			partial = modular_multiply(partial, a, mod);
			pow -= 1;
		} else {
			a = modular_square_residues(a, mod);
			pow /= 2;
		}
	}
	return partial;
}

long long modular_power(a, pow, mod)
	long long a, mod;
	long long pow;
{
	return modular_power_residues_iter(findremainder(a, mod), pow, mod, 1);
}
