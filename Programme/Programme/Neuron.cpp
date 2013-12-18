#include "Neuron.h"

double Neuron::eta = 0.15; //overall net learning rate
double Neuron::alpha = 0.5; // momentum, multiplier o last deltaweight



Neuron::Neuron(unsigned numOutputs,unsigned myIndex){
	for(unsigned c=0;c<numOutputs;++c){
		m_outputWeights.push_back(Connection());
		m_outputWeights.back().weight=randomWeight();
	}

	m_myIndex = myIndex;
}




void Neuron::updateInputWeights(Layer &prevLayer){
	// The weights to be updated are in the connection container
	// In the neuron in the preceding layer

	for( unsigned n = 0; n < prevLayer.size(); ++n){
		Neuron &neuron=prevLayer[n];
		double oldDeltaWeight = neuron.m_outputWeights[m_myIndex].deltaWeight;

		double newDeltaWeight =
			// Individaul input, magnified by the gradient and train rate:
			eta 
			* neuron.getOutputVal()
			* m_gradient
			// Also add momentum = a fraction of the previous delta weight
			+ alpha
			* oldDeltaWeight;

		neuron.m_outputWeights[m_myIndex].deltaWeight = newDeltaWeight;
		neuron.m_outputWeights[m_myIndex].weight += newDeltaWeight;

	}
}

double Neuron::sumDOW(const Layer &nextLayer) const{
	double sum = 0;

	// sum our contribution of the erros at the nodes we feed

	for (unsigned n = 0; n < nextLayer.size() - 1;++n){
		sum += m_outputWeights[n].weight * nextLayer[n].m_gradient;
	}

	return sum;
}
void Neuron::calcHiddenGradients(const Layer &nextLayer){
	double dow = sumDOW(nextLayer);
	m_gradient= dow * Neuron::transfertFunctionDerivative(m_outputVal);
}

void Neuron::calcOutputGradients(double targetVal){
	double delta=targetVal - m_outputVal;
	m_gradient = delta * Neuron::transfertFunctionDerivative(m_outputVal);

}

double Neuron::transfertFunction(double x){
	return tanh(x);
}

double Neuron::transfertFunctionDerivative(double x){
	return 1-x*x;
}

void Neuron::feedForward(const Layer &prevLayer){
	double sum=0.0;

	for(unsigned n = 0; n < prevLayer.size();++n){
		sum+=prevLayer[n].getOutputVal() * prevLayer[n].m_outputWeights[m_myIndex].weight;
	}

	m_outputVal = Neuron::transfertFunction(sum);
}


