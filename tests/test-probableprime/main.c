#include <stdio.h>
#include <stddef.h>

#include "euclid.h"
#include "solvelinear.h"
#include "modulararithmetic.h"
#include "horner.h"
#include "probableprime.h"

int main(void) {
	/*
	int n;
	n = 8;
	long long x[n], mod[n], res[n];
	int pow[n];
	// long long pow[n];
	x[0] = 999;
	mod[0] = 1763;
	pow[0] = 179;
	res[0] = 1219;
	x[1] = 2;
	mod[1] = 341;
	pow[1] = 85;
	res[1] = 32;
	x[2] = 2;
	mod[2] = 1763;
	pow[2] = 1762;
	res[2] = 742;
	x[3] = 2;
	mod[3] = 1387;
	pow[3] = 1386;
	res[3] = 1;
	x[4] = 2;
	mod[4] = 1387;
	pow[4] = 693;
	res[4] = 512;
	x[5] = 2;
	mod[5] = 91;
	pow[5] = 45;
	res[5] = 57;
	x[6] = 2;
	mod[6] = 11111;
	pow[6] = mod[6] - 1;
	res[6] = 10536;
	x[7] = 2;
	mod[7] = 1111111;
	pow[7] = mod[7] - 1;
	res[7] = 553891;
	// possible overflow in the following test cases;
	// also, modular_multiply assumes an upper bound on the arguments
	// x[8] = 2;
	// mod[8] = 11111111111;
	// pow[8] = mod[8] - 1;
	// res[8] = 1496324899;
	// x[9] = 2;
	// mod[9] = 1111111111111;
	// pow[9] = mod[9] - 1;
	// res[9] = 1015669396877;
	// x[10] = 11;
	// mod[10] = 3215031751;
	// pow[10] = (mod[10] - 1) / 2;
	// res[10] = 2129160099;
	for ( int i = 0; i < n; i++ ) {
		long long e = modular_power(x[i], pow[i], mod[i]);
		printf("%lld ^ %d = %lld (mod %lld)\n", x[i], pow[i], e, \
				mod[i]);
		printf("\t%d\n", (e == res[i]));
	}
	*/
	/* PROBABLEPRIME, STRONGPROBABLEPRIME, OLDPROBABLEPRIME
	long long a, m;
	_Bool spp, pp, opp;
	m = 1387;
	a = 2;
	pp = probableprime(m, a);
	if ( pp ) {
		printf("%lld is a probable prime to the base %lld\n", m, a);
	} else {
		printf("%lld is composite\n", m);
	}
	m = 1387;
	a = 2;
	spp = strongprobableprime(m, a);
	if ( spp ) {
		printf("%lld is a strong probable prime to the base %lld\n",
				m, a);
	} else {
		printf("%lld is composite\n", m);
	}
	m = 1763;
	a = 2;
	pp = probableprime(m, a);
	if ( pp ) {
		printf("%lld is a probable prime to the base %lld\n", m, a);
	} else {
		printf("%lld is composite\n", m);
	}
	m = 2047;
	a = 2;
	spp = strongprobableprime(m, a);
	if ( spp ) {
		printf("%lld is a strong probable prime to the base %lld\n",
				m, a);
	} else {
		printf("%lld is composite\n", m);
	}
	m = 2047;
	a = 3;
	spp = strongprobableprime(m, a);
	if ( spp ) {
		printf("%lld is a strong probable prime to the base %lld\n",
				m, a);
	} else {
		printf("%lld is composite\n", m);
	}
	m = 1373563;
	a = 2;
	spp = strongprobableprime(m, a);
	if ( spp ) {
		printf("%lld is a strong probable prime to the base %lld\n",
				m, a);
	} else {
		printf("%lld is composite\n", m);
	}
	m = 1373563;
	a = 3;
	spp = strongprobableprime(m, a);
	if ( spp ) {
		printf("%lld is a strong probable prime to the base %lld\n",
				m, a);
	} else {
		printf("%lld is composite\n", m);
	}
	m = 1373563;
	a = 5;
	spp = strongprobableprime(m, a);
	if ( spp ) {
		printf("%lld is a strong probable prime to the base %lld\n",
				m, a);
	} else {
		printf("%lld is composite\n", m);
	}
	m = 1373653;
	a = 2;
	spp = strongprobableprime(m, a);
	if ( spp ) {
		printf("%lld is a strong probable prime to the base %lld\n",
				m, a);
	} else {
		printf("%lld is composite\n", m);
	}
	m = 1373653;
	a = 3;
	spp = strongprobableprime(m, a);
	if ( spp ) {
		printf("%lld is a strong probable prime to the base %lld\n",
				m, a);
	} else {
		printf("%lld is composite\n", m);
	}
	m = 1373653;
	a = 5;
	spp = strongprobableprime(m, a);
	if ( spp ) {
		printf("%lld is a strong probable prime to the base %lld\n",
				m, a);
	} else {
		printf("%lld is composite\n", m);
	}

	m = 25326001;
	a = 2;
	spp = strongprobableprime(m, a);
	if ( spp ) {
		printf("%lld is a strong probable prime to the base %lld\n",
				m, a);
	} else {
		printf("%lld is composite\n", m);
	}
	m = 25326001;
	a = 3;
	spp = strongprobableprime(m, a);
	if ( spp ) {
		printf("%lld is a strong probable prime to the base %lld\n",
				m, a);
	} else {
		printf("%lld is composite\n", m);
	}
	m = 25326001;
	a = 5;
	spp = strongprobableprime(m, a);
	if ( spp ) {
		printf("%lld is a strong probable prime to the base %lld\n",
				m, a);
	} else {
		printf("%lld is composite\n", m);
	}
	m = 25326001;
	a = 7;
	spp = strongprobableprime(m, a);
	if ( spp ) {
		printf("%lld is a strong probable prime to the base %lld\n",
				m, a);
	} else {
		printf("%lld is composite\n", m);
	}
	m = 2532597;
	a = 5;
	spp = strongprobableprime(m, a);
	if ( spp ) {
		printf("%lld is a strong probable prime to the base %lld\n",
				m, a);
	} else {
		printf("%lld is composite\n", m);
	}
	m = 25325997;
	a = 5;
	spp = strongprobableprime(m, a);
	if ( spp ) {
		printf("%lld is a strong probable prime to the base %lld\n",
				m, a);
	} else {
		printf("%lld is composite\n", m);
	}
	m = 161038;
	a = 2;
	opp = oldprobableprime(m, a);
	if ( opp ) {
		printf("%lld is a probable prime to the base %lld in the 'old' sense\n", m, a);
	} else {
		printf("%lld is composite\n", m);
	}
	m = 161038;
	a = 2;
	pp = probableprime(m, a);
	if ( pp ) {
		printf("%lld is a probable prime to the base %lld\n", m, a);
	} else {
		printf("%lld is composite\n", m);
	}
	m = 341;
	a = 2;
	pp = probableprime(m, a);
	if ( pp ) {
		printf("%lld is a probable prime to the base %lld\n", m, a);
	} else {
		printf("%lld is composite\n", m);
	}
	*/
	// PRINT_PROPER_DIVISORS_ITER
	long long m;
	int len;
	/*
	m = 341;
	len = 1;
	long long bases_0[len];
	bases_0[0] = 2;
	print_proper_divisors_iter(m, bases_0, len);
	*/
	//
	/*
	m = 1373653;
	len = 12;
	long long bases_1[len];
	bases_1[0] = 2;
	bases_1[1] = 3;
	bases_1[2] = 5;
	bases_1[3] = 7;
	bases_1[4] = 11;
	bases_1[5] = 13;
	bases_1[6] = 495502;
	bases_1[7] = 4;
	bases_1[8] = 6;
	bases_1[9] = 10;
	bases_1[10] = 14;
	bases_1[11] = 23;
	print_proper_divisors_iter(m, bases_1, len);
	*/
	//
	/*
	m = 8131;
	len = m / 2;
	long long bases_2[len];
	for ( int i = 0; i < len; i++ ) {
		bases_2[i] = i;
	}
	// bases_2[0] = 2;
	// bases_2[1] = 3;
	// bases_2[2] = 5;
	// bases_2[3] = 7;
	// bases_2[4] = 11;
	// bases_2[5] = 13;
	// bases_2[6] = 495502;
	// bases_2[7] = 4;
	// bases_2[8] = 6;
	// bases_2[9] = 10;
	// bases_2[10] = 14;
	// bases_2[11] = 23;
	// bases_2[12] = 29;
	// bases_2[13] = 17;
	// bases_2[14] = 31;
	print_proper_divisors_iter(m, bases_2, len);
	*/
	//
	m = 16019;
	len = (m - 2) / 2;
	long long bases_3[len];
	for ( int i = 0; i < len; i++ ) {
		bases_3[i] = i + 2;
	}
	print_proper_divisors_iter(m, bases_3, len);
	return 0;
}

