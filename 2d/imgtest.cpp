#include <iostream>
#include <fstream>
// #include "Camera.h"
// write to PPM
using namespace std;

int px[100][100][3];
void blur();
void blurbad();
int main() {
	
	ofstream out;
	out.open("img3.ppm");
	out << "P3 100 100 255\n";
	for (int i=25;i<75;i++) 
		for (int j=25;j<75;j++)
			px[i][j][0]=255;
	for (int i=0;i<100;i++)
		for (int j=0;j<100;j++)
			for (int k=0;k<3;k++) out << px[i][j][k] << "\n";
}
