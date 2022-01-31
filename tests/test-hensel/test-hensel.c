#include <stdio.h>
#include "test-hensel.h"

void test_hensel_boolean(void) {
	// test suite : tests the boolean functions in hensel.h
	void report_hensel(deg, f, p, j, x)
		// funtion to print the results of the test cases
		long long f[], p, j, x;
		int deg;
	{
		int deg_der;
		long long f_der[max(0, deg)], t;
		derived_polynomial(deg, f, &deg_der, f_der);
		if ( ! ( solution_is_nonsingular(x, deg_der, f_der, p) ) ) {
			printf("%lld is a singular solution mod %lld ^ %lld\n", x, p, j);
			printf("the exact power of %lld dividing f'(%lld) is %lld\n", p, x, (t = p_content(horner(f_der, x, deg_der), p)));
			if ( singular_can_apply_hensel(x, deg_der, f_der, p, j) ) {
				printf("the residue class of %lld mod %lld ^ %lld gives rise to a solution mod %lld ^ %lld\n", x, p, j - t, p, j + 1);
			} else {
				printf("%lld does not satisfy the hypotheses of Hensel's lemma\n", x);
			}
		} else {
			printf("%lld is a nonsingular solution mod %lld ^ %lld\n", x, p, j);
		}
		printf("---\n");
	}
	// TEST CASES
	void test_hensel_0(void) {
		int deg = 2;
		long long f[deg + 1], x, p, j;
		f[0] = 223;
		f[1] = 1;
		f[2] = 1;
		p = 3;
		j = 5;
		x = 4;
		report_hensel(deg, f, p, j, x);
	}
	void test_hensel_1(void) {
		int deg = 2;
		long long f[deg + 1], x, p, j;
		f[0] = 223;
		f[1] = 1;
		f[2] = 1;
		p = 3;
		j = 5;
		x = 22;
		report_hensel(deg, f, p, j, x);
	}
	void test_hensel_2(void) {
		int deg = 2;
		long long f[deg + 1], x, p, j;
		f[0] = 223;
		f[1] = 1;
		f[2] = 1;
		p = 3;
		j = 5;
		x = 49;
		report_hensel(deg, f, p, j, x);
	}
	void test_hensel_3(void) {
		int deg = 2;
		long long f[deg + 1], x, p, j;
		f[0] = 223;
		f[1] = 1;
		f[2] = 1;
		p = 3;
		j = 4;
		x = 13;
		report_hensel(deg, f, p, j, x);
	}
	void test_hensel_4(void) {
		int deg = 2;
		long long f[deg + 1], x, p, j;
		f[0] = 47;
		f[1] = 1;
		f[2] = 1;
		p = 7;
		j = 1;
		x = 1;
		report_hensel(deg, f, p, j, x);
	}
	void test_hensel_5(void) {
		int deg = 2;
		long long f[deg + 1], x, p, j;
		f[0] = 47;
		f[1] = 1;
		f[2] = 1;
		p = 7;
		j = 2;
		x = 1;
		report_hensel(deg, f, p, j, x);
	}
	void test_hensel_6(void) {
		int deg = 2;
		long long f[deg + 1], x, p, j;
		f[0] = 47;
		f[1] = 1;
		f[2] = 1;
		p = 7;
		j = 3;
		x = 99;
		report_hensel(deg, f, p, j, x);
	}
	void test_hensel_7(void) {
		int deg = 2;
		long long f[deg + 1], x, p, j;
		f[0] = 47;
		f[1] = 1;
		f[2] = 1;
		p = 7;
		j = 1;
		x = 5;
		report_hensel(deg, f, p, j, x);
	}
	// RUN TEST CASES
	test_hensel_0();
	test_hensel_1();
	test_hensel_2();
	test_hensel_3();
	test_hensel_4();
	test_hensel_5();
	test_hensel_6();
	test_hensel_7();
}

void test_hensel_single_lifts(void) {
	// test suite : tests lift_nonsingular_once and lift_singular_once
	void report_hensel(deg, f, p, j, x)
		// funtion to print the results of the test cases
		long long f[], p, j, x;
		int deg;
	{
		int deg_der;
		long long f_der[max(0, deg)], t;
		derived_polynomial(deg, f, &deg_der, f_der);
		if ( ! ( solution_is_nonsingular(x, deg_der, f_der, p) ) ) {
			printf("%lld is a singular solution mod %lld ^ %lld\n", x, p, j);
			printf("the exact power of %lld dividing f'(%lld) is %lld\n", p, x, (t = p_content(horner(f_der, x, deg_der), p)));
			if ( singular_can_apply_hensel(x, deg_der, f_der, p, j) ) {
				printf("the residue class of %lld mod %lld ^ %lld gives rise to a solution mod %lld ^ %lld\n", x, p, j - t, p, j + 1);
			} else {
				printf("%lld does not satisfy the hypotheses of Hensel's lemma\n", x);
			}
		} else {
			// printf("%lld\n",horner_modular(f, x, deg, power(p, j)));
			printf("%lld is a nonsingular solution mod %lld ^ %lld\n", x, p, j);
			lift_nonsingular_once(&x, deg, f, deg_der, f_der, p, &j);
			if ( horner_modular(f, x, deg, power(p, j)) == 0 ) {
				printf("%lld is a nonsingular solution mod %lld ^ %lld\n", x, p, j);
			} else {
				printf("lifting failed\n");
			}
		}
		printf("---\n");
	}
	// TEST CASES
	void test_hensel_0(void) {
		int deg = 2;
		long long f[deg + 1], x, p, j;
		f[0] = 223;
		f[1] = 1;
		f[2] = 1;
		p = 3;
		j = 5;
		x = 4;
		report_hensel(deg, f, p, j, x);
	}
	void test_hensel_1(void) {
		int deg = 2;
		long long f[deg + 1], x, p, j;
		f[0] = 223;
		f[1] = 1;
		f[2] = 1;
		p = 3;
		j = 5;
		x = 22;
		report_hensel(deg, f, p, j, x);
	}
	void test_hensel_2(void) {
		int deg = 2;
		long long f[deg + 1], x, p, j;
		f[0] = 223;
		f[1] = 1;
		f[2] = 1;
		p = 3;
		j = 5;
		x = 49;
		report_hensel(deg, f, p, j, x);
	}
	void test_hensel_3(void) {
		int deg = 2;
		long long f[deg + 1], x, p, j;
		f[0] = 223;
		f[1] = 1;
		f[2] = 1;
		p = 3;
		j = 4;
		x = 13;
		report_hensel(deg, f, p, j, x);
	}
	void test_hensel_4(void) {
		int deg = 2;
		long long f[deg + 1], x, p, j;
		f[0] = 47;
		f[1] = 1;
		f[2] = 1;
		p = 7;
		j = 1;
		x = 1;
		report_hensel(deg, f, p, j, x);
	}
	void test_hensel_5(void) {
		int deg = 2;
		long long f[deg + 1], x, p, j;
		f[0] = 47;
		f[1] = 1;
		f[2] = 1;
		p = 7;
		j = 2;
		x = 1;
		report_hensel(deg, f, p, j, x);
	}
	void test_hensel_6(void) {
		int deg = 2;
		long long f[deg + 1], x, p, j;
		f[0] = 47;
		f[1] = 1;
		f[2] = 1;
		p = 7;
		j = 3;
		x = 99;
		report_hensel(deg, f, p, j, x);
	}
	void test_hensel_7(void) {
		int deg = 2;
		long long f[deg + 1], x, p, j;
		f[0] = 47;
		f[1] = 1;
		f[2] = 1;
		p = 7;
		j = 1;
		x = 5;
		report_hensel(deg, f, p, j, x);
	}
	void test_hensel_8(void) {
		int deg = 2;
		long long f[deg + 1], x, p, j;
		f[0] = 47;
		f[1] = 1;
		f[2] = 1;
		p = 7;
		j = 2;
		x = 47;
		report_hensel(deg, f, p, j, x);
	}
	// RUN TEST CASES
	test_hensel_0();
	test_hensel_1();
	test_hensel_2();
	test_hensel_3();
	test_hensel_4();
	test_hensel_5();
	test_hensel_6();
	test_hensel_7();
	test_hensel_8();
}

void test_hensel_multiple_lifts(void) {
	// test suite : tests lift_nonsingular_iter and lift_singular_iter
	void report_hensel(deg, f, p, j, x, j_desired)
		// funtion to print the results of the test cases
		long long f[], p, j, x, j_desired;
		int deg;
	{
		int deg_der;
		long long f_der[max(0, deg)], t;
		derived_polynomial(deg, f, &deg_der, f_der);
		if ( ! ( solution_is_nonsingular(x, deg_der, f_der, p) ) ) {
			printf("%lld is a singular solution mod %lld ^ %lld\n", x, p, j);
			printf("the exact power of %lld dividing f'(%lld) is %lld\n", p, x, (t = p_content(horner(f_der, x, deg_der), p)));
			if ( singular_can_apply_hensel(x, deg_der, f_der, p, j) ) {
				printf("the residue class of %lld mod %lld ^ %lld gives rise to a solution mod %lld ^ %lld\n", x, p, j - t, p, j + 1);
				lift_singular_iter(&x, t, deg, f, deg_der, f_der, p, &j, j_desired);
				if ( horner_modular(f, x, deg, power(p, j)) == 0 ) {
					printf("%lld is a singular solution mod %lld ^ %lld\n", x, p, j);
				} else {
					printf("lifting failed\n");
				}
			} else {
				printf("%lld does not satisfy the hypotheses of Hensel's lemma\n", x);
			}
		} else {
			printf("%lld is a nonsingular solution mod %lld ^ %lld\n", x, p, j);
			lift_nonsingular_iter(&x, deg, f, deg_der, f_der, p, &j, j_desired);
			if ( horner_modular(f, x, deg, power(p, j)) == 0 ) {
				printf("%lld is a nonsingular solution mod %lld ^ %lld\n", x, p, j);
			} else {
				printf("lifting failed\n");
			}
		}
		printf("---\n");
	}
	// TEST CASES
	void test_hensel_0(void) {
		int deg = 2;
		long long f[deg + 1], x, p, j, j_desired;
		f[0] = 223;
		f[1] = 1;
		f[2] = 1;
		p = 3;
		j = 5;
		x = 4;
		j_desired = 6;
		report_hensel(deg, f, p, j, x, j_desired);
	}
	void test_hensel_1(void) {
		int deg = 2;
		long long f[deg + 1], x, p, j, j_desired;
		f[0] = 223;
		f[1] = 1;
		f[2] = 1;
		p = 3;
		j = 5;
		x = 4;
		j_desired = 5;
		report_hensel(deg, f, p, j, x, j_desired);
	}
	void test_hensel_2(void) {
		int deg = 2;
		long long f[deg + 1], x, p, j, j_desired;
		f[0] = 223;
		f[1] = 1;
		f[2] = 1;
		p = 3;
		j = 5;
		x = 4;
		j_desired = 3;
		report_hensel(deg, f, p, j, x, j_desired);
	}
	void test_hensel_3(void) {
		int deg = 2;
		long long f[deg + 1], x, p, j, j_desired;
		f[0] = 223;
		f[1] = 1;
		f[2] = 1;
		p = 3;
		j = 5;
		x = 22;
		j_desired = 6;
		report_hensel(deg, f, p, j, x, j_desired);
	}
	void test_hensel_4(void) {
		int deg = 2;
		long long f[deg + 1], x, p, j, j_desired;
		f[0] = 223;
		f[1] = 1;
		f[2] = 1;
		p = 3;
		j = 5;
		x = 22;
		j_desired = 7;
		report_hensel(deg, f, p, j, x, j_desired);
	}
	void test_hensel_5(void) {
		int deg = 2;
		long long f[deg + 1], x, p, j, j_desired;
		f[0] = 223;
		f[1] = 1;
		f[2] = 1;
		p = 3;
		j = 5;
		x = 49;
		j_desired = 6;
		report_hensel(deg, f, p, j, x, j_desired);
	}
	void test_hensel_6(void) {
		int deg = 2;
		long long f[deg + 1], x, p, j, j_desired;
		f[0] = 223;
		f[1] = 1;
		f[2] = 1;
		p = 3;
		j = 4;
		x = 13;
		j_desired = 3;
		report_hensel(deg, f, p, j, x, j_desired);
	}
	void test_hensel_7(void) {
		int deg = 2;
		long long f[deg + 1], x, p, j, j_desired;
		f[0] = 47;
		f[1] = 1;
		f[2] = 1;
		p = 7;
		j = 1;
		x = 1;
		j_desired = 1;
		report_hensel(deg, f, p, j, x, j_desired);
	}
	void test_hensel_8(void) {
		int deg = 2;
		long long f[deg + 1], x, p, j, j_desired;
		f[0] = 47;
		f[1] = 1;
		f[2] = 1;
		p = 7;
		j = 1;
		x = 1;
		j_desired = 2;
		report_hensel(deg, f, p, j, x, j_desired);
	}
	void test_hensel_9(void) {
		int deg = 2;
		long long f[deg + 1], x, p, j, j_desired;
		f[0] = 47;
		f[1] = 1;
		f[2] = 1;
		p = 7;
		j = 1;
		x = 1;
		j_desired = 3;
		report_hensel(deg, f, p, j, x, j_desired);
	}
	void test_hensel_10(void) {
		int deg = 2;
		long long f[deg + 1], x, p, j, j_desired;
		f[0] = 47;
		f[1] = 1;
		f[2] = 1;
		p = 7;
		j = 1;
		x = 1;
		j_desired = 5;
		report_hensel(deg, f, p, j, x, j_desired);
	}
	void test_hensel_11(void) {
		int deg = 2;
		long long f[deg + 1], x, p, j, j_desired;
		f[0] = 47;
		f[1] = 1;
		f[2] = 1;
		p = 7;
		j = 2;
		x = 1;
		j_desired = 1;
		report_hensel(deg, f, p, j, x, j_desired);
	}
	void test_hensel_12(void) {
		int deg = 2;
		long long f[deg + 1], x, p, j, j_desired;
		f[0] = 47;
		f[1] = 1;
		f[2] = 1;
		p = 7;
		j = 3;
		x = 99;
		j_desired = 5;
		report_hensel(deg, f, p, j, x, j_desired);
	}
	void test_hensel_13(void) {
		int deg = 2;
		long long f[deg + 1], x, p, j, j_desired;
		f[0] = 47;
		f[1] = 1;
		f[2] = 1;
		p = 7;
		j = 1;
		x = 5;
		j_desired = 4;
		report_hensel(deg, f, p, j, x, j_desired);
	}
	void test_hensel_14(void) {
		int deg = 2;
		long long f[deg + 1], x, p, j, j_desired;
		f[0] = 47;
		f[1] = 1;
		f[2] = 1;
		p = 7;
		j = 2;
		x = 47;
		j_desired = 4;
		report_hensel(deg, f, p, j, x, j_desired);
	}
	// RUN TEST CASES
	test_hensel_0();
	test_hensel_1();
	test_hensel_2();
	test_hensel_3();
	test_hensel_4();
	test_hensel_5();
	test_hensel_6();
	test_hensel_7();
	test_hensel_8();
	test_hensel_9();
	test_hensel_10();
	test_hensel_11();
	test_hensel_12();
	test_hensel_13();
	test_hensel_14();
}

void test_hensel_exercises(void) {
	void report_hensel(deg, f, p, j, x, j_desired)
		// funtion to print the results of the test cases
		long long f[], p, j, x, j_desired;
		int deg;
	{
		int deg_der;
		long long f_der[max(0, deg)], t;
		derived_polynomial(deg, f, &deg_der, f_der);
		if ( ! ( solution_is_nonsingular(x, deg_der, f_der, p) ) ) {
			printf("%lld is a singular solution mod %lld ^ %lld\n", x, p, j);
			printf("the exact power of %lld dividing f'(%lld) is %lld\n", p, x, (t = p_content(horner(f_der, x, deg_der), p)));
			if ( singular_can_apply_hensel(x, deg_der, f_der, p, j) ) {
				printf("the residue class of %lld mod %lld ^ %lld gives rise to a solution mod %lld ^ %lld\n", x, p, j - t, p, j + 1);
				lift_singular_iter(&x, t, deg, f, deg_der, f_der, p, &j, j_desired);
				if ( horner_modular(f, x, deg, power(p, j)) == 0 ) {
					printf("%lld is a singular solution mod %lld ^ %lld\n", x, p, j);
				} else {
					printf("lifting failed\n");
				}
			} else {
				printf("%lld does not satisfy the hypotheses of Hensel's lemma\n", x);
			}
		} else {
			printf("%lld is a nonsingular solution mod %lld ^ %lld\n", x, p, j);
			lift_nonsingular_iter(&x, deg, f, deg_der, f_der, p, &j, j_desired);
			if ( horner_modular(f, x, deg, power(p, j)) == 0 ) {
				printf("%lld is a nonsingular solution mod %lld ^ %lld\n", x, p, j);
			} else {
				printf("lifting failed\n");
			}
		}
		printf("---\n");
	}
	void test_hensel_0(void) {
		// x5 + x4 + 1 (3 ^ 4)
		int deg = 5;
		long long f[deg + 1], x, p, j, j_desired;
		f[0] = 1;
		f[1] = 0;
		f[2] = 0;
		f[3] = 0;
		f[4] = 1;
		f[5] = 1;
		p = 3;
		j = 1;
		x = 1;
		j_desired = 4;
		report_hensel(deg, f, p, j, x, j_desired);
	}
	void test_hensel_1(void) {
		// x3 + x + 57 (5 ^ 3)
		int deg = 3;
		long long f[deg + 1], x, p, j, j_desired;
		f[0] = 57;
		f[1] = 1;
		f[2] = 0;
		f[3] = 1;
		p = 5;
		j = 1;
		// x = 4; // although this line is commented garbage value turned out to be solution, or the programme found one
		j_desired = 3;
		report_hensel(deg, f, p, j, x, j_desired);
	}
	void test_hensel_2(void) {
		// x2 + 5 x + 24 (36)
		// x2 + 5 x + 24 (2 ^ 2)
		int deg = 2;
		long long f[deg + 1], x, p, j, j_desired;
		f[0] = 24;
		f[1] = 5;
		f[2] = 1;
		p = 2;
		j = 1;
		x = 1;
		j_desired = 2;
		report_hensel(deg, f, p, j, x, j_desired);
	}
	void test_hensel_3(void) {
		// x2 + 5 x + 24 (36)
		// x2 + 5 x + 24 (3 ^ 2)
		int deg = 2;
		long long f[deg + 1], x, p, j, j_desired;
		f[0] = 24;
		f[1] = 5;
		f[2] = 1;
		p = 3;
		j = 1;
		x = 1;
		j_desired = 2;
		report_hensel(deg, f, p, j, x, j_desired);
	}
	void test_hensel_4(void) {
		// x3 + 10 x2 + x + 3 (3 ^ 3)
		int deg = 3;
		long long f[deg + 1], x, p, j, j_desired;
		f[0] = 3;
		f[1] = 1;
		f[2] = 10;
		f[3] = 1;
		p = 3;
		j = 1;
		x = 0;
		j_desired = 3;
		report_hensel(deg, f, p, j, x, j_desired);
	}
	void test_hensel_5(void) {
		// x3 + x2 - 4 (7 ^ 3)
		// there is no solution mod 7
		int deg = 3;
		long long f[deg + 1], x, p, j, j_desired;
		f[0] = -4;
		f[1] = 0;
		f[2] = 1;
		f[3] = 1;
		p = 7;
		j = 1;
		// x = 3;
		j_desired = 3;
		report_hensel(deg, f, p, j, x, j_desired);
	}
	void test_hensel_6(void) {
		// x3 + x2 - 5 (7 ^ 3)
		int deg = 3;
		long long f[deg + 1], x, p, j, j_desired;
		f[0] = -5;
		f[1] = 0;
		f[2] = 1;
		f[3] = 1;
		p = 7;
		j = 1;
		x = 2;
		j_desired = 3;
		report_hensel(deg, f, p, j, x, j_desired);
	}
	test_hensel_0();
	test_hensel_1();
	test_hensel_2();
	test_hensel_3();
	test_hensel_4();
	// test_hensel_5();
	test_hensel_6();
}

void test_hensel_can_lift(void) {
	// function to test solution_can_lift
	void report_hensel(deg, f, p, j, x)
		long long f[], p, j, x;
		int deg;
	{
		int deg_der;
		long long f_der[max(0, deg)];
		derived_polynomial(deg, f, &deg_der, f_der);
		if ( is_solution(x, deg, f, p, j) ) {
			if ( solution_is_nonsingular(x, deg_der, f_der, p) ) {
				printf("%lld is a nonsingular solution mod %lld ^ %lld\n", x, p, j);
			} else {
				printf("%lld is a singular solution mod %lld ^ %lld\n", x, p, j);
			}
			if ( solution_can_lift(x, deg, f, deg_der, f_der, p, j) ) {
				printf("%lld lifts to a solution mod %lld ^ %lld\n", x, p, j+1);
			} else {
				printf("%lld is not a solution mod %lld ^ %lld\n", x, p, j+1);
			}
		} else {
			printf("%lld is not a solution mod %lld ^ %lld\n", x, p, j);
		}
	}
	void test_hensel_0(void) {
		int deg = 2;
		long long f[deg + 1], x, p, j;
		f[0] = 223;
		f[1] = 1;
		f[2] = 1;
		p = 3;
		j = 5;
		x = 4;
		report_hensel(deg, f, p, j, x);
	}
	void test_hensel_1(void) {
		int deg = 2;
		long long f[deg + 1], x, p, j;
		f[0] = 223;
		f[1] = 1;
		f[2] = 1;
		p = 3;
		j = 5;
		x = 22;
		report_hensel(deg, f, p, j, x);
	}
	void test_hensel_2(void) {
		int deg = 2;
		long long f[deg + 1], x, p, j;
		f[0] = 223;
		f[1] = 1;
		f[2] = 1;
		p = 3;
		j = 5;
		x = 49;
		report_hensel(deg, f, p, j, x);
	}
	void test_hensel_3(void) {
		int deg = 2;
		long long f[deg + 1], x, p, j;
		f[0] = 223;
		f[1] = 1;
		f[2] = 1;
		p = 3;
		j = 4;
		x = 13;
		report_hensel(deg, f, p, j, x);
	}
	void test_hensel_4(void) {
		int deg = 2;
		long long f[deg + 1], x, p, j;
		f[0] = 47;
		f[1] = 1;
		f[2] = 1;
		p = 7;
		j = 1;
		x = 1;
		report_hensel(deg, f, p, j, x);
	}
	void test_hensel_5(void) {
		int deg = 2;
		long long f[deg + 1], x, p, j;
		f[0] = 47;
		f[1] = 1;
		f[2] = 1;
		p = 7;
		j = 2;
		x = 1;
		report_hensel(deg, f, p, j, x);
	}
	void test_hensel_6(void) {
		int deg = 2;
		long long f[deg + 1], x, p, j;
		f[0] = 47;
		f[1] = 1;
		f[2] = 1;
		p = 7;
		j = 3;
		x = 99;
		report_hensel(deg, f, p, j, x);
	}
	void test_hensel_7(void) {
		int deg = 2;
		long long f[deg + 1], x, p, j;
		f[0] = 47;
		f[1] = 1;
		f[2] = 1;
		p = 7;
		j = 1;
		x = 5;
		report_hensel(deg, f, p, j, x);
	}
	// RUN TEST CASES
	test_hensel_0();
	test_hensel_1();
	test_hensel_2();
	test_hensel_3();
	test_hensel_4();
	test_hensel_5();
	test_hensel_6();
	test_hensel_7();
}
