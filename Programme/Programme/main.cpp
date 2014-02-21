#include "Network.h"

int main(){

	double eta = 0.2;
	double alpha = 0.5;
	Network rdn(eta, alpha, TAN);
    cout<<"Network created"<<endl;
    rdn.data_training();
    cout<<"very good"<<endl;
    rdn.consoleTesting();
    return 0;
}
