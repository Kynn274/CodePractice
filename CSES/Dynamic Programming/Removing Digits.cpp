#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n;
ll iCount(0);

ll findMaxDigit(ll n){
    ll maxDigit = 0;
    while(n > 0){
        maxDigit = max(maxDigit, n % 10);
        n /= 10;
    }
    return maxDigit;
}


int main() {
    cin >> n;
    while(n > 0){
        ll maxDigit = findMaxDigit(n);
        n -= maxDigit;
        iCount++;
    }
    cout << iCount;
}
