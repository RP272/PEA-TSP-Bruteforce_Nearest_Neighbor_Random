#include "BruteForce.hpp"
#include <iostream>

void BruteForce::swap(int* a, int* b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void BruteForce::swap(bool* a, bool* b)
{
	bool tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

int BruteForce::getLargestMobile(int* currentPermutation, bool* directions, int n)
{
	int largestMobileIndex = -1;
	int largestMobileValue = 0;
	int neighborIndex;
	bool direction;
	for (int i = 0; i < n; i++) {
		neighborIndex = -1;
		direction = directions[i];
		if (direction == false && i - 1 >= 0)
			neighborIndex = i - 1;
		else if (direction == true && i + 1 < n)
			neighborIndex = i + 1;
		if (neighborIndex != -1 && currentPermutation[i] > currentPermutation[neighborIndex] && currentPermutation[i] > largestMobileValue) {
			largestMobileIndex = i;
			largestMobileValue = currentPermutation[largestMobileIndex];
		}
	}
	return largestMobileIndex;
}

int BruteForce::calculateShortestPath(InputData data)
{
	// This method uses Johnson-Trotter permutation generation algorithm.
	// Foreach permutation the total path length is calculated.
	// The length of the shortest path is returned.

	// If direction is false it is pointing left, else it is pointing right.

	// After tests unfortunatelly my implementation of Johnson-Trotter algorithm is much slower than the other permutation generation algorithm.

	bool* directions = new bool[data.numberOfCities];
	int* permutation = new int[data.numberOfCities];
	for (int i = 0; i < data.numberOfCities; i++) {
		directions[i] = false;
		permutation[i] = i+1;
	}
	int counter = 1;
	int largestMobileIndex, neighborIndex;
	largestMobileIndex = getLargestMobile(permutation, directions, data.numberOfCities);
	while (largestMobileIndex != -1) {
		if (directions[largestMobileIndex] == false) neighborIndex = largestMobileIndex - 1;
		else if (directions[largestMobileIndex] == true) neighborIndex = largestMobileIndex + 1;
		swap(&permutation[largestMobileIndex], &permutation[neighborIndex]);
		swap(&directions[largestMobileIndex], &directions[neighborIndex]);
		for (int i = 0; i < data.numberOfCities; i++) {
			if (permutation[i] > permutation[neighborIndex]) directions[i] = !directions[i];
		}
		counter++;
		largestMobileIndex = getLargestMobile(permutation, directions, data.numberOfCities);
	}
	std::cout << "number of permutations: " << counter << std::endl;
	return 0;
}

int BruteForce::calculatePermutationCost(int* cities, InputData data)
{
	int cost = 0;
	for (int i = 0; i < data.numberOfCities - 1; i++) cost += data.costMatrix[cities[i]][cities[i + 1]];
	cost += data.costMatrix[cities[data.numberOfCities - 1]][cities[0]];
	return cost;
}

int BruteForce::permutationGeneration(InputData data)
{
	int largestJ, smallestK, minimum, cost;
	minimum = INT_MAX;
	cost = 0;
	int* cities = new int[data.numberOfCities];
	for (int i = 0; i < data.numberOfCities; i++) cities[i] = i;
	cost = calculatePermutationCost(cities, data);
	if (cost < minimum) minimum = cost;

	while (true) {
		largestJ = -1;
		for (int j = 0; j < data.numberOfCities - 1; j++) {
			if (cities[j] < cities[j + 1]) {
				largestJ = j;
			}
		}
		if (largestJ == -1) {
			break;
		}

		smallestK = largestJ + 1;
		for (int k = largestJ + 1; k < data.numberOfCities; k++) {
			if (cities[k] < cities[smallestK] && cities[k] > cities[largestJ]) {
				smallestK = k;
			}
		}
		swap(&cities[largestJ], &cities[smallestK]);

		for (int i = 0; i < (data.numberOfCities - (largestJ + 1)) / 2; i++) {
			swap(&cities[largestJ + 1 + i], &cities[data.numberOfCities - 1 - i]);
		}
		
		// Calculate permutation path cost.
		cost = calculatePermutationCost(cities, data);
		if (cost < minimum) minimum = cost;
	}
	return minimum;
}