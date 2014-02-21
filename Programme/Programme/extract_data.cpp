#include "extract_data.h"
#include "EasyBMP.h"
#include <time.h>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

string gestion_data::get_path()
{
	string path;
	path=__FILE__;
	size_t ext_pos = path.find_last_of('\\');
	path.erase(ext_pos+1, path.size()-1);
	return path;
}

vector <vector<double> > gestion_data::images_data(string aim)
{
	string file_name;
	vector <vector<double> > v_images;
	double n_rows;

	// determine the name of the file depending on the aim and its number of rows
	if (aim == "test"){
		file_name="test_images.txt";
		n_rows=10000;
	}
	else if (aim == "train"){
		file_name="train_images.txt";
		n_rows=60000;
	}
	else {
		cerr << "File can't be opened: aim must be 'train' or 'test'" << endl;
		// no return: to get the error easily
	}
	ifstream data_images((get_path()+file_name).c_str());		// data_images: data file of images
	if (data_images) {
		for (unsigned i=1; i<n_rows+1; i++){	// for every digits, creation of a sub-vector to have pixels
			vector<double> v_pixel;
			for (unsigned j=1; j<785; j++){		// extraction the values from the data
				double value;
				data_images >> value;
				v_pixel.push_back(value);
			}
			v_images.push_back(v_pixel);
		}
	}
	if (aim == "test"){
			m_images = v_images;
		}
	return v_images;
}

vector<double> gestion_data::labels_data(string aim)
{
	string file_name;
	vector<double> v_labels;

	// determine the name of the file depending on the aim
	if (aim == "test"){
		file_name="test_labels.txt";
	}
	else if (aim == "train"){
		file_name="train_labels.txt";
	}
	else {
		cerr << "File can't be opened: aim must be 'train' or 'test'" << endl;
		// no return: to get the error easily
	}
	ifstream data_labels((get_path()+file_name).c_str());		// data_labels: data file of labels
	if (data_labels) {
		double value;
		while ( data_labels >> value ){		// put all values in v_labels
			v_labels.push_back(value);
		}
	}
	if (aim == "test"){
				m_labels = v_labels;
			}
	return v_labels;
}



double gestion_data::output_bmp(int l)
{
	vector <vector <double> > v;
	if (m_images.size() == 0) {v=images_data("test");}
	else {v = m_images;}// no need to build images while training the network
	vector <double> w;
	w=v.at(l);		// select an image in the vector of images

	BMP AnImage;	// create a bitmap file
	AnImage.SetSize(28,28);		// setting size (28*28 pixels)
	AnImage.SetBitDepth(32);	// coding on 32 bits
	// RGB method, argument=value get from images_data
	for (int i=1;i<28;i++){
		for (int j=1; j<28; j++){
			AnImage(i,j)->Red = w[28*j+i];
			AnImage(i,j)->Green = w[28*j+i];
			AnImage(i,j)->Blue = w[28*j+i];
			AnImage(i,j)->Alpha = 0;
		}
	}

	AnImage.WriteToFile("Output.bmp");		// name of output file
	vector <double> y;
	if (m_labels.size() == 0) {y=labels_data("test");}
	else {y = m_labels;}
	return y.at(l);
}

vector<vector<double> > gestion_data::output_data(string aim){
	vector<double> labels = labels_data(aim);
	vector<vector<double> > output_data;
	for (int i = 0; i<labels.size(); ++i){
		for (unsigned k = 0; k<10; ++k){
			if (k == labels[i]) output_data[i].push_back(1);
				else output_data[i].push_back(0);
			}
		}
	return output_data;
}

vector<double> gestion_data::singleoutput_data(double &label){
	vector<double> output_data;
	for (unsigned k =0; k<10; ++k){
		if (k == label) output_data.push_back(1);
						else output_data.push_back(0);
	}
	return output_data;
}

int gestion_data::rand_digit()
{
	srand(time(NULL)); // initialization of rand
	return static_cast<int>(rand() % 10000);
}
