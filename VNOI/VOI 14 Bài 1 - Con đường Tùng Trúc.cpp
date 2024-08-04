#include <bits/stdc++.h>
#define fmax 300005
using namespace std;

struct item{
    long long d;
    int k;
};

istream & operator>>(istream & is, item & p){
    is >> p.d >> p.k;
    return is;
}

bool ss(item a, item b){
    return a.d < b.d;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    long long n, a, b;
    item v[fmax];

    cin >> n >> a >> b;
    for(long long i = 0; i < n; i++) cin >> v[i];
    sort(v, v + n, ss);

    long long i(0), j(0), distance(1e9), ia(0), ib(0);
    while(j < n){
        v[j].k == 1 ? ia++ : ib++;
        while(ia > a && v[i].k == 1 || ib > b && v[i].k == 2){
            v[i].k == 1 ? ia-- : ib--;
            i++;
        }
        if(ia >= a && ib >= b) distance = min(distance, v[j].d - v[i].d);
        j++;
    }
    distance == 1e9 ? cout << -1 : cout << distance;
    return 0;
}
