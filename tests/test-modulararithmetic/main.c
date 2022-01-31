#include <stdio.h>
#include <stddef.h>

#include "euclid.h"
#include "solvelinear.h"
#include "modulararithmetic.h"
#include "horner.h"

int main(void) {
	/* MODULAR_MULTIPLY
	long long x, y, mod;
	x = 999;
	y = 999;
	mod = 537;
	printf("%lld * %lld = %lld (mod %lld)\n", x, y, \
			modular_multiply(x, y, mod), mod);
	printf("%lld\n", findremainder(999 * 999, mod));
	*/
	/* MODULAR_POWER
	int n;
	n = 9;
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
	x[8] = 2;
	mod[8] = 11111111111;
	pow[8] = mod[8] - 1;
	res[8] = 1496324899;
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
	return 0;
}

