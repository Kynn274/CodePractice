#include <bits/stdc++.h>
using namespace std;

int n;
string x;
queue<int> q;

void remove_last(queue<int> & main_q){
  queue<int> tmp;
  while(main_q.size() > 1){
    tmp.push(main_q.front());
    main_q.pop();
  }
  main_q = tmp;
}

int main(){
    cin >> n;
    while(n--){
        cin >> x;
        if(x == "empty")
            if(q.empty()) cout << "YES\n";
            else cout << "NO\n";
        else if(x == "pop"){
            cout << q.back() << "\n";
            remove_last(q);
        }
        else if(x == "top") cout << q.back() << '\n';
        else if(x == "push"){
            int var;
            cin >> var;
            q.push(var);
        }
    }
    
    return 0;
}
