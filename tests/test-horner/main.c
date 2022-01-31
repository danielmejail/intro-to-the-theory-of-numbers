#include <stdio.h>
#include <stddef.h>

#include "euclid.h"
#include "solvelinear.h"
#include "modulararithmetic.h"
#include "horner.h"

int main(void) {
	int n, deg;
	n = 14;
	deg = 2;
	long long u, u_red;
	u = 1;
	u_red = 1;
	long long mod = 131; // 36287
	long long p[deg + 1];
	p[0] = 1;
	p[1] = 0;
	p[2] = 1;
	printf("u = %lld\t = %lld (mod %lld)\n", u, u_red, mod);
	while ( n > 0 ) {
		u = horner(p, u, deg);
		u_red = horner_modular(p, u_red, deg, mod);
		printf("u = %lld\t = %lld (mod %lld)\n", u, u_red, mod);
		n--;
	}
	return 0;
}

