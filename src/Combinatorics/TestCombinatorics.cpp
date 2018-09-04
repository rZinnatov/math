#include <iostream>

#include "TestCombinatorics.hpp"

bool test_factorial() {
    return
        (ZZ::Math::Combinatorics::factorial(5) == 120) &&
        (ZZ::Math::Combinatorics::factorial(10) == 3628800) &&
        (ZZ::Math::Combinatorics::factorial(20) == 2432902008176640000)
    ;
}
bool test_arrangeWithRepetitions() {
    return
        (ZZ::Math::Combinatorics::arrangeWithRepetitions(3, 5) == 243)
        && (ZZ::Math::Combinatorics::arrangeWithRepetitions(30, 50) == 7.17897987691852588770249e+73)
        && (ZZ::Math::Combinatorics::arrangeWithRepetitions(50, 100) == 7,8886090522101180541172856528279e+169)
    ;
}
bool test_arrangeWithoutRepetitions() {
    std::cout << "arrangeWithoutRepetitions(5, 3) = " << ZZ::Math::Combinatorics::arrangeWithoutRepetitions(5, 3) << std::endl;
    std::cout << "arrangeWithoutRepetitions(50, 30) = " << (ZZ::Math::Combinatorics::arrangeWithoutRepetitions(50, 30) == 1.25012e+46) << std::endl;
    std::cout << "arrangeWithoutRepetitions(100, 50) = " << (ZZ::Math::Combinatorics::arrangeWithoutRepetitions(100, 50) == 3.06852e+93) << std::endl;
    return
        (ZZ::Math::Combinatorics::arrangeWithoutRepetitions(5, 3) == 60) &&
        (ZZ::Math::Combinatorics::arrangeWithoutRepetitions(50, 30) == 1.25012e+46) &&
        (ZZ::Math::Combinatorics::arrangeWithoutRepetitions(100, 50) == 3.06852e+93)
    ;
}
bool test_chooseWithRepetitions() {
    return
        (ZZ::Math::Combinatorics::chooseWithRepetitions(3, 5) == 84) &&
        (ZZ::Math::Combinatorics::chooseWithRepetitions(30, 50) == 9.5819694105875247169048764500886e+53) &&
        (ZZ::Math::Combinatorics::chooseWithRepetitions(50, 100) == 2.4825806457049290738310640896637e+165)
    ;
}
bool test_chooseWithoutRepetitions() {
    return
        (ZZ::Math::Combinatorics::chooseWithoutRepetitions(5, 3) == 360) &&
        (ZZ::Math::Combinatorics::chooseWithoutRepetitions(50, 30) == 3.315967997574713330783446409775e+78) &&
        (ZZ::Math::Combinatorics::chooseWithoutRepetitions(100, 50) == 9.3326215443944152681699238856267e+157)
    ;
}