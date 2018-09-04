#include <iostream>
#include "Combinatorics/TestCombinatorics.hpp"

#define TITLE(str) std::cout \
    << "\x1b[1m" << str << "\x1b[0m" \
    << std::endl \
;
#define PASSED "\x1b[32mPassed\x1b[0m"
#define FAILED "\x1b[31mFailed\x1b[0m"
#define TEST(name, method) std::cout \
    << name << ": " \
    << (method() ? PASSED : FAILED) \
    << std::endl \
;

bool test_true () { return true; }
bool test_false () { return false; }
int main()
{
    TITLE("Test algorithms implementations:");

    TEST("Test true", test_true);
    TEST("Test false", test_false);

    TITLE("Test Combinatorics:");
    TEST("\tFactorial", test_factorial);
    TEST("\tArrange w reps", test_arrangeWithRepetitions);
    TEST("\tArrange w/o reps", test_arrangeWithoutRepetitions);
    TEST("\tChoose w reps", test_chooseWithRepetitions);
    TEST("\tChoose w/o reps", test_chooseWithoutRepetitions);

    TITLE("Done");
    return 0;
}