// PEA-TSP-Bruteforce_Nearest_Neighbor_Random.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "FileReader/FileReader.hpp"
#include "TSP/BruteForce.hpp";
#include <chrono>


int main()
{
    ConfigurationData configurationData = FileReader::readConfigurationDataFile();
    std::chrono::duration<float, std::milli> timer;

    if (configurationData.readOrGenerateData == 0) {
        // Read data from input_file.txt.
        InputData inputData = FileReader::readInputDataFile();
        int minimumCost;
        switch (configurationData.whichAlgorithm) {
            case 0: {
                // Bruteforce
                auto t1 = std::chrono::high_resolution_clock::now();
                minimumCost = BruteForce::permutationGeneration(inputData);
                auto t2 = std::chrono::high_resolution_clock::now();
                timer = t2 - t1;
                std::cout << "czas generowania permutacji: " << timer.count() << std::endl;
                std::cout << "minimalny koszt sciezki TSP: " << minimumCost << std::endl;
                break;
            }
            case 1: {
                // Nearest neighbor
                break;
            }
            case 2: {
                // Random
                break;
            }
        }
    }
    else if (configurationData.readOrGenerateData == 1) {
        // Generate matrix and make measurements.
        InputData inputData = 
        if (configurationData.asymmetricOrSymmetric == 0) {
            // Generate symmetric matrix.

            // Run bruteforce
            // Run nearest neighbor
            // Run random
        }
        else if (configurationData.asymmetricOrSymmetric == 1) {
            // Generate asymmetric matrix.

            // Run bruteforce
            // Run nearest neighbor
            // Run random
        }
    }
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
