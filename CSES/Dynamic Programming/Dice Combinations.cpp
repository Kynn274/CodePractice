#include <bits/stdc++.h>
#define ll long long
#define fmax 1000006
#define mod 1000000007

using namespace std;

// Var
ll n;
ll dp[fmax];

int main() {
    cin >> n;
    dp[0] = 1;
    for (ll i = 1; i <= n; i++) {
        dp[i] = 0;
        for (ll j = 1; j <= min(i, (ll)6); j++) {
            dp[i] = (dp[i] + dp[i - j]) % mod;
        }
    }

    cout << dp[n];
    return 0;
}