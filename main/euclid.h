#ifndef EUCLID_H
#define EUCLID_H

#include <stdio.h>
#include "base.h"

long long findremainder(long long x, long long m);
	// returns remainder of x (mod m)
long long euclid(long long a, long long b);
	// returns GCD of a and b
long long leastcommonmultiple(long long a, long long b);
	// returns lcm of a and b
_Bool isunit(long long a, long long m);
	// returns True, if and only if, a is invertible modulo m
long long euclid_extended_iter(long long *v0[], long long v1[]);

long long euclid_extended(long long a, long long b, long long *px, \
		long long *py);

long long findinverse(long long a, long long m);
	// returns inverse of a mod m; assumes it exists

#endif
