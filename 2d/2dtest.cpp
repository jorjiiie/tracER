#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


// 2d 

struct pix {
	int r,g,b;
};
class Canvas {
public:
	Canvas(int width, int length) {
		w = length;
		l = width;
		px.resize(l);
		for (auto& k : px) k.resize(w);
	}
	void drawRect(int x, int y, int width, int length, pix col) {
		int mn_x = max(x,0);
		int mn_y = max(y,0);
		int mx_x = min(x+width,w);
		int mx_y = min(y+length,l);

		for (int i = mn_x; i < mx_x; i++) {
			for (int j = mn_y; j < mx_y; j++) {
				for (int k=0;k<3;k++) px[i][j] = col;
			}
		}
		return;
	}
	void drawCircle(int x, int y, int radius, pix col) {
		int mn_x = max(x,0);
		int mn_y = max(y,0);
		int mx_x = min(x+2*radius,w);
		int mx_y = min(y+2*radius,l);
		int center_x = x+radius;
		int center_y = y+radius;

		int radius_2 = radius*radius;
		for (int i = mn_x; i < mx_x; i++) {
			// how much up/down ?
			for (int j = 0; j < radius; j++) {
				// if i-center^2 + j-center^2 < radius ^2
				if ((i-center_x)*(i-center_x) + j*j < radius_2) {
					px[i][center_y+j] = col;
					px[i][center_y-j] = col;
				}
			}
		}
	}
	void writeImg() {
		ofstream out;
		out.open("img41.ppm");
		out << "P3 " << w << " " << l <<  " 255\n";
		for (int i = 0; i < w; i++)
			for (int j = 0; j < l; j++) 
					out << px[i][j].r << " " << px[i][j].g << " " << px[i][j].b << "\n";
	}

	void blur() {
		// alias? LOL
		vector<vector<pix> > tmp;
		tmp.resize(l);
		for (auto& k : tmp) k.resize(w);
		for (int i=1;i<w-1;i++)
			for (int j=1;j<l-1;j++) {
				pix a = {0,0,0};
				for (int k = -1; k < 2; k++)
					for (int f = -1; f < 2; f++) {
						a.r += px[i+k][j+f].r;
						a.g += px[i+k][j+f].g;
						a.b += px[i+k][j+f].b;
					}
				a.r /= 9;
				a.g /= 9;
				a.b /= 9;
				tmp[i][j] = a;
			}
		for (int i=1;i<w-1;i++)
			for (int j=1;j<l-1;j++) {
				px[i][j] = tmp[i][j];
			}
	}

private:
	vector<vector<pix> > px;
	int w,l;
	int images;

};


int main() {
	Canvas canv(1000,1000);
	pix k = {0,255,255};
	canv.drawRect(20,20,30,30,k);
	canv.drawCircle(50,50,200,k);
	pix RED = {255,0,0};
	canv.drawCircle(600,200,400,RED);
	pix WHITE = {255,255,255};
	canv.drawRect(100,100,250,50,WHITE);
	canv.drawRect(200,150,50,100,WHITE);
	canv.drawRect(100,250,250,50,WHITE);

	canv.drawRect(100,400,50,150,WHITE);
	canv.drawRect(100,450,250,50,WHITE);
	canv.drawRect(300,400,50,150,WHITE);
	// canv.blur();
	canv.writeImg();
}