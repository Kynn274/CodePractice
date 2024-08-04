#include <bits/stdc++.h>
#define ll long long
#define fmax 1003
using namespace std;

ll flag;
ll n, w;
ll a[fmax][fmax];
ll f[fmax][fmax];

// di chuyển 4 chiều 
void maxWeight(){
    f[0][0] = a[0][0];
    for(ll i = 1; i < n; i++)
        f[0][i] = min (f[0][i - 1], a[0][i]);
    for(ll i = 1; i < n; i++)
        f[i][0] = min (f[i - 1][0], a[i][0]);
    for(ll i = 1; i < n; i++)
        for(ll j = 1; j < n; j++)
            f[i][j] = min (a[i][j], max (f[i - 1][j], f[i][j - 1]));
    cout << f[n - 1][n - 1];
}

void minDanger(){
    a[0][0] < w ? f[0][0] = 1 : f[0][0] = 0;
    for(ll i = 1; i < n; i++)
        a[0][i] < w ? f[0][i] = f[0][i - 1] + 1 : f[0][i] = f[0][i - 1];
    for(ll i = 1; i < n; i++)
        a[i][0] < w ? f[i][0] = f[i - 1][0] + 1 : f[i][0] = f[i - 1][0];
    for(ll i = 1; i < n; i++)
        for(ll j = 1; j < n; j++)
            a[i][j] < w ? f[i][j] = min (f[i - 1][j], f[i][j - 1]) + 1 : f[i][j] = min (f[i - 1][j], f[i][j - 1]);
    cout << f[n - 1][n - 1];
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> flag;

    if(flag == 1){
        cin >> n >> w;
        for(ll i = 0; i < n; i++)
            for(ll j = 0; j < n; j++)
                cin >> a[i][j];
        minDanger();
    }else{
        cin >> n;
        for(ll i = 0; i < n; i++)
            for(ll j = 0; j < n; j++)
                cin >> a[i][j];
        maxWeight();
    }
    return 0;
}
