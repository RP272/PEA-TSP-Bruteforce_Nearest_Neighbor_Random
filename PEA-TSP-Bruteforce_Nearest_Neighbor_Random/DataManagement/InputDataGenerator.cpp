#include "InputDataGenerator.hpp"

InputData InputDataGenerator::generateInputData(ConfigurationData config)
{
	InputData result = { 0 };
	result.numberOfCities = config.quantityOfCities;
    result.costMatrix = new int* [result.numberOfCities];
    for (int i = 0; i < result.numberOfCities; i++)
    {
        result.costMatrix[i] = new int[result.numberOfCities];
        for (int j = 0; j < result.numberOfCities; j++) {
            if (j == i) result.costMatrix[i][j] = -1;
        }
        // Generate random 
    }

	return result;
}
