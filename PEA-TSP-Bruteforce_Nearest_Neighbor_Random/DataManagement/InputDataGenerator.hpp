#ifndef INPUTDATAGENERATOR_HPP
#define INPUTDATAGENERATOR_HPP
#include "InputData.hpp"
#include "ConfigurationData.hpp"

class InputDataGenerator
{
public:
	static InputData generateInputData(ConfigurationData config);
};

#endif

