#ifndef HENSEL_H
#define HENSEL_H

#include <stdio.h>

#include "euclid.h"
#include "modulararithmetic.h"
#include "horner.h"

void lift_nonsingular_once(long long *x, int deg, long long f[], int deg_der, long long f_der[], long long p, long long *j);
	// inout : x, a solution to f = 0 (mod p ^ j) such that
	// 	f'(x) != 0 (mod p)
	// in : deg, integer representing degree of f
	// in : f, long long list representing the coefficients of the
	// 	polynomial
	// in : deg_der, degree of f_der
	// in : f_der, f derived
	// in : p, a prime
	// inout : j, a positive integer; after execution x is, still, a
	// 	solution to f = 0 (mod p ^ j)
void lift_nonsingular_iter(long long *x, int deg, long long f[], int deg_der, long long f_der[], long long p, long long *j, long long j_desired);
	// calls lift_nonsingular_once until accuracy j_desired is attained
	// (it might turn out to be better); since a nonsingular solution
	// remains nonsingular after being lifted, is_nonsingular_solution is
	// called only once
void lift_singular_once(long long *x, long long t, int deg, long long f[], int deg_der, long long f_der[], long long p, long long *j);
	// same as lift_nonsingular_once;
	// assumes x is a solution to f = 0 (mod p ^ j) and, additionally, that
	// f'(x) == 0 (mod p); assumes t is the exact power of p dividing
	// f'(x) and lifts x to a solution of the form x + b * p ^ (j - t)
	// of f = 0 (mod p ^ (j + 1)); the number b is uniquely determined mod
	// p
void lift_singular_iter(long long *x, long long t, int deg, long long f[], int deg_der, long long f_der[], long long p, long long *j, long long j_desired);
	// calls lift_singular_once until accuracy j_desired or better is
	// attained
void lift_solution_iter(long long *x, int deg, long long f[], long long p, long long *j, long long j_desired);
	// determines if a solution is nonsingular or not and calls the
	// appropriate function;
	// since the exact power t of p dividing f'(x) does not
	// change *if* x is replaced by the unique solution of the form
	// x + b * p ^ (j - t) to f = 0 (mod p ^ (j + 1)) with b a resiue
	// mod p, then singular_can_lift needs to be called only once

_Bool is_solution(long long x, int deg, long long f[], long long p, long long j);
	// returns TRUE, if and only if f(x) = horner(f, x, deg) == 0 (p ^ j)
_Bool is_nonsingular_solution(long long x, int deg, long long f[], long long p);
	// returns TRUE, if the solution x to f = 0 (mod p) satisfies
	// f'(x) != 0 (mod p)
_Bool solution_is_nonsingular(long long x, int deg_der, long long f_der[], long long p);
	// in : x, a solution to f = 0 (mod p)
	// in : deg_deg, degree of f_der
	// in(out) : f_der, derivative of f
	// in : p, a prime
	// returns TRUE, if p does not divide f_der(x) and FALSE, otherwise
_Bool singular_can_lift(long long x, long long e, long long p, long long j);
	// x : a solution to f = 0 (mod p ^ j)
	// e = f(x) = horner(f, x, deg) : the value of f at x
	// returns TRUE, if and only if p ^ (j + 1) divides e
	// if FALSE, this means the residue class of x mod p ^ j does not give
	// rise to any solution mod p ^ (j + 1)
_Bool singular_can_apply_hensel(long long x, int deg_der, long long f_der[], long long p, long long j);
	// returns TRUE, if the singular solution x to f = 0 (mod p ^ j) can be
	// lifted using Hensel's method; explicitly, this means:
	// in : x, a residue mod p ^ j and a solution to f = 0 (mod p ^ j)
	// in : deg_der, degree of the derivative of f
	// in(out) : f_der, derivative of a polynomial f such that
	// 	f(x) = 0 (mod p ^ j); to determine whether a solution can be
	// 	lifted using Hensel's method, one only needs the derivative of
	// 	the polynomial
	// outputs TRUE, if the exact power t of p dividing f'(x) satisfies
	// j >= 2 * t + 1 and FALSE, otherwise; if TRUE, the residue class of
	// x (mod p ^ (j - t)) lifts to a solution mod p ^ (j + 1); this class
	// is of the form x + b * p ^ (j - t) for a unique b (mod p)
long long p_content(long long e, long long p);
	// returns exact power of p dividing e
_Bool solution_can_lift(long long x, int deg, long long f[], int deg_der, long long f_der[], long long p, long long j);
	// returns TRUE, if the solution x to f = 0 (mod p ^ j) can be lifted

#endif
