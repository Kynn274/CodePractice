#include <bits/stdc++.h>
using namespace std;

vector<char> provide;
string input, substring1("bn"), substring2("nb");
int point(0), x, y;

int main(){
    cin >> input >> x >> y;
    int len = input.size();
    if(x > y){
        for(int i = 0; i < len - 1; i++)
            if(input[i] == 'b' && input[i + 1] == 'n'){
                point += x;
                input.erase(i, 2);
                i-=2;
            }
        len = input.size();
        for(int i = 0; i < len - 1; i++)
            if(input[i] == 'n' && input[i + 1] == 'b'){
                point += y;
                input.erase(i, 2);
                i-=2;
            }
    }else{
        for(int i = 0; i < len - 1; i++)
            if(input[i] == 'n' && input[i + 1] == 'b'){
                point += y;
                input.erase(i, 2);
                i-=2;
            }
        len = input.size();
        for(int i = 0; i < len - 1; i++)
            if(input[i] == 'b' && input[i + 1] == 'n'){
                point += x;
                input.erase(i, 2);
                i-=2;
            }
    }
    
    cout << point;
    return 0;
}

/*
Đúng 18/18
#######################
Thông tin chi tiết
test 1 :	0.007219s 			0 MB		 [đúng]
test 2 :	0.006449s 			0 MB		 [đúng]
test 3 :	0.009668s 			0 MB		 [đúng]
test 4 :	0.187799s 			0 MB		 [đúng]
test 5 :	0.007998s 			0 MB		 [đúng]
test 6 :	0.074470s 			0 MB		 [đúng]
test 7 :	0.037015s 			0 MB		 [đúng]
test 8 :	0.027132s 			0 MB		 [đúng]
test 9 :	0.026986s 			0 MB		 [đúng]
test 10 :	0.080499s 			0 MB		 [đúng]
test 11 :	0.031200s 			0 MB		 [đúng]
test 12 :	0.035186s 			0 MB		 [đúng]
test 13 :	0.028595s 			0 MB		 [đúng]
test 14 :	0.028747s 			0 MB		 [đúng]
test 15 :	0.015594s 			0 MB		 [đúng]
test 16 :	0.014466s 			0 MB		 [đúng]
test 17 :	0.018802s 			0 MB		 [đúng]
test 18 :	0.016845s 			0 MB		 [đúng]

*/
