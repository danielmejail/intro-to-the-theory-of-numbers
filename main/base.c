#include <stdio.h>
#include "base.h"

long long square(a)
	long long a;
{
	return ( a * a );
}

long long power_iter(a, pow, partial)
	long long a, pow, partial;
{
	while ( pow > 0 ) {
		if ( euclid(pow, 2) == 1 ) {
			partial *= a;
			pow--;
		} else {
			a = square(a);
			pow /= 2;
		}
	}
	return partial;
}

long long power(a, pow)
	long long a, pow;
{
	return power_iter(a, pow, 1);
}

