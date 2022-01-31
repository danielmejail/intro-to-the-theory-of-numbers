#ifndef NTHPOWER_H
#define NTHPOWER_H

#include <stdio.h>

#include "base.h"
#include "euclid.h"
#include "modulararithmetic.h"
#include "probableprime.h"

_Bool is_nth_power_modulo_prime(long long n, long long a, long long p);
	// returns TRUE, iff x ^ n = a (mod p) has a solution; this is achieved
	// using Euler's criterion: a is an nth power, if and only if
	// a ^ ( ( p - 1 ) / euclid(n, p - 1) ) = 1 (mod p); if the congruence
	// holds, then there are euclid(n, p - 1) many solutions, if not, there
	// are no solutions and a is not an nth power

long long find_nth_power_nonresidue(long long n, long long p);
	// returns z such that x ^ n = z (mod p) has no solution
	// assumes p > 2 and (p, n) = 1

long long find_order_exact_power_of_two(long long N, long long p);
	// assumes N (mod p) has order a power of 2; returns the exponent of
	// this power, the least k >= 0 such that N ^ (2 ^ k) = 1 (mod p)

long long quadratic_ressol(long long a, long long p);
	// returns a solution, if there is any, to x ^ 2 = a (mod p) using the
	// RESidue SOLver algorithm

#endif
