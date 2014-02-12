#pragma once
#include <cmath>


enum Transfert{
	TAN
};

//Transfer function used in each neuron
class TransfertFunction{

public:
	double value(double x, Transfert t){
		if (t = TAN){
			return valueTan(x);
		}
		else return 0;
	};
	double derivative(double x, Transfert t){
		if (t = TAN){
			return derivativeTan(x);
		}
		else return 0;
	};


	double valueTan(double x){
		return std::tanh(x);
	}

	double derivativeTan(double x){
		return 1 - x*x;
	};
};
