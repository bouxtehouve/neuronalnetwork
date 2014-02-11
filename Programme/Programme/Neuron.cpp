#include "Neuron.h"
using namespace std;



Neuron::Neuron(unsigned numOutputs, unsigned myIndex, const Transfert f){
	for (unsigned c = 0; c<numOutputs; ++c){
		m_outputWeights.push_back(Connection());
		m_outputWeights.back().weight = randomWeight();
	}
	//m_transfertFunction = f;
	m_myIndex = myIndex;
	m_transfertFunction = f;
}


Neuron::~Neuron(){
	m_outputWeights.empty();
	delete(&m_transfertFunction);
}


// This function is called by the TrainingMethod
void Neuron::updateInputWeights(Layer prevLayer, double eta, double alpha){
	// 	The weights to be updated are in the Connection container
	// in the neurons in the preceding layer
	for (unsigned n = 0; n < prevLayer.size(); n++){
		Neuron &neuron = prevLayer[n];
		Connection &conn = neuron.m_outputWeights[m_myIndex];

		double oldDeltaWeight = conn.deltaWeight;
		double newDeltaWeight =
			// Individual input, magnified by the gradient and train rate:
			eta
			* neuron.m_outputVal
			* neuron.m_gradient
			// Also add momentum = a fraction of the previous delta weight;
			+ alpha
			* oldDeltaWeight;

		conn.deltaWeight = newDeltaWeight;
		conn.weight += newDeltaWeight;
	}
}


double Neuron::sumDOW(const Layer &nextLayer){

	double sum = 0;

	// sum our contribution of the errors at the nodes we feed
	for (unsigned n = 0; n < nextLayer.size() - 1; ++n){
		sum += m_outputWeights[n].weight * nextLayer[n].m_gradient;
	}

	return sum;
}

void Neuron::calcHiddenGradients(const Layer &nextLayer){
	double dow = sumDOW(nextLayer);
	TransfertFunction t;
	m_gradient = dow * t.value(m_outputVal,m_transfertFunction);
}

void Neuron::calcOutputGradients(double targetVal){
	double delta = targetVal - m_outputVal;
	TransfertFunction t;
	m_gradient = delta * t.derivative(m_outputVal, m_transfertFunction);

}



// Function called to update the output of a Neuron according to the outputweight of
// the previous layer
void Neuron::feedForwardNeuron(const Layer &prevLayer){
	double sum = 0.0;

	for (unsigned n = 0; n < prevLayer.size(); ++n){
		sum += prevLayer[n].getOutputVal() * prevLayer[n].m_outputWeights[m_myIndex].weight;
	}
	TransfertFunction t;
	m_outputVal = t.value(sum, m_transfertFunction);
}


