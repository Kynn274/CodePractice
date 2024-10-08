#include <bits/stdc++.h>
#define fmax 1000006
#define ll long long
using namespace std;

ll n, m, u, v;
ll a[fmax];
ll f[fmax];

bool checkSNT(ll x){
    if(x < 2) return 0;
    if(x == 2 || x == 3) return 1;
    for(ll i = 2; i <= sqrt(x); i++)
        if(x % i == 0) return 0;
    return 1;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(ll i = 0; i < n; i++) cin >> a[i];
    for(ll i = 0; i < n; i++) f[i] = f[i - 1] + a[i];
    for(ll i = 0; i < m; i++){
        cin >> u >> v;
        if(checkSNT(f[v - 1] - f[u - 2])) cout << 1 << '\n';
        else cout << 0 << '\n';
    }
    return 0;
}

/*
Test case #1:	Accepted	[0.007s,	1.96 MB]	(1/1)
Test case #2:	Accepted	[0.004s,	1.95 MB]	(1/1)
Test case #3:	Accepted	[0.005s,	2.02 MB]	(1/1)
Test case #4:	Accepted	[0.005s,	1.99 MB]	(1/1)
Test case #5:	Accepted	[0.006s,	2.02 MB]	(1/1)
Test case #6:	Accepted	[0.007s,	1.95 MB]	(1/1)
Test case #7:	Accepted	[0.006s,	2.00 MB]	(1/1)
Test case #8:	Accepted	[0.008s,	1.95 MB]	(1/1)
Test case #9:	Accepted	[0.006s,	1.94 MB]	(1/1)
Test case #10:	Accepted	[0.006s,	1.96 MB]	(1/1)
Test case #11:	Accepted	[0.070s,	1.96 MB]	(1/1)
Test case #12:	Accepted	[0.078s,	1.95 MB]	(1/1)
Test case #13:	Accepted	[0.079s,	2.00 MB]	(1/1)
Test case #14:	Accepted	[0.072s,	1.95 MB]	(1/1)
Test case #15:	Accepted	[0.861s,	1.95 MB]	(1/1)
Test case #16:	Accepted	[0.728s,	1.95 MB]	(1/1)
Test case #17:	Accepted	[0.617s,	2.02 MB]	(1/1)
Test case #18:	Accepted	[0.801s,	1.96 MB]	(1/1)
Test case #19:	Accepted	[0.726s,	1.94 MB]	(1/1)
Test case #20:	Accepted	[0.858s,	1.96 MB]	(1/1)

*/
