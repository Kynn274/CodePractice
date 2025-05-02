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

/*
Đúng 10/10
#######################
Thông tin chi tiết
test 1 :	0.007370s 			0 MB		 [đúng]
test 2 :	0.006210s 			0 MB		 [đúng]
test 3 :	0.006673s 			0 MB		 [đúng]
test 4 :	0.009077s 			0 MB		 [đúng]
test 5 :	0.009072s 			0 MB		 [đúng]
test 6 :	0.009290s 			0 MB		 [đúng]
test 7 :	0.010386s 			0 MB		 [đúng]
test 8 :	0.011162s 			0 MB		 [đúng]
test 9 :	0.012710s 			0 MB		 [đúng]
test 10 :	0.013299s 			0 MB		 [đúng]
*/
