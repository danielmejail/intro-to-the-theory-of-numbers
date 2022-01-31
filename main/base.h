#ifndef BASE_H
#define BASE_H

#define FALSE 0
#define TRUE 1
#define max(A, B) ((A) > (B) ? (A) : (B))

#include <stdio.h>
#include "euclid.h"

long long square(long long a);

long long power_iter(long long a, long long pow, long long partial);

long long power(long long a, long long pow);

#endif
