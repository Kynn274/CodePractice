#include <bits/stdc++.h>
using namespace std;

long long n;
double f[1000006];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(long long i = 1; i < n; i++)
      f[i] = (double) log(i) + f[i - 1];
    cout << log(pow(10,20000)) << '\n';
    long long i = 0, j = i + 1;
    while(i <= j){
      if(f[j] - f[i - 1] < (double) log(n)) j++;
      else if(f[j] - f[i - 1] > (double) log(n)) i++;
      else{
        cout << i << ' ' << j;
        break;
      }
    }
    return 0;
}
