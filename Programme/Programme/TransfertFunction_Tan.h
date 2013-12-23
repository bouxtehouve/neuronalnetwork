#include <cmath>


class TransfertFunction_Tan{
public:
	double value(double x){
		return std::tanh(x);	
	};
	double derivative(double x){
		return 1-x*x;
	};

};