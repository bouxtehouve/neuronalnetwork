#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "extract_data.h"
#include "Network.h"
#include "EasyBMP.h" // external library
using namespace std;

int main(){
	vector<unsigned> archi;
	archi.push_back(784);
	archi.push_back(30000);
	archi.push_back(10);
	double eta = 0.2;
	double alpha = 0.5;
	Network rdn(eta, alpha, TAN, archi);
	rdn.data_training();
	//cout << "cc7" << endl;
	//vector<double> input(2);
	//input.push_back(3.5);
	//cout << "cc9" << endl;
	//input.push_back(2.9);
	//cout << "cc10" << endl;
	//vector<double> output(1);
	//output.push_back(6.7);
	//cout << "cc12" << endl;
	//rdn.feedForwardNetwork(input);
	//cout << "cc13" << endl;
	//rdn.singleTraining(input, output);
	//cout << "cc14" << endl;
}
