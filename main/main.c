#include <stdio.h>
#include <stddef.h>

#include "base.h"
#include "euclid.h"
#include "solvelinear.h"
#include "modulararithmetic.h"
#include "horner.h"
#include "probableprime.h"
#include "hensel.h"
// #include "test-hensel.h"
#include "nthpower.h"

int main(void) {
	/* IS_NTH_POWER_RESIDUE
	int len = 6;
	long long n[len], a[len], p[len];
	n[0] = 5;
	a[0] = 6;
	p[0] = 101;
	n[1] = 12;
	a[1] = 16;
	p[1] = 17;
	n[2] = 48;
	a[2] = 9;
	p[2] = 17;
	n[3] = 20;
	a[3] = 13;
	p[3] = 17;
	n[4] = 11;
	a[4] = 9;
	p[4] = 17;
	n[5] = 2;
	a[5] = 43;
	p[5] = 97;
	while ( len-- > 0 ) {
		if ( is_nth_power_modulo_prime(n[len], a[len], p[len]) ) {
			printf("%lld is a %lld-power mod %lld\n", a[len], \
					n[len], p[len]);
		} else {
			printf("%lld is not a %lld-power mod %lld\n", a[len], \
					n[len], p[len]);
		}
	*/
	int len = 9;
	long long a[len], p[len];
	a[0] = 6;
	p[0] = 101;
	a[1] = 16;
	p[1] = 17;
	a[2] = 9;
	p[2] = 17;
	a[3] = 13;
	p[3] = 17;
	a[4] = 7;
	p[4] = 29;
	a[5] = 43;
	p[5] = 97;
	a[6] = 10;
	p[6] = 13;
	a[7] = 5;
	p[7] = 19;
	a[8] = 3;
	p[8] = 11;
	while ( len-- > 0 ) {
		if ( is_nth_power_modulo_prime(2, a[len], p[len]) ) {
			printf("%lld ^ 2 = %lld (mod %lld)\n", \
				quadratic_ressol(a[len], p[len]), a[len], \
				p[len]);
		} else {
			printf("%lld is not a square mod %lld\n", a[len], p[len]);
		}
	}
	return 0;
}

