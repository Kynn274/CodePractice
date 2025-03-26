#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

struct Canh {
	int nguon, dich;
	int trongSo;
};

istream& operator>>(istream& is, Canh& c) {
	is >> c.nguon >> c.dich >> c.trongSo;
	return is;
}

void Fold_Bellman(int dinh, int canh, vector<Canh>& v, int nguon) {
	vector<int> d(canh, INT_MAX);
	d[nguon] = 0;
	for (int i = 0; i < canh; i++) {
		for (int j = 0; j < canh; j++) {
			if (d[v[j].nguon] != INT_MAX && d[v[j].dich] > d[v[j].nguon] + v[j].trongSo) {
				d[v[j].dich] = d[v[j].nguon] + v[j].trongSo;
			}
		}
	}
	for (int i = 0; i < canh; i++) {
		if (d[v[i].nguon] != INT_MAX && d[v[i].dich] > d[v[i].nguon] + v[i].trongSo) {
			cout << "Do thi co chu trinh am" << endl;
			return;
		}
	}
	for (int i = 0; i < dinh; i++) {
		cout << "Khoang cach tu " << nguon << " den " << i << " la: ";
		if(d[i] == INT_MAX)
			cout << "INF" << endl;
		else
			cout << d[i] << endl;
	}
}
int main() {
	int dinh, canh, nguon;
	cin >> dinh >> canh >> nguon;
	vector<Canh> v(canh);
	for (int i = 0; i < canh; i++) {
		cin >> v[i];
	}
	Fold_Bellman(dinh, canh, v, nguon);

	return 0;
}