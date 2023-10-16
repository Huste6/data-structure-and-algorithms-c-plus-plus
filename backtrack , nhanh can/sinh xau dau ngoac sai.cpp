#include <bits/stdc++.h>
using namespace std;

int n;
vector<char> x;

void print() {
    for (int i = 0; i < 2 * n; i++) {
        cout << x[i];
    }
    cout << endl;
}

bool check(vector<char> x) {
    stack<char> st;
    int tt = 0;
    for (int i = 0; i < 2 * n; i++) {
        if(x[i] == '('){
            st.push(x[i]);
        } else {
            if(st.empty()) return false;
            else{
                st.pop();
            }
        }
    }
    return st.empty();
}

void init(int pos, int opened, int closed) {
    if (pos == 2 * n) {
        x[pos] = '\0';
        if (check(x) == false) {
            print();
        }
        return;
    }

    if (opened < n) {
        x[pos] = '(';
        init(pos + 1, opened + 1, closed);
    }

    if (closed < n) {
        x[pos] = ')';
        init(pos + 1, opened, closed + 1);
    }
}

int main() {
    cin >> n;
    x.resize(2 * n);
    init(0, 0, 0);
    return 0;
}

