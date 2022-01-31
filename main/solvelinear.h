#ifndef SOLVELINEAR_H
#define SOLVELINEAR_H

#include <stdio.h>
#include "euclid.h"

long long solvelinearreduced(long long a, long long b, long long m);
	// returns a (the) solution to ax = b (mod m); assumes euclid(a, m)==1
long long solvelinear(long long a, long long b, long long m);
	// returns a (one) solution to the congruence ax = b (mod m)
_Bool linearissolvable(long long a, long long b, long long m);
	// returns True, if and only if the congruence ax = b (mod m)
	// has a solution
_Bool pairwisecoprime(long long *moduli, int n);
	// returns True, if and only if (m_i,m_j)=1 for all m_i, m_j in moduli,
	// i, j < n and i != j
long long chineseremainder(long long *residues, long long *moduli, int n);
	// given a sequence of moduli satisfying (m_1,m_2)=1, and a sequence
	// of residues, returns a residue x (mod m) such that x = a (mod m_i)
	// for every modulus m_i and corresponding residue a_i, i < n
long long solvelinear_extended_rec(long long *a, long long *b, long long *m, long long prev_sol, long long prev_mod, int n);
	// solve the system a * x = b (m), recursively
long long solvelinear_extended_iter(long long *a, long long *b, long long *m, long long sol, long long lcm, int n);
	// solve the system a * x = b (m), iteratively...
long long solvelinear_extended(long long *a, long long *b, long long *m, int n);
	// returns a solution to the list of congruences ax = b (mod m)
	// n is the assumed length of the vectors a, b and m
	// solution should be 0 <= x < lcm(m); a negative return value should
	// indicate that there is no common solution
#endif

