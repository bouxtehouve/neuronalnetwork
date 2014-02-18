#ifndef extract_data
#define extract_data

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class data
{	
	string path;

public:
	data(string);
	vector <vector<double>> images_data(string aim);
	vector<double> labels_data(string aim);
};

#endif