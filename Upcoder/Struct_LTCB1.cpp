#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, count(0);
    cin >> n;
    vector<int> point_x(n);
    vector<int> point_y(n);
    vector<int> point_check(n, 0);
    
    for(int i = 0; i < n; i++) cin >> point_x[i];
    for(int i = 0; i < n; i++) cin >> point_y[i];
    
    for(int i = 0; i < n - 1; i++){
        if(point_check[i] == 0){
            for(int j = i + 1; j < n; j++)
                if(point_x[i] == point_x[j] && point_y[i] != point_y[j] && point_x[i] != 0){
                    if(point_check[i] == 0){
                        count++;
                        point_check[i] = 1;
                    }
                    point_check[j] = 1;
                }
        }
    }
    cout << count;
    
    return 0;
}