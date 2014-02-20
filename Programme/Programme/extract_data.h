#ifndef extract_data
#define extract_data

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class data
{
public:
	vector <vector<double> > images_data(string aim);	// aim = 'test' or 'train'
	/* vector of vector of double for images: 
	rank 1) list of pictures (10000 for 'test', 60000 for 'train')
	rank 2) list of pixels (28*28=784 doubles)
	rank 3) each double (0 to 255)
	*/

	vector <double> labels_data(string aim);
	/* vector of double for labels: 
	rank 1) list of labels (10000 for 'test', 60000 for 'train')
	rank 2) each digits (0 to 9)
	*/

	int rand_digit();
	/*
	return a random number: used for graphic interface to show a random image
	*/

	double output_bmp(int l);
	/*
	l=index of line, 0<l<10000 or 60000, to choose a digit
	create a image of pixels extracted from images_data, path of image: in current project
	also return label corresponding to the pixel
	*/

	string get_path();
	/*
	get the path directory of project
	*/

};

#endif