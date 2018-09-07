#include "zz-test.h"
#include "TestZZTest.h"

int test_areEquals() {
    const double decimalPointsPrecision = 5;
    return
        // <-- Common -->
        zztest_areEquals(12.34, 12.34, decimalPointsPrecision)
        && zztest_areEquals(-12.34, -12.34, decimalPointsPrecision)
        && !zztest_areEquals(12.34, -12.34, decimalPointsPrecision)
        && zztest_areEquals(0.0, 0.0, decimalPointsPrecision)
        && zztest_areEquals(-0.0, 0.0, decimalPointsPrecision)
        && zztest_areEquals(-0.0, -0.0, decimalPointsPrecision)

        && zztest_areEquals(12.34000, 12.34001, decimalPointsPrecision)
        && zztest_areEquals(12.34001, 12.34000, decimalPointsPrecision)
        && !zztest_areEquals(12.34000, 12.34002, decimalPointsPrecision)
        && !zztest_areEquals(12.34002, 12.34000, decimalPointsPrecision)
        // </- Common -->

        // <-- Infinity -->
        && !zztest_areEquals(
            12.34,
            INFINITY,
            decimalPointsPrecision
        )
        && !zztest_areEquals(
            INFINITY,
            12.34,
            decimalPointsPrecision
        )
        && zztest_areEquals(
            INFINITY,
            INFINITY,
            decimalPointsPrecision
        )
        && zztest_areEquals(
            -INFINITY,
            -INFINITY,
            decimalPointsPrecision
        )
        && !zztest_areEquals(
            -INFINITY,
            INFINITY,
            decimalPointsPrecision
        )
        && !zztest_areEquals(
            INFINITY,
            -INFINITY,
            decimalPointsPrecision
        )
        // </- Infinity -->
        
        // <-- Nan -->
        && !zztest_areEquals(
            12.34,
            NAN,
            decimalPointsPrecision
        )
        && !zztest_areEquals(
            NAN,
            12.34,
            decimalPointsPrecision
        )
        && !zztest_areEquals(
            NAN,
            NAN,
            decimalPointsPrecision
        )
        && !zztest_areEquals(
            NAN,
            INFINITY,
            decimalPointsPrecision
        )
        && !zztest_areEquals(
            INFINITY,
            NAN,
            decimalPointsPrecision
        )
        && !zztest_areEquals(
            NAN,
            -INFINITY,
            decimalPointsPrecision
        )
        && !zztest_areEquals(
            -INFINITY,
            NAN,
            decimalPointsPrecision
        )
        // </- Nan -->
    ;
}