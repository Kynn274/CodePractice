#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

class Diem {
private:
	int x, y;
public:
	Diem(int x = 0, int y = 0) {
		this->x = x;
		this->y = y;
	}
	void nhap() {
		cin >> x >> y;
	}
	void xuat() {
		cout << "(" << x << ", " << y << ")";
	}

	double tinhKhoangCach(Diem d) {
		return sqrt(pow(d.x - x, 2) + pow(d.y - y, 2));
	}

};



int main() {
	Diem A, B, C;
	A.nhap();
	B.nhap();
	C.nhap();
	cout << "Độ dài các cạnh:\n";
	cout << "AB = " << fixed << setprecision(2) << A.tinhKhoangCach(B) << endl;
	cout << "BC = " << fixed << setprecision(2) << B.tinhKhoangCach(C) << endl;
	cout << "AC = " << fixed << setprecision(2) << A.tinhKhoangCach(C) << endl;
	return 0;
}