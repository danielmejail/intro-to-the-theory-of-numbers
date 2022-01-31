#ifndef EUCLID_H
#define EUCLID_H

#include <stdio.h>

long long euclid_extended_iter(long long *v0[], long long v1[]);

long long euclid_extended(long long a, long long b, long long *px, \
		long long *py);

#endif
