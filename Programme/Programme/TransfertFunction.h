#pragma once

//Transfer function used in each neuron
class TransfertFunction{

public:
	virtual double value(double x){ return 0; };
	virtual double derivative(double x){ return 0; };

};