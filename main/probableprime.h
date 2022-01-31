#ifndef PSEUDOPRIME_H
#define PSEUDOPRIME_H

#include <stdio.h>
#include <stddef.h>

#include "euclid.h"
#include "modulararithmetic.h"

void even_odd_descomposition(long long x, long long eod[2]);
	// modifies eod; by the end of the execution, eod stores the power of
	// 2 dividing x in eod[0] and the odd number x / 2 ^ eod[0] in eod[1];
	// x = (2 ^ eod[0]) * eod[1]

_Bool probableprime(long long m, long long a);
	// returns True, if m is a probable prime to the base a;
	// returns False, if m is composite (does not pass the probable prime
	// test)
_Bool strongprobableprime(long long m, long long a);
	// returns True, if m is a strong probable prime to the base a
_Bool oldprobableprime(long long m, long long a);
	// returns True if m is a probable prime in te old sense: that is, if
	// a ^ m = a (mod m)
_Bool strongprobableprime_extended(long long m, long long a, long long *x);
	// identical to strongprobableprime, with the exception that the value
	// of x is updated to hold a residue class such that
	// x != 1, -1 (mod m), but x ^ 2 = 1 (mod m)
void locate_divisors(long long m, long long x, long long divs[2]);
	// assumes that m is an odd composite number which fails the
	// strong probable prime test to some base a; the numbers
	// d = euclid(x + 1, m) and e = euclid(x - 1, m) are proper divisors
	// of m; furthermore, m = d * e, since euclid(d, e) = 1 or 2 and cannot
	// be 2
void print_proper_divisors_iter(long long m, long long bases[], int n);
	// uses the strong probable prime test and locates divisors to find a
	// factorisation of m as a product of two proper divisors;
	// n = length(bases)
#endif
