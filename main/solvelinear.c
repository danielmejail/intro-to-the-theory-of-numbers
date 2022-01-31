#include <stdio.h>
#include "euclid.h"
#include "solvelinear.h"

long long solvelinearreduced(long long a, long long b, long long m) {
	// assumes linearissolvable(a, b, m) and euclid(a,m)==1
	long long a_inv = findinverse(a, m); // inverse of a mod m
	long long x = a_inv * b;
	return findremainder(x, m);
}

long long solvelinear(long long a, long long b, long long m) {
	// assumes linearissolvable(a, b, m)
	// returns one solution to ax = b (mod m); 0 <= x < m
	long long g = euclid(a, m);
	if ( g > 1 ) {
		a = a / g;
		m = m / g;
		b = b / g;
	}
	return solvelinearreduced(a, b, m);
}

_Bool linearissolvable(long long a, long long b, long long m) {
	long long g = euclid(a,m);
	return ( findremainder(b,g) == 0 );
}

_Bool pairwisecoprime(long long moduli[], int n) {
	for ( int i = 0; i < n; i++) {
		for ( int j = i+1; j < n; j++ ) {
			if ( euclid(moduli[i], moduli[j]) > 1 ) {
				return FALSE;
			}
		}
	}
	return TRUE;
}

long long chineseremainder(long long residues[], long long moduli[], int n) {
	long long m = 1;
	long long sol = 0;
	for ( int i = 0; i < n; i++ ) {
		m *= moduli[i];
	}
	long long inverses[n];
	for ( int i = 0; i < n; i++ ) {
		inverses[i] = findinverse(m / moduli[i], moduli[i]);
	}
	for ( int i = 0; i < n; i++ ) {
		sol += (m / moduli[i]) * inverses[i] * residues[i];
	}
	return findremainder(sol, m);
}

long long solvelinear_extended_rec(a, b, m, prev_sol, prev_mod, n)
	long long a[], b[], m[], prev_sol, prev_mod;
	int n;
{
	if ( prev_sol < 0 ) {
		return -1;
	}
	if (n > 0) {
		long long u;
		// return prev_sol + prev_mod * u;
		// donde u es sol del nuevo sistema que se obtiene reemplazando
		// x por prev_sol + prev_mod * k
		for ( int i = 0; i < n; i++ ) {
			// update the system
			b[i] -= a[i] * prev_sol;
			a[i] *= prev_mod;
			long long g = euclid(a[i], m[i]);
			if ( findremainder(b[i], g) > 0 ) {
				return -1;
			}
			a[i] /= g;
			m[i] /= g;
			b[i] /= g;
			printf("%lld * u = %lld (mod %lld)\n", a[i], b[i], m[i]);
		}
		if ( linearissolvable(a[0], b[0], m[0]) ) {
			// solve the first equation
			u = solvelinear(a[0], b[0], m[0]);
			printf("%lld solves the first equation\n", u);
			// find a solution for the remaining equations
			// compatible with the above solution; update
			printf("---\n");
			u = solvelinear_extended_rec(a+1, b+1, m+1, u, \
					m[0], n-1);
			return prev_sol + prev_mod * u;
		} else {
			// the system is incompatible; return a negative value
			// signaling this; solvelinear should always return a
			// nonnegative solution
			return -1;
		}
	} else {
		return prev_sol;
	}
}

long long solvelinear_extended_iter(a, b, m, sol, lcm, n)
	long long a[], b[], m[], sol, lcm;
	int n;
{
	while ( n > 0 ) {
		// sol is a common solution to the first equations
		// find a solution compatible with sol which is also a solution
		// to the next equation in line; update
		// this new solution is chosen to be of the form sol + lcm * u,
		// for som integer u, where lcm is the least common multiple
		// of the first moduli
		long long u;
		// modify the next unsolved equation, in order to find u;
		// maybe this can be done without actually modifying the system
		b[0] -= a[0] * sol;
		a[0] *= lcm;
		if ( linearissolvable(a[0], b[0], m[0]) ) {
			u = solvelinear(a[0], b[0], m[0]);
		} else {
			return -1;
		}
		// update solution (and lcm)
		sol += lcm * u;
		lcm = leastcommonmultiple(lcm, m[0]);
		// the head of each list is updated to point one place forward
		a++;
		b++;
		m++;
		// reduce the amount of remaining equations
		n--;
	}
	return sol;
}

long long solvelinear_extended(a, b, m, n)
	long long a[], b[], m[];
	int n;
{
	return solvelinear_extended_iter(a, b, m, 0, 1, n);
	// return solvelinear_extended_rec(a, b, m, 0, 1, n);
}
