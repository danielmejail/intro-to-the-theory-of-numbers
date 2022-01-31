#include <stdio.h>
#include <stddef.h>

#include "base.h"
#include "euclid.h"
#include "solvelinear.h"
#include "modulararithmetic.h"
#include "horner.h"
#include "probableprime.h"
#include "hensel.h"
#include "test-hensel.h"

int main(void) {
	// test_hensel_boolean();
	// test_hensel_single_lifts();
	// test_hensel_multiple_lifts();
	// test_hensel_exercises();
	test_hensel_can_lift();
	return 0;
}

