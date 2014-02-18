#include "extract_data.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

data::data(string path0)
{
	path=path0;
}

vector <vector<double>> data::images_data(string aim)
{
	string file_name;
	vector <vector<double>> v_images;

	if (aim=="test"){
		file_name="test_images.txt";
		if (aim=="train"){
			file_name="train_images.txt";
		}

		ifstream data_images(path+file_name);
		if (data_images) {
			double value;
			while ( data_images >> value ) {
				vector<double> v_pixel;
				for (unsigned i=0; i<784; i++){
					v_pixel.push_back(value);
				}
				v_images.push_back(v_pixel);
			}
		}
		return v_images;
	}

	else{
		cout << "File can't be opened: aim must be 'train' or 'test'" << endl;
	}
}

vector<double> data::labels_data(string aim)
{
	string file_name;
	vector<double> v_labels;

	if (aim=="test"){
		file_name="test_labels.txt";
		if (aim=="train"){
			file_name="train_labels";
		}

		ifstream data_labels(path+file_name);
		if (data_labels) {
			double value;
			while ( data_labels >> value ) {
				v_labels.push_back(value);
			}
		}
		return v_labels;
	}
	
	else{
		cout << "File can't be opened: aim must be 'train' or 'test'" << endl;
	}
}