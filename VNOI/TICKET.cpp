#include <bits/stdc++.h>
#define ll long long
#define fmax 1000006
using namespace std;

ll n;
ll t[fmax];
ll r[fmax];
ll f[fmax];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(ll i = 0; i < n; i++) cin >> t[i];
    for(ll i = 0; i < n - 1; i++) cin >> r[i];
    f[0] = t[0];
    f[1] = min (f[0] + t[1], r[0]);
    for(ll i = 2; i < n; i++)
        f[i] = min (f[i - 2] + r[i - 1], f[i - 1] + t[i]);
    cout << f[n - 1];
    return 0;
}

/*
Test case #1:	Accepted	[0.006s,	1.93 MB]	(0/0)
Test case #2:	Accepted	[0.016s,	4.77 MB]	(1/1)
Test case #3:	Accepted	[0.006s,	1.98 MB]	(1/1)
Test case #4:	Accepted	[0.005s,	2.04 MB]	(1/1)
Test case #5:	Accepted	[0.006s,	1.86 MB]	(1/1)
Test case #6:	Accepted	[0.006s,	1.99 MB]	(1/1)
Test case #7:	Accepted	[0.008s,	3.49 MB]	(1/1)
Test case #8:	Accepted	[0.010s,	3.50 MB]	(1/1)
Test case #9:	Accepted	[0.011s,	3.62 MB]	(1/1)
Test case #10:	Accepted	[0.012s,	3.94 MB]	(1/1)
Test case #11:	Accepted	[0.012s,	4.29 MB]	(1/1)


Resources: 0.016s, 4.77 MB
Final score: 10/10 (0.050/0.050 points)
*/
