#include "Network.h"
#include "TrainingMethod.h"


class Training{

public:
	Network _networkToTrain;
	std::vector<std::vector<double>> _inputValue;
	std::vector<std::vector<double>> _outputValue;
	TrainingMethod method;
};