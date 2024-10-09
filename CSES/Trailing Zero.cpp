#include <iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;
    long long ans(0),tmp(0);
    
    // Count factors of 5
    for (long long i = 5; i <= n; i *= 5) ans += n / i;
    // Count factors of 2
    for (long long i = 2; i <= n; i *= 2) tmp += n / i;

    cout << min(ans, tmp) << endl;
    
    return 0;
}