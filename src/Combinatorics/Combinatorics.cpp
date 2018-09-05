#include "Combinatorics.hpp"

#include <cmath>

double ZZ::Math::Combinatorics::factorial(int n) {
	if (n < 2) {
		return 1;
	}

	return n * factorial(n - 1);
}
double ZZ::Math::Combinatorics::arrangeReps(int n, int k) {
	return pow(n, k);
}
double ZZ::Math::Combinatorics::arrangeNoReps(int n, int k) {
	double numberOfPermutations = 1;
 
	for (double i = n; i > n - k; i--) {
		numberOfPermutations *= i;
	}
 
	return numberOfPermutations;
}
double ZZ::Math::Combinatorics::chooseNoReps(int n, int k) {
	return arrangeNoReps(n, k) / factorial(k);
}
double ZZ::Math::Combinatorics::chooseReps(int n, int k) {
	return chooseNoReps(n + k - 1, k);
}