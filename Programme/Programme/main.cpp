#include "Network.h"

int main(){

	double eta = 0.2;
	double alpha = 0.5;
	Network rdn(eta, alpha, TAN);
    cout<<"Network created"<<endl;
    rdn.data_training();
    rdn.consoleTesting();
    return 0;
}
