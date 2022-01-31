#include <stdio.h>
#include <stddef.h>

#include "probableprime.h"

void even_odd_descomposition(x, eod)
	long long x, eod[2];
{
	long long j = 0;
	while ( x % 2 == 0 ) {
		x /= 2;
		j++;
	}
	eod[0] = j;
	eod[1] = x;
}

_Bool probableprime(m, a)
	long long m, a;
{
	return ( modular_power(a, m-1, m) == 1 );
}

_Bool strongprobableprime(m, a)
	long long m, a;
{
	long long eod[2], j, d, b;
	even_odd_descomposition(m-1, eod);
	j = eod[0];
	d = eod[1];
	b = modular_power(a, d, m);
	if ( b == 1 ) {
		return TRUE;
	}
	while ( j > 0 ) {
		if ( b == 1 ) {
			return FALSE;
		}
		if ( b == m-1 ) {
			return TRUE;
		}
		b = modular_square_residues(b, m);
		j--;
	}
	return FALSE;
}

_Bool oldprobableprime(m, a)
	long long m, a;
{
	return ( modular_power(a, m, m) == a );
}

_Bool strongprobableprime_extended(m, a, x)
	long long m, a, *x;
{
	long long eod[2], j, d, b;
	even_odd_descomposition(m-1, eod);
	j = eod[0];
	d = eod[1];
	b = modular_power(a, d, m);
	if ( b == 1 ) {
		return TRUE;
	}
	*x = b;
	while ( j > 0 ) {
		if ( b == 1 ) {
			return FALSE;
		}
		if ( b == m-1 ) {
			return TRUE;
		}
		*x = b;
		b = modular_square_residues(b, m);
		j--;
	}
	return FALSE;
}

void locate_divisors(m, x, divs)
	long long m, x, divs[2];
{
	divs[0] = euclid(x + 1, m);
	divs[1] = euclid(x - 1, m);
}

void print_proper_divisors_iter(m, bases, n)
	long long m, bases[];
	int n; // length of bases
{
	long long x;
	while ( n > 0 ) {
		long long a = *bases;
		if ( strongprobableprime_extended(m, a, &x) ) {
			printf("%lld is a strong probable prime to the base %lld\n", m, a);
		} else {
			printf("%lld fails the strong probable prime test to the base %lld\n", m, a);
			printf("%lld does not divide %lld + 1 nor %lld - 1\n", m, x, x);
			if ( modular_square_residues(x, m) == 1 ) {
				printf("%lld divides %lld ^ 2 - 1\n", m, x);
				long long divs[2];
				locate_divisors(m, x, divs);
				printf("%lld = %lld * %lld\n", m, divs[0], divs[1]);
				break;
			} else {
				printf("%lld does not divide %lld ^ 2 - 1\n", m, x);
			}
		}
		bases++;
		n--;
	}
}
