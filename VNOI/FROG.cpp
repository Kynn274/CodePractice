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
    f[1] = abs(a[1] - a[0]);
    for(ll i = 2; i < n; i++)
        f[i] = min (f[i - 1] + abs(a[i] - a[i - 1]), f[i - 2] + abs(a[i] - a[i - 2]));
    cout << f[n - 1];
    return 0;
}
/*
Test case #1:	Accepted	[0.015s,	1.98 MB]	(1/1)
Test case #2:	Accepted	[0.014s,	1.87 MB]	(1/1)
Test case #3:	Accepted	[0.014s,	1.99 MB]	(1/1)
Test case #4:	Accepted	[0.012s,	1.98 MB]	(1/1)
Test case #5:	Accepted	[0.015s,	1.93 MB]	(1/1)
Test case #6:	Accepted	[0.025s,	4.52 MB]	(1/1)
Test case #7:	Accepted	[0.019s,	4.56 MB]	(1/1)
Test case #8:	Accepted	[0.018s,	4.55 MB]	(1/1)
Test case #9:	Accepted	[0.019s,	4.52 MB]	(1/1)
Test case #10:	Accepted	[0.024s,	4.51 MB]	(1/1)
Test case #11:	Accepted	[0.023s,	4.54 MB]	(1/1)


Resources: 0.025s, 4.56 MB
Final score: 11/11 (0.100/0.100 points)
*/
