#include "TSP.hpp"
#include <climits>
#include <iostream>
#include <chrono>
#include <algorithm>
#include <string>

void TSP::swap(int* a, int* b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void TSP::lexicographicPermutation(int numberOfCities, int** costMatrix)
{
	int largestJ, smallestK, counter;
	int* cities = new int[numberOfCities];
	for (int i = 0; i < numberOfCities; i++) cities[i] = i;
	counter = 0;
	while(true){
		largestJ = -1;
		for (int j = 0; j < numberOfCities - 1; j++) {
			if (cities[j] < cities[j + 1]) {
				largestJ = j;
			}
		}
		if (largestJ == -1) {
			counter++;
			break;
		}

		smallestK = largestJ + 1;
		for (int k = largestJ + 1; k < numberOfCities; k++) {
			if (cities[k] < cities[smallestK] && cities[k] > cities[largestJ]) {
				smallestK = k;
			}
		}
		swap(&cities[largestJ], &cities[smallestK]);
		
		for (int i = 0; i < (numberOfCities-(largestJ+1))/2; i++) {
			swap(&cities[largestJ+1+i], &cities[numberOfCities - 1 - i]);
		}
		counter++;
	}
	std::cout << counter << std::endl;
}

void TSP::permute(int* cities, int l, int r, int n, int* minimum, int** costMatrix)
{
	if (l == r)
	{
		// Calculate TSP path length
		int cost = 0;
		int j;
		for (j = 1; j < n; j++) {
			cost += costMatrix[cities[j-1]][cities[j]];
		}
		cost += costMatrix[cities[j-1]][cities[0]];
		if (cost < *minimum) {
			*minimum = cost;
		}
	}
	else
	{
		for (int i = l; i <= r; i++)
		{
			swap((cities + l), (cities + i));
			permute(cities, l + 1, r, n, minimum, costMatrix);
			swap((cities + l), (cities + i));
		}
	}
}

int TSP::rollingSwap(int* cities, int n, int** costMatrix)
{
	int minimum = INT_MAX;
	int x = 1;
	unsigned long long int counter = 0;
	for (int i = 1; i <= n ; i++)
	{
		x = x * i;
	}
	int a;
	while (x > 0)
	{
		a = n - 1;
		while (a > 0)
		{
			swap(&cities[a], &cities[a - 1]);
			a = (a - 1) % n;
			x = x - 1;
			
			// Calculate cost
			counter++;
		}
	}
	std::cout << "counter: " << counter << std::endl;

	return minimum;
}

void TSP::permuteAlgorithm(std::string s)
{
	int counter = 0;
	do
	{
		//std::cout << s << '\n';
		counter++;
	} while (std::next_permutation(s.begin(), s.end()));
	std::cout << counter << std::endl;
}



void TSP::JohnsonTrotterPermutationGeneration(int n, int** costMatrix)
{
	// If direction is false it is pointing left, else it is pointing right.
	bool* direction = new bool[n];
	int* permutation = new int[n];
	for (int i = 0; i < n; i++) {
		direction[i] = false;
		permutation[i] = i;
	}
	
	/*int minimumPath = INT_MAX;
	int cost = 0;
	for (int i = 0; i < n; i++) {
		cost += costMatrix[i][i+1];
	}*/


}

int TSP::bruteForce(InputData data)
{
	int minimum = INT_MAX;
	int* cities = new int[data.numberOfCities];
	for (int i = 0; i < data.numberOfCities; i++) {
		cities[i] = i;
	}
	//permute(cities, 0, data.numberOfCities - 1, data.numberOfCities, &minimum, data.costMatrix);
	auto t1 = std::chrono::high_resolution_clock::now();
	//lexicographicPermutation(cities, data.numberOfCities, data.costMatrix);
	TSP::permuteAlgorithm("ABCDEFGHIJKPZX");
	auto t2 = std::chrono::high_resolution_clock::now();
	auto ms_int = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
	std::cout << "czas generowania permutacji: " << ms_int.count() << std::endl;
	//rollingSwap(cities, data.numberOfCities, data.costMatrix);
	return minimum;
}

int TSP::nearestNeighbor(InputData data)
{
	return 0;
}

int TSP::random(InputData data)
{
	return 0;
}
