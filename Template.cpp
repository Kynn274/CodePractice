#include <iostream>
#include <algorithm>

using namespace std;

string multiplyLargeNumber(const string &num, int multiplier){
    string result = "";
    int carry = 0;
    
    for (int i = num.size() - 1; i >= 0; i--) {
        int product = (num[i] - '0') * multiplier + carry;
        result.push_back(product % 10 + '0');
        carry = product / 10;
    }
    
    while(carry){
        result.push_back(carry % 10 + '0');
        carry /= 10;
    }
    
    reverse(result.begin(), result.end());
    return result;
}

int main(){
    string giaBan, chiPhi;
    string danSo = "985100000000";
    cin >> giaBan >> chiPhi;
    
    // Convert giaBan from string to integer
    int giaBanInt = stoi(giaBan);
    string tongTien = multiplyLargeNumber(danSo, giaBanInt);
    
    cout << "Result: " << tongTien << endl;
    return 0;  // Fixed typo in 'return'
}