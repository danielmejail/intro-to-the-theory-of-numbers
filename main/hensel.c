#include <stdio.h>

#include "hensel.h"

void lift_nonsingular_once(x, deg, f, deg_der, f_der, p, j)
	long long *x, f[], f_der[], p, *j;
	int deg, deg_der;
{
	long long e, e_der, b;
	e = horner(f, *x, deg);
	for ( int i = 0; i < *j; i++) {
		e /= p;
	}
	e_der = horner(f_der, *x, deg_der);
	b = modular_multiply( (-1) * e, findinverse(e_der, p), p);
	*x += b * power(p, *j);
	*j += 1;
}

void lift_nonsingular_iter(x, deg, f, deg_der, f_der, p, j, j_desired)
	long long *x, f[], f_der[], p, *j, j_desired;
	int deg, deg_der;
{
	while ( *j < j_desired ) {
		lift_nonsingular_once(x, deg, f, deg_der, f_der, p, j);
	}
}

void lift_singular_once(x, t, deg, f, deg_der, f_der, p, j)
	long long *x, t, f[], f_der[], p, *j;
	int deg, deg_der;
{
	long long e, e_der, b;
	e = horner(f, *x, deg);
	for ( int i = 0; i < *j; i++ ){
		e /= p;
	}
	e_der = horner(f_der, *x, deg_der);
	for ( int i = 0; i < t; i++ ){
		e_der /= p;
	}
	b = modular_multiply( (-1) * e, findinverse(e_der, p), p);
	*x += b * power(p, *j - t);
	*j += 1;
}

void lift_singular_iter(x, t, deg, f, deg_der, f_der, p, j, j_desired)
	long long *x, t, f[], f_der[], p, *j, j_desired;
	int deg, deg_der;
{
	while ( *j < j_desired ) {
		lift_singular_once(x, t, deg, f, deg_der, f_der, p, j);
	}
}

void lift_solution_iter(x, deg, f, p, j, j_desired)
	long long *x, f[], p, *j, j_desired;
	int deg;
{
	int deg_der;
	long long f_der[max(0, deg)], e_der, t;
	derived_polynomial(deg, f, &deg_der, f_der);
	e_der = horner(f_der, *x, deg_der);
	t = p_content(e_der, p);
	if ( t == 0 ) {
		// solution is nonsingular
		lift_nonsingular_iter(x, deg, f, deg_der, f_der, p, j, \
				j_desired);
	} else {
		lift_singular_iter(x, t, deg, f, deg_der, f_der, p, j, \
				j_desired);
	}
}

_Bool is_solution(x, deg, f, p, j)
	long long x, f[], p, j;
	int deg;
{
	return ( horner_modular(f, x, deg, power(p, j)) == 0 );
}

_Bool is_nonsingular_solution(x, deg, f, p)
	long long x, f[], p;
	int deg;
{
	int deg_der;
	long long f_der[max(0, deg)];
	derived_polynomial(deg, f, &deg_der, f_der);
	return ( findremainder(horner_modular(f_der, x, deg_der, p), \
				p) != 0 );
}

_Bool solution_is_nonsingular(x, deg_der, f_der, p)
	long long x, f_der[], p;
	int deg_der;
{
	return ( findremainder(horner_modular(f_der, x, deg_der, p), \
				p) != 0 );
}

_Bool singular_can_lift(x, e, p, j)
	long long x, e, p, j;
{
	while ( j > 0 ) {
		e /= p;
		j--;
	}
	if ( findremainder(e, p) == 0 ) {
		return TRUE;
	} else {
		return FALSE;
	}
}

_Bool singular_can_apply_hensel(x, deg_der, f_der, p, j)
	long long x, f_der[], p, j;
	int deg_der;
{
	long long t = 0;
	long long e = horner(f_der, x, deg_der);
	while ( findremainder(e, p) == 0 ) {
		e /= p;
		t++;
	}
	return ( j >= 2 * t + 1 );
}

long long p_content(e, p)
	long long e, p;
{
	long long t = 0;
	while ( findremainder(e, p) == 0 ) {
		e /= p;
		t++;
	}
	return t;
}

_Bool solution_can_lift(x, deg, f, deg_der, f_der, p, j)
	long long x, f[], f_der[], p, j;
	int deg, deg_der;
{
	if ( solution_is_nonsingular(x, deg_der, f_der, p) ) {
		return TRUE;
	} else {
		// return singular_can_apply_hensel(x, deg_der, f_der, p, j);
		long long e = horner(f, x, deg);
		return singular_can_lift(x, e, p, j);
	}
}
