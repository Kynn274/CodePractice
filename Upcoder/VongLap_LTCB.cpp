#include <bits/stdc++.h>
using namespace std;

int main(){
    int x, n, count(0);
    cin >> n >> x;
    vector<int> a(n);
    
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n - 1; i++)
        for(int j = i + 1; j < n; j++)
            if(a[i] + a[j] == x){
                cout << "(" << a[i] << "," << a[j] << ")\n";
                count++;
            }
            
    if(count == 0) cout << "thì ra đến cả số còn không có cặp giống chủ tus";
    return 0;
}