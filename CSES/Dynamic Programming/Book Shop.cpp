#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n, x;
ll h[1001], s[1001];
ll dp[100001];

int main() {
    cin >> n >> x;
    for(ll i = 0; i < n; i++) cin >> h[i]; // price
    for(ll i = 0; i < n; i++) cin >> s[i]; // pages

    for(ll i = 0; i < n; i++)
        for(ll j = x; j >= h[i]; j--)
            dp[j] = max(dp[j], dp[j - h[i]] + s[i]);

    cout << dp[x];
    return 0;
}

