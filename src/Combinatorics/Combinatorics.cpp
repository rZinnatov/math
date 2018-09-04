#include "Combinatorics.hpp"

#include <cmath>

double ZZ::Math::Combinatorics::factorial(int n) {
	if (n < 2) {
		return 1;
	}

	return n * factorial(n - 1);
}
double ZZ::Math::Combinatorics::arrangeWithRepetitions(int n, int k) {
	return pow(n, k);
}
double ZZ::Math::Combinatorics::arrangeWithoutRepetitions(int n, int k) {
	double numberOfPermutations = 1;
 
	for (double i = n; i > n - k; i--) {
		numberOfPermutations *= i;
	}
 
	return numberOfPermutations;
}
double ZZ::Math::Combinatorics::chooseWithoutRepetitions(int n, int k) {
	return arrangeWithoutRepetitions(n, k) / factorial(k);
}
double ZZ::Math::Combinatorics::chooseWithRepetitions(int n, int k) {
	return chooseWithoutRepetitions(n + k - 1, k);
}