#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "extract_data.h"
#include "EasyBMP.h" // external library using namespace std;

int main(){
	data test0("\\Users\\Bouxtehouve\\Dropbox\\C++ Neural Network\\data");
	// direction path, with double \\;
	cout << test0.output_bmp(1258)<< endl;
}
