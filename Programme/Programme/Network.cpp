#include "Network.h"

using namespace std;

Network::Network(double eta, double alpha, Transfert choice){
	m_eta = eta;
	m_alpha = alpha;
	m_transfertFunction = choice;
	m_error_testing = 0;
	m_count = 0;
	m_count_error = 0;
	
	vector<unsigned> architecture;
	architecture.push_back(784);		// 784=number of pixels
	architecture.push_back(500);
	architecture.push_back(10);			// 10=number of digits (10)

	unsigned numLayers = architecture.size();
	for (unsigned layerNum = 0; layerNum < numLayers; ++layerNum){
		m_layers.push_back(Layer());
		unsigned numOutputs = layerNum == architecture.size() - 1 ? 0 : architecture[layerNum + 1];
		for (unsigned neuronNum = 0; neuronNum <= architecture[layerNum]; ++neuronNum){
			m_layers.back().push_back(Neuron(numOutputs, neuronNum, m_transfertFunction));
		}
	}
}


void Network::training(const std::vector<std::vector<double> > &inputValsTab, const std::vector<std::vector<double> > &outputValsTab){

	for (int i = 0; i < inputValsTab.size()-1; i++){
		Network::singleTraining(inputValsTab[i], outputValsTab[i]);
	}

}


void Network::singleTraining(const std::vector<double> &inputVals, const std::vector<double> &outputVals){
	// Get new input data and feed it forward:
	Network::feedForwardNetwork(inputVals);
	// Collect the net's actual output results:
	//Network::getResultsNetwork(resultValues);

	// Train the net what the outputs should have been:
	Network::backPropNetwork(outputVals);
	// Report how well the training is working, average over recent samples:
	std::cout << m_recentAverageError << "\n" << endl;
}

//This function sends the output value obtained by the neuron network with the last inputs entered
void Network::getResultsNetwork(vector<double> &resultVals){
	resultVals.clear();
	for (unsigned n = 0; n < m_layers.back().size() - 1; ++n){
		resultVals.push_back(m_layers.back()[n].getOutputVal());
	}
}

int Network::interpretResults(std::vector<double> &resultVals){
	int pos = 0;
	int max = resultVals[0];
	for (unsigned n =0; n < resultVals.size()-1; ++n)
	{
		if (resultVals[n] > max)
		{
			pos = n;
			max = resultVals[n];
		}
	}
	return pos;
}


//This function updates the output values for each neuron in each layer according
//to a set of input values
void Network::feedForwardNetwork(const vector<double> &inputVals){

	//Assign the input values into the input neurons
	for (unsigned i = 0; i<inputVals.size()-1; ++i){
		m_layers[0][i].setOutputVal(inputVals[i]);
	}

	//Forward propragate
	for (unsigned layerNum = 1; layerNum < m_layers.size()-1; ++layerNum){
		Layer &prevLayer = m_layers[layerNum - 1];
		for (unsigned n = 0; n< m_layers[layerNum].size() - 1; ++n){
			m_layers[layerNum][n].feedForwardNeuron(prevLayer);
		}
	}
}

void Network::singleTesting(const std::vector<double> &inputVals, int &wanted_digit){
	m_count += 1;
	Network::feedForwardNetwork(inputVals);
	std::vector<double> resultVals;
	Network::getResultsNetwork(resultVals);
	int result = Network::interpretResults(resultVals);
	if (result != wanted_digit){
		m_count_error += 1;
		m_error_testing = m_count_error / m_count;
	}
}

void Network::consoleTesting()
{
	m_count = 0;
	gestion_data data;
	vector <vector<double> > images = data.images_data("test");
	vector<vector<double> > output_values = data.output_data("test");
	while (m_count < 10000)
	{
		m_count +=1;
		cout<<"Press 1 to test the network or 0 to quit !"<<endl;
		int n;
		cin >> n;
		if(n == 1)
		{
			// We pick up the next written digit and corresponding label
			Network::feedForwardNetwork(images[m_count]);
			std::vector<double> resultVals;
			Network::getResultsNetwork(resultVals);
			int result = Network::interpretResults(resultVals);
			double x = data.output_bmp(m_count);
			cout<<"Digit the networks sees : "<<result<<endl;
			cout<<"Actual digit : "<<Network::interpretResults(output_values[m_count])<<endl;
			if (result != Network::interpretResults(output_values[m_count]))
			{
				m_count_error +=1;
				m_error_testing = m_count_error / m_count;
			}
			cout<<"The updated error rate for the network is"<<m_error_testing<<endl;
		}
		else if (n == 2)
		{
			return;
		}
		else
		{
			cout<<"You have to write 0 or 1 !"<<endl;
		}
	}
	return;
}

//This function does the backPropagation of the neural network
void Network::backPropNetwork(const vector<double> &targetVals){
	// Calculate overall net error 'RMS of the output neuron errors)
	Layer &outputLayer = m_layers.back();
	m_error = 0.0;
	for (unsigned n = 0; n < outputLayer.size() - 1; ++n){
		double delta = targetVals[n] - outputLayer[n].getOutputVal();
		m_error += delta*delta;
	}
	m_error /= outputLayer.size() - 1;
	m_error = sqrt(m_error);

	// Implement a recent average measurement

	m_recentAverageError =
		(m_recentAverageError * m_recentAverageSmoothingFactor + m_error)
		/ (m_recentAverageSmoothingFactor + 1);


	//Calculate output layer gradients
	for (unsigned n = 0; n < outputLayer.size() - 1; ++n){
		outputLayer[n].calcOutputGradients(targetVals[n]);
	}

	// Calculate gradients on hidden layers
	for (unsigned layerNum = m_layers.size() - 2; layerNum > 0; --layerNum){
		Layer &hiddenLayer = m_layers[layerNum];
		Layer &nextLayer = m_layers[layerNum + 1];
		for (unsigned n = 0; n < hiddenLayer.size()-1; ++n){
			hiddenLayer[n].calcHiddenGradients(nextLayer);
		}
	}
	// For all layers from outputs to first hidden layer.
	// update connection weights
	for (unsigned layerNum = m_layers.size() - 1; layerNum > 0; --layerNum){
		Layer &layer = m_layers[layerNum];
		Layer &prevLayer = m_layers[layerNum - 1];
		for (unsigned n = 0; n < layer.size()-1; ++n){
			layer[n].updateInputWeights(prevLayer, m_eta, m_alpha);
		}
	}

}

void Network::data_training(void){
	gestion_data data;
	vector <vector<double> > images = data.images_data("train");
	vector<vector<double> > output_values = data.output_data("train");
	Network::training(images, output_values);
}
