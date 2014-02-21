#pragma once
#include "Neuron.h"
#include "TransfertFunction.h"

class Network{
	typedef std::vector<Neuron> Layer;
public:
	//Network(const std::vector<unsigned> &architecture, const TransfertFunction &transfertFunction,Parameters p);
	Network(double eta, double alpha, Transfert choice, std::vector<unsigned> &architecture); //Constructeur
	void feedForwardNetwork(const std::vector<double> &inputVals);
	//Pour une valeur d'input donnee, fait progresser l'information jusqu'a la derniere couche
	void backPropNetwork(const std::vector<double> &targetVals);
	//Effectue une retropropagation du gradient selon les valeurs que l'on aurait voulu avoir pour un input sur la couche de sortie
	//Je te conseille de prendre pour targetVal le vecteur (0,0,...1,0,...,0) de longueur 10, le 1 est pour le chiffre de 0 � 9 correspondant
	// J'esp�re que cette fonction fait bien ce qu'on dit !
	void getResultsNetwork(std::vector<double> &resultVals);
	//resultVals est modifie pour valoir le vecteur de ce que renvoie le r�seau sur la derni�re couche ( �tant donn� les derniers inputs feedforward )
	int interpretResults(std::vector<double> &resultVals);
	// Renvoie le digit correspondant a getResultsNetwork ( en gros, si la i-�me neurone de la derni�re couche renvoie la valeur max, alors le r�seau a reconnu comme un i l'input

	void training(const std::vector<std::vector<double> > &inputValsTab, const std::vector<std::vector<double> > &outputValsTab);
	// r�p�tition de singletraining sur un vecteur d'input/output
	void singleTraining(const std::vector<double> &inputVals, const std::vector<double> &outputVals);
	// prend en entr�e un vecteur input, en sortie l'output voulu ( 0,...1,...0 ) donc, et am�liore le r�seau par r�tropropagation
	void singleTesting(const std::vector<double> &inputVals, int &wanted_digit);
	// (pour la gui) une fois le r�seau entra�n�, regarde pour un input donn� si on reconna�t bien et modifie le taux d'erreur en attribut

	std::vector <Layer> m_layers;
	double m_error;
	double m_recentAverageError;
	double m_recentAverageSmoothingFactor;
	double m_eta;
	double m_alpha;
	double m_error_testing;
	unsigned m_count;
	unsigned m_count_error;
	Transfert m_transfertFunction;

};
