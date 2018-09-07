#include "ZZTest/zz-test.h"
#include "TestCombinatorics.hpp"


const int precision = 5;

bool test_factorial() {
    return zztest_areEquals(ZZ::Math::Combinatorics::factorial(5), 120, precision)
        && zztest_areEquals(ZZ::Math::Combinatorics::factorial(10), 3628800, precision)
        && zztest_areEquals(ZZ::Math::Combinatorics::factorial(20), 2432902008176640000, precision)
    ;
}
bool test_arrangeReps() {
    return zztest_areEquals(
            ZZ::Math::Combinatorics::arrangeReps(3, 5),
            243,
            precision
        )
        && zztest_areEquals(
            ZZ::Math::Combinatorics::arrangeReps(30, 50),
            7.17897987691852588770249e+73,
            precision
        )
        && zztest_areEquals(
            ZZ::Math::Combinatorics::arrangeReps(50, 100),
            7.8886090522101180541172856528279e+169,
            precision
        )
    ;
}
bool test_arrangeNoReps() {
    return zztest_areEquals(
            ZZ::Math::Combinatorics::arrangeNoReps(5, 3),
            60,
            precision
        )
        && zztest_areEquals(
            ZZ::Math::Combinatorics::arrangeNoReps(50, 30),
            12501158328406121771367407631048321803845894144.0,
            precision
        )
        && zztest_areEquals(
            ZZ::Math::Combinatorics::arrangeNoReps(100, 50),
            3068518756254965995806053995506028460322292848199434614029947814704023699874918745193182134272.0,
            precision
        )
    ;
}
bool test_chooseReps() {
    return zztest_areEquals(
            ZZ::Math::Combinatorics::chooseReps(3, 5),
            21,
            precision
        )
        && zztest_areEquals(
            ZZ::Math::Combinatorics::chooseReps(30, 50),
            3326779700565170978816.00000,
            precision
        )
        && zztest_areEquals(
            ZZ::Math::Combinatorics::chooseReps(50, 100),
            6709553636577312758557068362648666505216.00000,
            precision
        )
    ;
}
bool test_chooseNoReps() {
    return zztest_areEquals(
            ZZ::Math::Combinatorics::chooseNoReps(5, 3),
            10,
            precision
        )
        && zztest_areEquals(
            ZZ::Math::Combinatorics::chooseNoReps(50, 30),
            47129212243960.007812,
            precision
        )
        && zztest_areEquals(
            ZZ::Math::Combinatorics::chooseNoReps(100, 50),
            100891344545564202071714955264.0,
            precision
        )
    ;
}