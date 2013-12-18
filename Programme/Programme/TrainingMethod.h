

class TrainingMethod{

public:
	virtual void Training(Network &networkToTrain,const std::vector<double> &inputValue,const std::vector<double> &outputValue);


};