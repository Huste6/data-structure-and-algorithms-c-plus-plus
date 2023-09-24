
#include <iostream>
#include <unordered_map>
using namespace std;
//tim ky tu xuat hien cuoi cung
int bsofendindex(string s, char target) {
    int l = 0;
    int r = s.size() - 1;
    int res = -1;
    while (l <= r) {
        int m = (l + r) / 2;
        if (s[m] != target) {
            l = m + 1;
        } else {
            res = m;
            l = m + 1;
        }
    }
    return res;
}

unordered_map<char, int> countchar(string s) {
    unordered_map<char, int> charCount;
    for (char ch : s) {
        charCount[ch]++;
    }
    return charCount;
}

int main() {
    string s;
    cin >> s;
    unordered_map<char, int> charCount = countchar(s);
    
    int cnt = 0;
    for (auto it : charCount) {
        if (it.second != 0) {
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}

