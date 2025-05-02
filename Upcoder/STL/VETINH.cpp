#include <bits/stdc++.h>
using namespace std;

class VETINH{
private:
    int x, y, z;
public:
    VETINH(int _x = 0, int _y = 0, int _z = 0){
        x = _x;
        y = _y;
        z = _z;
    }
    VETINH(const VETINH &s){
        this -> x = s.x;
        this -> y = s.y;
        this -> z = s.z;
    }
    friend istream& operator>>(istream& in, VETINH& s);
    friend ostream& operator<<(ostream& out, VETINH s);
    double distance(){
        return sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
    }
    bool operator>(VETINH s){
        return this->distance() > s.distance();
    }
    bool operator<(VETINH s){
        return this->distance() < s.distance();
    }
};

istream& operator>>(istream& in, VETINH& s){
    in >> s.x >> s.y >> s.z;
    return in;
}

ostream& operator<<(ostream& out, VETINH s){
    out << "(" << s.x << ", " << s.y << ", " << s.z << ")\n";
    return out;
}

int main(){
    int n;
    vector<VETINH> v;
    VETINH tmp;
    cin >> n;
    while(cin >> tmp) v.push_back(tmp);
    
    sort(v.begin(), v.end());

    if(n == 0) for(VETINH x : v) cout << x;
    else{
        for(int i = v.size() - 1; i >= 0; i--) cout << v[i];
    }
    
    
    return 0;
}

/*
Đúng 4/4
#######################
Thông tin chi tiết
test 1 :	0.007994s 			0 MB		 [đúng]
test 2 :	0.006332s 			0 MB		 [đúng]
test 3 :	0.006167s 			0 MB		 [đúng]
test 4 :	0.006191s 			0 MB		 [đúng]
*/
