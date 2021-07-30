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
	for (int i=0;i<100;i++) 
		for (int j=0;j<100;j++) 
			for (int k=0;k<3;k++) px[i][j][k]=rand() % 255;

	ofstream out2;
	out2.open("img2.ppm");
	out2 << "P3 100 100 255\n";
	for (int i=0;i<100;i++)
		for (int j=0;j<100;j++) {
			for (int k=0;k<3;k++) out2 << px[i][j][k] << "\n";
		}
	blur();
	for (int i=0;i<100;i++)
		for (int j=0;j<100;j++)
			for (int k=0;k<3;k++) out << px[i][j][k] << "\n";

}

void blur() {
	int tmp[100][100][3];
	for (int i=1;i<99;i++)
		for (int j=1;j<99;j++) {
			tmp[i][j][0]=tmp[i][j][1]=tmp[i][j][2]=0;
			for (int k=-1;k<=1;k++)
				for (int f=-1;f<=1;f++) {
					tmp[i][j][0]+=px[i+k][j+f][0];
					tmp[i][j][1]+=px[i+k][j+f][1];
					tmp[i][j][2]+=px[i+k][j+f][2];
					// cout << tmp[i][j][0] << " ADD " << px[i+k][j+f][0] << "\n";
				}
			// cout << "HI " << i << " " << j << " [" << tmp[i][j][0] << " " << tmp[i][j][1] << " " << tmp[i][j][2] << "]\n";
			tmp[i][j][0]/=9;
			tmp[i][j][1]/=9;
			tmp[i][j][2]/=9;
			
		}
	for (int i=1;i<99;i++)
		for (int j=1;j<99;j++)
			for (int k=0;k<3;k++) px[i][j][k]=tmp[i][j][k];
}
void blurbad() {
	for (int i=1;i<99;i++)
		for (int j=1;j<99;j++) {
			for (int k=-1;k<=1;k++)
				for (int f=-1;f<=1;f++) {
					if (!k && k==f) continue;
					px[i][j][0]+=px[i+k][j+f][0];
					px[i][j][1]+=px[i+k][j+f][1];
					px[i][j][2]+=px[i+k][j+f][2];
					// cout << tmp[i][j][0] << " ADD " << px[i+k][j+f][0] << "\n";
				}
			// cout << "HI " << i << " " << j << " [" << tmp[i][j][0] << " " << tmp[i][j][1] << " " << tmp[i][j][2] << "]\n";
			px[i][j][0]/=9;
			px[i][j][1]/=9;
			px[i][j][2]/=9;
			
		}

}