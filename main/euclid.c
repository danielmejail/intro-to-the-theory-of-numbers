#include <stdio.h>
#include "euclid.h"

long long findremainder(long long x, long long m){
	// assumes m >= 0
	long long r, q;
	if ( m == 0 ) {
		return x;
	}
	if ( x >= 0 ) {
		q = x/m; // assuming this works ``correctly'': floor (x div m)
		return x - m * q;
	} else {
		// return findremainder(m - findremainder(-x, m), m);
		if ( (r = m - findremainder(-x, m)) < m ) {
			return r;
		} else {
			return 0;
		}
	}
	// long long q = x / m;
	// return x - m * q;
}

long long euclid(long long a, long long b) {
	long long r, q;
	q = b/a;
	r = b - a*q;
	while(r>0) {
		b = a;
		a = r;
		q = b/a;
		r = b - a*q;
	}
	return a;
}

long long leastcommonmultiple(a, b)
	long long a, b;
{
	return (a * b) / euclid(a, b);
}

_Bool isunit(long long a, long long m) {
	return ( euclid(a, m) == 1 );
}

long long euclid_extended_iter(v0, v1)
	// (int r0, int x0, int y0, int r1, int x1, int y1)
	// returns g = euclid(a, b) after updating x, y with values such that
	// ax + by = g
	// in the final implementation, x and y should be considered having
	// garbage values which are updated first to 1 and 0, respectively,
	// then to 0 and 1 and, finally, after an iteration of the euclidean
	// algorithm, to the expected values
	long long *v0[3], v1[3];
	{
	long long v_temp[3], q;
	while ( v1[0] > 0 ) {
		q = *v0[0] / v1[0];
		v_temp[0] = *v0[0] - v1[0] * q;
		v_temp[1] = *v0[1] - v1[1] * q;
		v_temp[2] = *v0[2] - v1[2] * q;
		for ( int i = 0; i < 3 ; i++ ) {
			*v0[i] = v1[i];
			v1[i] = v_temp[i];
		}
	}
	return *v0[0];
}

long long euclid_extended(long long a, long long b, long long *px, long long *py) {
	// function call should be g = euclid_extended(a, b, &x, &y), where
	// x and y are the variables holding the values such that
	// ax + by = g
	long long *v0[3], v1[3];
	*px = 1;
	*py = 0;
	v0[0] = &a;
	v0[1] = px;
	v0[2] = py;
	v1[0] = b;
	v1[1] = 0;
	v1[2] = 1;
	return ( euclid_extended_iter(v0, v1) );
}

long long findinverse(long long a, long long m) {
	// assumes euclid(a, m) == 1 returns a_inv such that
	// 0 <= a_inv < m (?) and a * a_inv + m * y = 1
	// actually returns a_inv such that a * a_inv + m * y = g
	long long a_inv, y, g;
	g = euclid_extended(a, m, &a_inv, &y);
	return a_inv;
}
