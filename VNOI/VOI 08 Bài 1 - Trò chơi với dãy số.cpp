#include <bits/stdc++.h>
#define fmax 100005
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    long long n, b[fmax], c[fmax], ans(1e9);
    cin >> n;
    for(long long i = 0; i < n; i++) cin >> b[i];
    for(long long i = 0; i < n; i++) cin >> c[i];

    sort(b, b + n);
    sort(c, c + n);
    long long i = 0, j = n - 1;
    while(i < n && j >= 0){
        ans = min(ans, b[i] + c[j]);
        if(ans == 0) break;
        if(b[i] * c[j] < 0){
            if(abs(b[i]) > abs(c[j]))
        }
    }
    return 0;
}
