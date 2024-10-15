#ifndef CONFIGURATIONDATA_HPP
#define CONFIGURATIONDATA_HPP

struct ConfigurationData
{
	// 0 - read from input_file.txt. In this case the TSP algorithm is run only once.
	// 1 - generate random matrix. In this case 'whichAlgorithm' is not used. 
	//	   The generated matrix is used by all 3 algorithms.
	int readOrGenerateData;
	// 0 - Bruteforce. 1 - Nearest neighbor. 2 - Random
	int whichAlgorithm; 
	int quantityOfCities;
	int quantityOfMeasurements;
	// 0 - symmetric.
	// 1 - asymmetric.
	int asymmetricOrSymmetric;
};

#endif
