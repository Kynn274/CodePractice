#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin >> n;

    if (n >= 3 && n % 2 != 0 && (n - 3) % 4 == 0 || n >= 4 && n % 4 == 0){
        cout << "YES";
        vector<long long> gr1;
        vector<long long> gr2;
        if(n % 2 != 0){
            gr1.push_back(1);
            gr1.push_back(2);
            gr2.push_back(3);
            for(long long i = 4; i <= n; i += 4){
                gr1.push_back(i);
                gr2.push_back(i + 1);
                gr2.push_back(i + 2);
                gr1.push_back(i + 3);
            }
        }else{
            for(long long i = 1; i <= n; i += 4){
                gr1.push_back(i);
                gr2.push_back(i + 1);
                gr2.push_back(i + 2);
                gr1.push_back(i + 3);
            }
        }
        cout << "\n" << gr1.size() << '\n';
        for(long long i = 0; i < (long long) gr1.size(); i++) cout << gr1[i] << ' ';
        cout << "\n" << gr2.size() << '\n';
        for(long long i = 0; i < (long long) gr2.size(); i++) cout << gr2[i] << ' ';
    }
    else cout << "NO";
    return 0;
}
