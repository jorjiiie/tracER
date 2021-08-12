#include <iostream>
#include <map>
#include <string>
#include <chrono>
#include <thread>
#include <mutex>
 #include <vector>

using namespace std;

vector<int> locka;

mutex why;

class joea {
public:
	joea();
	joea(int c) {};
	void cool_kid() {
		cout << "your mother\n";
	}
};
void gaming() {
	for (int i=0;i<1e7;i++) {
		int b = 69 +69;
	}
}

void gogo(int id, int sz) {
	for (int i=0;i<sz;i++) {
		// why.lock();
		if (locka[i]==0) {
			locka[i] = id;
			if (locka[i]!=id) continue;
			cout << i << ": " << id << "\n";

			gaming();
		}
		// why.unlock();
	}
}

void tester(vector<vector<int> >& carl) {
	for (auto& carl2 : carl) for (int i : carl2) cout << i << " ";
	cout  << "\n";
}
int main() {
	locka.resize(10);
	thread joe(gogo, 1,locka.size());
	thread joe2(gogo,2,locka.size());
	joe2.join();
	joe.join();
	joea carl(69);

	thread joe3(&joea::cool_kid,&carl);
	joe3.join();
	for (auto &k : locka) {
		cout << k << "\n";
	}
	vector<vector<int> > bob(5);
	int a=1;
	for (auto& k : bob) k = vector<int>(a,++a);

	thread joe4(tester,std::ref(bob));
	joe4.join();
	cout << std::thread::hardware_concurrency() << " threads JASLDAJSD\n";
}
