#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin >> n;

    if (n <= 3) cout << "NO SOLUTION";
    else{
        vector<long long> odd;
        vector<long long> even;
        for(long long i = 1; i <= n; i++)
            if(i % 2 == 0) even.push_back(i);
            else odd.push_back(i);
        for(long long i = 0; i < odd.size(); i++) cout << odd[i] << ' ';
        for(long long j = 0; j < even.size(); j++) cout << even[i] << ' ';
    }
    return 0;
}