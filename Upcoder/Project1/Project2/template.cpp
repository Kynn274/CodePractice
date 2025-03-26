#include <bits/stdc++.h>
using namespace std;

struct Diem{
    int x, y;
};

struct Vector{
    int a, b;
};

istream& operator >> (istream& in, Diem& a) {
    in >> a.x >> a.y;
    return in;
}

ostream& operator << (ostream& out, Diem a) {
    out << "(" << a.x << ", " << a.y << ")";
    return out;
}



int main() {
    return 0;
}