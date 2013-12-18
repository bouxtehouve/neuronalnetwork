#pragma once;
#include <vector>
#include "Connection.h"

typedef std::vector<Neuron> Layer;



class Neuron{

public:
	Neuron(unsigned numOutputs,unsigned myIndex);
	void setOutputVal(double val){ m_outputVal = val;}
	double getOutputVal(void) const { return m_outputVal;}
	void feedForward(const Layer &prevLayer);
	void calcOutputGradients(double targetVal);
	void calcHiddenGradients(const Layer &nextLayer);
	void updateInputWeights(Layer &prevLayer);

private:
	static double eta;
	static double alpha;
	static double transfertFunction(double x);
	static double transfertFunctionDerivative(double x);
	static double randomWeight(void){ return rand()/ double(RAND_MAX);}
	double m_outputVal;
	double sumDOW(const Layer &nextLayer) const;
	std::vector<Connection> m_outputWeights;
	unsigned m_myIndex;
	double m_gradient;

};