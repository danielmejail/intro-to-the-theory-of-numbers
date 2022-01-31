#include <stdio.h>
#include <stddef.h>

#include "euclid.h"
#include "solvelinear.h"

int main(void) {
	/* SOLVELINEAR : AN ISSUE WITH THE FINDREMINDER FUNCTION ?
	long long a, x, b, m, r;
	a = 2;
	b = 1;
	m = 3;
	x = solvelinear(a,b,m);
	r = -1;
	printf("%lld * %lld = %lld (mod %lld)\n", a, x, b, m);
	printf("%lld = %lld (mod %lld)\n", r, findremainder(-1,m), m);
	*/
	/* SOLVELINEAR
	long long a, b, m;
	a = 15;
	b = 0;
	m = 35;
	if ( linearissolvable(a, b, m) ) {
		long long x;
		x = solvelinear(a, b, m);
		printf("%lld * %lld = %lld (mod %lld)\n", \
				a, x, b, m);
	}
	else {
		printf("%lld * x = %lld (mod %lld) has no solution\n", \
				a, b, m);
	}
	*/
	/* CHINESE REMAINDER
	int n = 3;
	long long residues[n], moduli[n];
	residues[0] = 1;
	residues[1] = 0;
	residues[2] = 5;
	moduli[0] = 4;
	moduli[1] = 3;
	moduli[2] = 7;
	if ( pairwisecoprime(moduli, n) ) {
		long long x;
		x = chineseremainder(residues, moduli, n);
		for ( int i = 0; i < n; i++ ) {
			printf("%lld = %lld (mod %lld)\n", x, residues[i], \
					moduli[i]);
		}
	} else {
		printf("moduli are not coprime in:\n");
		for ( int i = 0; i < n; i++ ) {
			printf("\tx = %lld (mod %lld)\n", residues[i], \
					moduli[i]);
		}
	}
	*/
	/* SOLVELINEAR_EXTENDED
	 */
	int n;
	n = 2;
	long long a[n], b[n], m[n], x;
	/*
	a[0] = 1;
	a[1] = 1;
	a[2] = 1;
	b[0] = 3;
	b[1] = 8;
	b[2] = 5;
	m[0] = 10;
	m[1] = 15;
	m[2] = 84;
	*/
	// n = 2;
	a[0] = 1;
	a[1] = 1;
	b[0] = 29;
	b[1] = 19;
	m[0] = 52;
	m[1] = 72;
	long long a_copy[n], b_copy[n], m_copy[n];
	for ( int i = 0; i < n; i++ ) {
		a_copy[i] = a[i];
		b_copy[i] = b[i];
		m_copy[i] = m[i];
	}
	if ( (x = solvelinear_extended(a, b, m, n)) < 0 ) {
		printf("the following system is not compatible:\n");
		for ( int i = 0; i < n; i++ ) {
			printf("\t%lld * x = %lld (mod %lld)\n", a_copy[i], \
					b_copy[i], m_copy[i]);
		}
	} else {
		for ( int i = 0; i < n; i++ ) {
			printf("%lld * %lld = %lld (mod %lld)\n", a_copy[i], \
					x, b_copy[i], m_copy[i]);
		}
	}
	return 0;
}

