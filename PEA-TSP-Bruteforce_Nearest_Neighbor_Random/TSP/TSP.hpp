#ifndef TSP_HPP
#define TSP_HPP
#include <string>

#include "../FileReader/InputData.hpp"

class TSP
{
public:
	static void JohnsonTrotterPermutationGeneration(int n, int** costMatrix);
	static void permute(int* a, int l, int r, int n, int* minimum, int** costMatrix);
	static void permuteAlgorithm(std::string s);
	static void lexicographicPermutation(int numberOfCities, int** costMatrix);
	static int rollingSwap(int* cities, int n, int** costMatrix);
	static void swap(int* a, int* b);
	static int bruteForce(InputData data);
	static int nearestNeighbor(InputData data);
	static int random(InputData data);
};

#endif

