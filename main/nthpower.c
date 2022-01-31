#include <stdio.h>
#include "nthpower.h"

_Bool is_nth_power_modulo_prime(n, a, p)
	long long n, a, p;
{
	return ( modular_power(a, (p - 1) / euclid(n, p - 1), p) == 1 );
}

long long find_nth_power_nonresidue(n, p)
	long long n, p;
{
	long long a = 2;
	while ( a < p ) {
		if ( ! is_nth_power_modulo_prime(n, a, p) ){
			return a;
		}
		a++;
	}
}

long long find_order_exact_power_of_two(N, p)
	long long N, p;
{
	long long k = 0;
	while ( (N = findremainder(N, p)) != 1 ) {
		// printf("%lld != 1 (mod %lld)\n", N, p);
		N = modular_square_residues(N, p);
		k++;
	}
	return k;
}

long long quadratic_ressol(a, p)
	long long a, p;
{
	long long eod[2], r, N;
	even_odd_descomposition(p - 1, eod);
	r = modular_power(a, (eod[1] + 1) / 2, p);
	N = modular_power(a, eod[1], p);
	// printf("%lld ^ %lld = %lld (mod %lld)\n", a, eod[1], N, p);
	// N ^ (2 ^ eod[0]) = a ^ (p - 1) = 1, so its order is a power of 2
	// N ^ (2 ^ (eod[0] - 1)) = a ^ ((p - 1) / 2) = 1, since a is assumed
	// to be a quadratic residue mod p; thus, the order of N is
	// 2 ^ k, with 0 <= k < eod[0]
	if ( findremainder(N, p) == 1 ) {
		// k == 0
		return r;
		// the other solution is -r
	}
	long long z, c, k, b;
	k = find_order_exact_power_of_two(N, p); // k > 0
	// printf("%lld has order 2 ^ %lld modulo %lld\n", N, k, p);
	z = find_nth_power_nonresidue(2, p);
	c = modular_power(z, eod[1], p);
	// since z is a quadratic nonresidue, c has order exactly
	// 2 ^ eod[0]
	while ( eod[0] > 0 ) {
		b = modular_power(c, power(2, eod[0] - k - 1), p);
		r = modular_multiply(b, r, p);
		c = modular_square_residues(b, p);
		N = modular_multiply(c, N, p);
		if ( findremainder(N, p) == 1 ) {
			return r;
		} else {
			eod[0] = k;
			k = find_order_exact_power_of_two(N, p);
			// printf("%lld has order 2 ^ %lld modulo %lld\n", N, k, p);
			// k < eod[0]
		}
	}
}
