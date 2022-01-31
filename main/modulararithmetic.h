#ifndef MODULARARITHMETIC_H
#define MODULARARITHMETIC_H

#define UPPERBOUNDFORCOMPUTATIONS 4294967296

#include <stdio.h>
#include <stddef.h>

#include "euclid.h"

long long modular_add_residues(long long a, long long b, long long mod);
	// adds a and b modulo mod; assumes 0 <= a, b < mod and returns the
	// residue class of a+b satisfying the same restriction

long long modular_add(long long a, long long b, long long mod);
	// adds a and b modulo mod; does not assume 0 <= a, b < mod;
	// finds the residue classes of a and b satisfying 0 <= a, b < mod
	// and calls another function to perform addition under this assumption;
	// the result satisfies 0 <= modular_add(a, b, mod) < mod
long long modular_multiply_residues(long long a, long long b, long long mod, long long X);
	// assumes 0 <= a, b < mod, mod <= X / 2 and X > 0
	// returns residue class of a * b modulo mod in the interval [[0, m-1]]
long long modular_multiply(long long a, long long b, long long mod);

long long modular_square_residues(long long a, long long mod);
	// square 0 <= a < mod modulo mod
long long modular_power_residues_iter(long long a, long long pow, long long mod, long long partial);
	// 0 <= a, partial < mod; returns resude class of a ^ pow modulo mod in the
	// interval [[0, m-1]]
long long modular_power(long long a, long long pow, long long mod);

#endif
