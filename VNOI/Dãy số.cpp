#include <bits/stdc++.h>
#define fmax 200005
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    long long n, a[fmax], f[fmax], iC(0);
    cin >> n;
    for(long long i = 0; i < n; i++) cin >> a[i];
    for(long long i = n; i < n * 2; i++) a[i] = a[i - n];
    long long i(0), j(1);
    while(i < n){
        if(j - i == n){
            iC++;
            i++;
            f[i] = a[i];
            while(f[i] <= 0){
                i++;
                f[i] = a[i];
            }
            j = i + 1;
        }
        if(j - i < n){
            f[j] = f[j - 1] + a[i];
            if(f[j] <= 0){
                i++;
                f[i] = a[i];
                while(f[i] <= 0){
                    i++;
                    f[i] = a[i];
                }
                j = i + 1;
            }else{
                j++;
            }
        }
    }
    cout << iC;
    return 0;
}
