#pragma once;
#include <vector>
#include "Connection.h"
#include "TransfertFunction.h"




class Neuron{
	typedef std::vector<Neuron> Layer;
public:

	Neuron(unsigned numOutputs,unsigned myIndex, const TransfertFunction &f);
	~Neuron();
	void setOutputVal(double val){ m_outputVal = val;}
	double getOutputVal(void) const { return m_outputVal;}
	void feedForwardNeuron(const Layer &prevLayer);
	void calcOutputGradients(double targetVal);
	void calcHiddenGradients(const Layer &nextLayer);
	void updateInputWeights(std::vector<Connection> newInputWeights);

private:

	static double randomWeight(void){ return rand()/ double(RAND_MAX);};
	TransfertFunction* m_transfertFunction;
	double m_outputVal;
	double sumDOW(const Layer &nextLayer) const;
	std::vector<Connection> m_outputWeights;
	unsigned m_myIndex;
	double m_gradient;

};

