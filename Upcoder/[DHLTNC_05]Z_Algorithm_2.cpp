#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Tính mảng Z cho chuỗi s
vector<int> computeZ(string s) {
    int n = s.length();
    vector<int> z(n);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (i <= r)
            z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            z[i]++;
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}

int main() {
    string T, P;
    getline(cin, T);  // Đoạn văn bản T
    getline(cin, P);  // Chuỗi cần tìm P

    string S = P + "#" + T;  // Gộp lại để dùng Z-algorithm
    vector<int> z = computeZ(S);

    vector<int> result;
    int pLen = P.length();
    for (int i = pLen + 1; i < z.size(); i++) {
        if (z[i] == pLen) {
            result.push_back(i - pLen - 1);
        }
    }

    if (result.empty()) {
        cout << "No" << endl;
    } else {
        for (int i = 0; i < result.size(); i++) {
            cout << "Vi tri: " << result[i];
            if (i != result.size() - 1) cout << " ";
        }
        cout << endl;
    }

    return 0;
}
