#include "Neuron.h"
using namespace std;



Neuron::Neuron(unsigned numOutputs,unsigned myIndex,const TransfertFunction &f){
	for(unsigned c=0;c<numOutputs;++c){
		m_outputWeights.push_back(Connection());
		m_outputWeights.back().weight=randomWeight();
	}
	m_transfertFunction=&f;
	m_myIndex = myIndex;
}


Neuron::~Neuron(){
	m_outputWeights.empty;
	m_transfertFunction=0;
}


// This function is called by the TrainingMethod
void Neuron::updateInputWeights(vector<Connection> newInputWeights){
	for( unsigned n = 0; n < m_outputWeights.size(); ++n){
		m_outputWeights[n]=newInputWeights[n];
	}
}

double Neuron::sumDOW(const Layer &nextLayer) const{
	double sum = 0;

	// sum our contribution of the errors at the nodes we feed

	for (unsigned n = 0; n < nextLayer.size() - 1;++n){
		sum += m_outputWeights[n].weight * nextLayer[n].m_gradient;
	}

	return sum;
}

void Neuron::calcHiddenGradients(const Layer &nextLayer){
	double dow = sumDOW(nextLayer);
	m_gradient= dow * m_transfertFunction->value(m_outputVal);
}

void Neuron::calcOutputGradients(double targetVal){
	double delta=targetVal - m_outputVal;
	m_gradient = delta * m_transfertFunction->derivative(m_outputVal);

}



// Function called to update the output of a Neuron according to the outputweight of
// the previous layer
void Neuron::feedForwardNeuron(const Layer &prevLayer){
	double sum=0.0;

	for(unsigned n = 0; n < prevLayer.size();++n){
		sum+=prevLayer[n].getOutputVal() * prevLayer[n].m_outputWeights[m_myIndex].weight;
	}

	m_outputVal = m_transfertFunction->value(sum);
}


