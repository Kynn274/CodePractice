#include <bits/stdc++.h>
#define ll long long 
#define INF 1e9
#define fmax 1000006
#define mod 1000000007
using namespace std;

ll n, x;
ll coins[fmax];
ll dp[fmax];

int main() {
    cin >> n >> x;
    for (int i = 0; i < n; i++) cin >> coins[i];
    for (int i = 0; i <= x; i++) dp[i] = INF;
    
    dp[0] = 0;
    sort(coins, coins + n);

    for (int j = 0; j < n; j++) {
        for (int i = coins[j]; i <= x; i++) {
            if (i - coins[j] >= 0) {
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }
    
    if (dp[x] == INF) cout << -1;
    else cout << dp[x];
    
    return 0;
}