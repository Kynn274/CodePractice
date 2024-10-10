#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

ll n;
char grid[1001][1001];

ll dp[1001][1001];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];

    if(grid[0][0] == '*'){
        cout << 0;
        return 0;
    }
    
    for(ll i = 0; i < n; i++)
        if(grid[i][0] == '.') dp[i][0] = 1;
        else break;
    for(ll i = 1; i < n; i++) 
        if(grid[0][i] == '.') dp[0][i] = 1;
        else break;

    for(ll i = 1; i < n; i++)
        for(ll j = 1; j < n; j++)
            if(grid[i][j] == '.')
                dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % mod;
            else dp[i][j] = 0;
    
    cout << dp[n-1][n-1];
    return 0;
}

