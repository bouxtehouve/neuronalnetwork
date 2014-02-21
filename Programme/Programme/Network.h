#pragma once
#include "Neuron.h"
#include "TransfertFunction.h"

class Network{
	typedef std::vector<Neuron> Layer;
public:
	//Network(const std::vector<unsigned> &architecture, const TransfertFunction &transfertFunction,Parameters p);
	Network(double eta, double alpha, Transfert choice); //Constructeur
	void feedForwardNetwork(const std::vector<double> &inputVals);
	//Pour une valeur d'input donnee, fait progresser l'information jusqu'a la derniere couche
	void backPropNetwork(const std::vector<double> &targetVals);
	//Effectue une retropropagation du gradient selon les valeurs que l'on aurait voulu avoir pour un input sur la couche de sortie
	//Je te conseille de prendre pour targetVal le vecteur (0,0,...1,0,...,0) de longueur 10, le 1 est pour le chiffre de 0 à 9 correspondant
	// J'espère que cette fonction fait bien ce qu'on dit !
	void getResultsNetwork(std::vector<double> &resultVals);
	//resultVals est modifie pour valoir le vecteur de ce que renvoie le réseau sur la dernière couche ( étant donnés les derniers inputs feedforward )
	int interpretResults(std::vector<double> &resultVals);
	// Renvoie le digit correspondant a getResultsNetwork ( en gros, si la i-ème neurone de la dernière couche renvoie la valeur max, alors le réseau a reconnu comme un i l'input

	void training(const std::vector<std::vector<double> > &inputValsTab, const std::vector<std::vector<double> > &outputValsTab);
	// répétition de singletraining sur un vecteur d'input/output
	void singleTraining(const std::vector<double> &inputVals, const std::vector<double> &outputVals);
	// prend en entrée un vecteur input, en sortie l'output voulu ( 0,...1,...0 ) donc, et améliore le réseau par rétropropagation
	void singleTesting(const std::vector<double> &inputVals, int &wanted_digit);
	// (pour la gui) une fois le réseau entraîné, regarde pour un input donné si on reconnaît bien et modifie le taux d'erreur en attribut
	void data_training(void);
	// will train our network given the data we have

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
