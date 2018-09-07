#pragma once

#include <math.h>
#include <stdio.h>
#include <limits.h>


// <-- Macroses -->
#define TITLE(str) printf("\x1b[1m" str "\x1b[0m\n")
#define PASSED "\x1b[32mPassed\x1b[0m"
#define FAILED "\x1b[31mFailed\x1b[0m"
#define TEST(name, method) printf( \
    "\t%s: %s\n", \
    name, \
    method() ? PASSED : FAILED \
);
// </- Macroses -->


// <-- Functions -->
#ifdef __cplusplus
extern "C" {
#endif


int zztest_areEquals(
    const double d1,
    const double d2,
    const int decimalPointsPrecision
);


#ifdef __cplusplus
}
#endif
// </- Functions -->