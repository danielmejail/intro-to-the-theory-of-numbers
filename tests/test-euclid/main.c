#include <stdio.h>
#include <stddef.h>
#include "euclid.h"

int main(void) {
	long long a, b, g;
	a = 42823;
	b = 6409;
	long long x, y;
	g = euclid_extended(a, b, &x, &y);
	printf("(%lld,%lld) = %lld * %lld + %lld * %lld = %lld", a, b, a, x, b, y, g);
	printf("\n");
	a = 5033464705;
	b = 3137640337;
	g = euclid_extended(a, b, &x, &y);
	printf("(%lld,%lld) = %lld * %lld + %lld * %lld = %lld", a, b, a, x, b, y, g);
	printf("\n");
	/* FINDREMAINDER
	int n = 10;
	long long x[n], m;
	m = 5;
	x[0] = 0;
	x[1] = 4;
	x[2] = 5;
	x[3] = 15;
	x[4] = 23;
	x[5] = -5;
	x[6] = -1;
	x[7] = -4;
	x[8] = -30;
	x[9] = -13;
	for ( int i = 0; i < n; i++ ) {
		printf("%lld = %lld (mod %lld)\n", x[i], \
				findremainder(x[i],m), m);
	}
	*/
	return 0;
}
