#ifndef TSP_HPP
#define TSP_HPP
#include "../DataManagement/InputData.hpp"

class BruteForce
{
public:
	static int calculateShortestPath(InputData data);
	static int getLargestMobile(int* currentPermutation, bool* directions, int n);
	static int permutationGeneration(InputData data);
	static int calculatePermutationCost(int* cities, InputData data);
	static void swap(int* a, int* b);
	static void swap(bool* a, bool* b);
};

#endif