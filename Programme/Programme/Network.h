#pragma once
#include "Neuron.h"



class Network{
	typedef std::vector<Neuron> Layer;
public:
	Network(const std::vector<unsigned> &architecture,const TransfertFunction &transfertFunction);
	void feedForwardNetwork(const std::vector<double> &inputVals);
	void backPropNetwork(const std::vector<double> &targetVals);
	void getResultsNetwork(std::vector<double> &resultVals);
private:
	std::vector <Layer> m_layers;
	double m_error;
	double m_recentAverageError;
	double m_recentAverageSmoothingFactor;
};