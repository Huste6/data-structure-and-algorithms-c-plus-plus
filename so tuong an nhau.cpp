#include <bits/stdc++.h>
using namespace std;

bool checkCanAttack(int x1, int y1, int x2, int y2) {
    if (x1 == x2 || y1 == y2) {
        return true;
    }
    if (abs(x2 - x1) == abs(y2 - y1)) {
        return true;
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    while (n--) {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }
    int cnt = 0;
    for (int i = 0; i < v.size(); i++) {
        for (int j = i + 1; j < v.size(); j++) {
            if (checkCanAttack(v[i].first, v[i].second, v[j].first, v[j].second)) {
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}
