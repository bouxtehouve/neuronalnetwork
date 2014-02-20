#include "extract_data.h"
#include "EasyBMP.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

data::data(string path0)
{
	path=path0;
}

vector <vector<double> > data::images_data(string aim)
{
	string file_name;
	vector <vector<double> > v_images;
	double n_rows;

	// determine the name of the file depending on the aim and its number of rows
	if (aim=="test"){
		file_name="test_images.txt";
		n_rows=10000;
		if (aim=="train"){
			file_name="train_images.txt";
			n_rows=60000;
		}

		ifstream data_images(path+file_name);
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
		return v_images;
	}

	else{
		cerr << "File can't be opened: aim must be 'train' or 'test'" << endl;
		// no return: to get the error easily
	}
}

vector<double> data::labels_data(string aim)
{
	string file_name;
	vector<double> v_labels;

	// determine the name of the file depending on the aim
	if (aim=="test"){
		file_name="test_labels.txt";
		if (aim=="train"){
			file_name="train_labels";
		}

		ifstream data_labels(path+file_name);
		if (data_labels) {
			double value;
			while ( data_labels >> value ){		// put all values in v_labels
				v_labels.push_back(value);
			}
		}
		return v_labels;
	}
	
	else{
		cerr << "File can't be opened: aim must be 'train' or 'test'" << endl;
		// no return: to get the error easily
	}
}

double data::output_bmp(int l)
{
	vector <vector <double> > v;
	v=images_data("test");		// no need to build images while training the network
	vector <double> w;
	w=v.at(l);

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
	y=labels_data("test");
	return y.at(l);
}
