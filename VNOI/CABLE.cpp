#include <bits/stdc++.h>
#define ll long long
#define fmax 1000006
using namespace std;

ll n;
ll a[fmax];
ll f[fmax];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(auto & x : a) cin >> x;
    f[0] = a[0];
    f[1] = f[0] + a[1];
    for(ll i = 2; i < n; i++)
        f[i] = min (f[i - 2] + a[i], f[i - 1] + a[i]);
    cout << f[n - 2];
    return 0;
}
/*
Test case #1:	Accepted	[0.013s,	1.93 MB]	(0/0)
Test case #2:	Accepted	[0.015s,	3.36 MB]	(1/1)
Test case #3:	Accepted	[0.013s,	1.99 MB]	(1/1)
Test case #4:	Accepted	[0.019s,	2.04 MB]	(1/1)
Test case #5:	Accepted	[0.012s,	1.86 MB]	(1/1)
Test case #6:	Accepted	[0.012s,	1.98 MB]	(1/1)
Test case #7:	Accepted	[0.012s,	2.04 MB]	(1/1)
Test case #8:	Accepted	[0.012s,	3.27 MB]	(1/1)
Test case #9:	Accepted	[0.012s,	3.24 MB]	(1/1)
Test case #10:	Accepted	[0.012s,	3.24 MB]	(1/1)
Test case #11:	Accepted	[0.013s,	3.75 MB]	(1/1)


Resources: 0.019s, 3.75 MB
Final score: 10/10 (0.070/0.070 points)
*/
