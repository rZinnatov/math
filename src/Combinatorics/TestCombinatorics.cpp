#include <cmath>
#include <limits>
#include <iostream>

#include "TestCombinatorics.hpp"

double round(const double d)
{
    if (d < 0 ) {
        return std::ceil(d - 0.5);
    }
    return std::floor(d + 0.5);
}
bool areEquals(const double d1, const double d2, const int decimalPointsPrecision) {
    if (std::isnan(d1) || std::isnan(d2)) {
        return false;
    }
    if (d1 == std::numeric_limits<double>::infinity()) {
        return d2 == std::numeric_limits<double>::infinity();
    }
    if (d1 == -std::numeric_limits<double>::infinity()) {
        return d2 == -std::numeric_limits<double>::infinity();
    }

    const double pointShift = std::pow(10, decimalPointsPrecision);
    const double d1Rounded = round(d1 * pointShift) / pointShift;
    const double d2Rounded = round(d2 * pointShift) / pointShift;

    const double precision = 1 / pointShift;
    return std::abs(d1Rounded - d2Rounded) <= precision;
}
bool test_equals() {
    const double decimalPointsPrecision = 5;
    return
        // <-- Common -->
        areEquals(12.34, 12.34, decimalPointsPrecision)
        && areEquals(-12.34, -12.34, decimalPointsPrecision)
        && !areEquals(12.34, -12.34, decimalPointsPrecision)
        && areEquals(0.0, 0.0, decimalPointsPrecision)
        && areEquals(-0.0, 0.0, decimalPointsPrecision)
        && areEquals(-0.0, -0.0, decimalPointsPrecision)

        && areEquals(12.34000, 12.34001, decimalPointsPrecision)
        && areEquals(12.34001, 12.34000, decimalPointsPrecision)
        && !areEquals(12.34000, 12.34002, decimalPointsPrecision)
        && !areEquals(12.34002, 12.34000, decimalPointsPrecision)
        // </- Common -->

        // <-- Infinity -->
        && !areEquals(12.34, std::numeric_limits<double>::infinity(), decimalPointsPrecision)
        && !areEquals(std::numeric_limits<double>::infinity(), 12.34, decimalPointsPrecision)
        && areEquals(std::numeric_limits<double>::infinity(), std::numeric_limits<double>::infinity(), decimalPointsPrecision)
        && areEquals(-std::numeric_limits<double>::infinity(), -std::numeric_limits<double>::infinity(), decimalPointsPrecision)
        && !areEquals(-std::numeric_limits<double>::infinity(), std::numeric_limits<double>::infinity(), decimalPointsPrecision)
        && !areEquals(std::numeric_limits<double>::infinity(), -std::numeric_limits<double>::infinity(), decimalPointsPrecision)
        // </- Infinity -->
        
        // <-- Nan -->
        && !areEquals(12.34, std::numeric_limits<double>::quiet_NaN(), decimalPointsPrecision)
        && !areEquals(std::numeric_limits<double>::quiet_NaN(), 12.34, decimalPointsPrecision)
        && !areEquals(std::numeric_limits<double>::quiet_NaN(), std::numeric_limits<double>::quiet_NaN(), decimalPointsPrecision)
        && !areEquals(std::numeric_limits<double>::quiet_NaN(), std::numeric_limits<double>::infinity(), decimalPointsPrecision)
        && !areEquals(std::numeric_limits<double>::infinity(), std::numeric_limits<double>::quiet_NaN(), decimalPointsPrecision)
        && !areEquals(std::numeric_limits<double>::quiet_NaN(), -std::numeric_limits<double>::infinity(), decimalPointsPrecision)
        && !areEquals(-std::numeric_limits<double>::infinity(), std::numeric_limits<double>::quiet_NaN(), decimalPointsPrecision)
        // </- Nan -->
    ;
}

const int precision = 5;

bool test_factorial() {
    return areEquals(ZZ::Math::Combinatorics::factorial(5), 120, precision) &&
        areEquals(ZZ::Math::Combinatorics::factorial(10), 3628800, precision) &&
        areEquals(ZZ::Math::Combinatorics::factorial(20), 2432902008176640000, precision)
    ;
}
bool test_arrangeWithRepetitions() {
    return areEquals(ZZ::Math::Combinatorics::arrangeWithRepetitions(3, 5), 243, precision)
        && areEquals(ZZ::Math::Combinatorics::arrangeWithRepetitions(30, 50), 7.17897987691852588770249e+73, precision)
        && areEquals(ZZ::Math::Combinatorics::arrangeWithRepetitions(50, 100), 7.8886090522101180541172856528279e+169, precision)
    ;
}
bool test_arrangeWithoutRepetitions() {
    return areEquals(ZZ::Math::Combinatorics::arrangeWithoutRepetitions(5, 3), 60, precision)
        && areEquals(ZZ::Math::Combinatorics::arrangeWithoutRepetitions(50, 30), 1.25012e+46, precision)
        && areEquals(ZZ::Math::Combinatorics::arrangeWithoutRepetitions(100, 50), 3.06852e+93, precision)
    ;
}
bool test_chooseWithRepetitions() {
    return areEquals(ZZ::Math::Combinatorics::chooseWithRepetitions(3, 5), 84, precision)
        && areEquals(ZZ::Math::Combinatorics::chooseWithRepetitions(30, 50), 9.5819694105875247169048764500886e+53, precision)
        && areEquals(ZZ::Math::Combinatorics::chooseWithRepetitions(50, 100), 2.4825806457049290738310640896637e+165, precision)
    ;
}
bool test_chooseWithoutRepetitions() {
    return areEquals(ZZ::Math::Combinatorics::chooseWithoutRepetitions(5, 3), 360, precision)
        && areEquals(ZZ::Math::Combinatorics::chooseWithoutRepetitions(50, 30), 3.315967997574713330783446409775e+78, precision)
        && areEquals(ZZ::Math::Combinatorics::chooseWithoutRepetitions(100, 50), 9.3326215443944152681699238856267e+157, precision)
    ;
}