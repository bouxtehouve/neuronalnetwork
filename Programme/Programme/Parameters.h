class Parameters{

public:
	double m_eta;
	double m_alpha;
	Parameters(){};
	~Parameters(){};
	Parameters(double eta, double alpha){
		m_eta = eta;
		m_alpha = alpha;

	};
	Parameters(Parameters const &para){
		m_eta = para.m_eta;
		m_alpha = para.m_alpha;
	};


};