#include <iostream>
#include "ZZTest/zz-test.h"
#include "ZZTest/TestZZTest.h"
#include "Combinatorics/TestCombinatorics.hpp"


bool test_true () { return true; }
bool test_false () { return false; }

int main()
{
    TITLE("Test algorithms implementations:");

    TITLE("Test Common:");
    TEST("\tTest true", test_true);
    TEST("\tTest false", test_false);

    TITLE("Test ZZTest:");
    TEST("\tTest equals", test_areEquals);

    TITLE("Test Combinatorics:");
    TEST("\tFactorial", test_factorial);
    TEST("\tArrange w reps", test_arrangeReps);
    TEST("\tArrange w/o reps", test_arrangeNoReps);
    TEST("\tChoose w reps", test_chooseReps);
    TEST("\tChoose w/o reps", test_chooseNoReps);

    TITLE("Done");
    return 0;
}