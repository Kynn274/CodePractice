#include <bits/stdc++.h>
using namespace std;

int n;
string x;
string text;
stack<string> s;

void show(stack<string> s){
    stack<string> tmp;
    while(!s.empty()){
        tmp.push(s.top());
        s.pop();
    }
    if(!tmp.empty())
        while(!tmp.empty()){
            cout << tmp.top();
            tmp.pop();
        }
    else cout << "empty";
}

int main(){
    cin >> n;
    while(n--){
        cin >> x;
        if(x == "type"){
            cin >> text;
            s.push(text);
        }else if(x == "undo")
            if(!s.empty()) s.pop();
    }
    
    show(s);
    return 0;
}

/*
Đúng 10/10
#######################
Thông tin chi tiết
test 1 :	0.006058s 			0 MB		 [đúng]
test 2 :	0.006428s 			0 MB		 [đúng]
test 3 :	0.005997s 			0 MB		 [đúng]
test 4 :	0.005708s 			0 MB		 [đúng]
test 5 :	0.005925s 			0 MB		 [đúng]
test 6 :	0.007608s 			0 MB		 [đúng]
test 7 :	0.005758s 			0 MB		 [đúng]
test 8 :	0.005925s 			0 MB		 [đúng]
test 9 :	0.006186s 			0 MB		 [đúng]
test 10 :	0.005862s 			0 MB		 [đúng]
*/
