#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin >> n;
    
    if (n == 1) cout << 1;
    else if (n <= 3) cout << "NO SOLUTION";
    else{
        vector<long long> odd;
        vector<long long> even;
        for(long long i = 1; i <= n; i++)
            if(i % 2 == 0) even.push_back(i);
            else odd.push_back(i);
        for(long long j = 0; j < (long long) even.size(); j++) cout << even[j] << ' ';
        for(long long i = 0; i < (long long) odd.size(); i++) cout << odd[i] << ' ';
    }
    return 0;
}