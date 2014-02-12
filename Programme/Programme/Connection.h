// A connection is two double which are used for each neuron's next neuron. It consits in the weight and the deltaweight
class Connection{

public:
	double weight;
	double deltaWeight;
	Connection(){};
	~Connection(){};
	Connection(Connection const &connect){ weight = connect.weight; deltaWeight = connect.deltaWeight; };


};