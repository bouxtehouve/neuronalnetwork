


class Connection{

public:
	double weight;
	double deltaWeight;
	Connection(){};
	~Connection(){};
	Connection(Connection const &connect){weight=connect.weight; deltaWeight=connect.deltaWeight;};


};