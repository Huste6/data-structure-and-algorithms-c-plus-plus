#include <iostream>
#include <cmath>

using namespace std;

int getCandidate(int n, int k) {
    int count = 0;
    while (n >= k) {
        n = n / k;
        count++;
    }
    return pow(k, count);
}

int main() {
    int n, k;
    cin >> n >> k;
    cout << getCandidate(n, k) << endl;
    return 0;
}
