#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Hàm tính mảng Z
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
    string s;
    cin >> s;

    vector<int> z = computeZ(s);
    bool allZero = true;

    for (int i = 1; i < z.size(); i++) {
        if (z[i] != 0) {
            allZero = false;
            break;
        }
    }

    if (allZero) {
        cout << "No" << endl;
    } else {
        for (int i = 1; i < z.size(); i++) {
            cout << z[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
