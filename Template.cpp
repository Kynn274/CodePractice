#include <bits/stdc++.h>
using namespace std;

long long n, k, tmp;
long long sum[1000006];

bool check(long long mid){
    long long num = k;
    long long begin(1);

    if(sum[1] >= mid) num--;

    for(long long i = 2; i <= n; i++){
        if(sum[i] - sum[begin]){
            num--;
            begin = i;
        }
    }

    return num <= 0;
}

long long maxDividedValue(long long l, long long r){
    long long maxValue(0);
    while(l <= r){
        long long mid = (l + r) / 2;
        if(check(mid)){
            l = mid + 1;
            maxValue = max(maxValue, mid);
        }else
            r = mid - 1;
    }
    return maxValue;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    
    for(long long i = 1; i <= n; i++){
        cin >> tmp;
        sum[i] = sum[i - 1] + tmp;
    }
    
    long long maxDividedNumber = maxDividedValue(0, sum[n]);
    cout << maxDividedNumber;
    return 0;
}