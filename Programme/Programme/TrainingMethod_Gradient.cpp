#include "TrainingMethod_Gradient.h"

//double TrainingMethod_Gradient::m_eta = 0.15; //overall net learning rate
//double TrainingMethod_Gradient::m_alpha = 0.5; // momentum, multiplier o last deltaweight



TrainingMethod_Gradient::TrainingMethod_Gradient(const double alpha,const double eta){
	m_eta=eta;
	m_alpha=alpha;

};



//Main Function called when we want to train a network with ONE sample of input and output
void TrainingMethod_Gradient::Training(Network &networkToTrain,const std::vector<double> &inputValue,
									   const std::vector<double> &outputValue){
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
	};

void TrainingMethod_Gradient::TrainALayer(){
};

void TrainingMethod_Gradient::TrainANeuron(){
};