#pragma once
#include "Neuron.h"



class Network{

public:
	Network(const std::vector<unsigned> &topology);
	void feedForward(const std::vector<double> &inputVals);
	void backProp(const std::vector<double> &targetVals){};
	void getResults(std::vector<double> &resultVals)const{};
private:
	std::vector <Layer> m_layers;
	double m_error;
	double m_recentAverageError;
	double m_recentAverageSmoothingFactor;
};