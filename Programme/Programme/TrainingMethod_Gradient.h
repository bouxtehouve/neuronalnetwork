#pragma once
#include "TrainingMethod.h"
#include "Training.h"

class TrainingMethod_Gradient:TrainingMethod{

public:
	TrainingMethod_Gradient(const double alphan,const double eta);

	void Training(Network &networkToTrain,const std::vector<double> &inputValue,
		const std::vector<double> &outputValue);
	void TrainALayer();
	void TrainANeuron();
	static double m_eta;
	static double m_alpha;


};

