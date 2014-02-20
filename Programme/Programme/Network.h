#pragma once
#include "Neuron.h"
#include "TransfertFunction.h"

class Network{
	typedef std::vector<Neuron> Layer;
public:
	//Network(const std::vector<unsigned> &architecture, const TransfertFunction &transfertFunction,Parameters p);
	Network(double eta, double alpha, Transfert choice);
	void feedForwardNetwork(const std::vector<double> &inputVals);
	void backPropNetwork(const std::vector<double> &targetVals);
	void getResultsNetwork(std::vector<double> &resultVals);
	int interpretResults(std::vector<double> &resultVals);

	void training(const std::vector<std::vector<double> > &inputValsTab, const std::vector<std::vector<double> > &outputValsTab);
	void singleTraining(const std::vector<double> &inputVals, const std::vector<double> &outputVals);

	std::vector <Layer> m_layers;
	double m_error;
	double m_recentAverageError;
	double m_recentAverageSmoothingFactor;
	double m_eta;
	double m_alpha;
	Transfert m_transfertFunction;

};
