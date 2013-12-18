#pragma once
#include "TrainingMethod.h"
#include "Training.h"

class TrainingMethodGradient:TrainingMethod{

public:
	void Training(Network &networkToTrain,const std::vector<double> &inputValue,const std::vector<double> &outputValue);


};