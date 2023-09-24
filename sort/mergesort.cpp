#include<bits/stdc++.h>
using namespace std;
//merge 2 ham 
void merge(int a[], int l, int m, int r) {
    vector<int> x(a + l, a + m + 1);
    vector<int> y(a + m + 1, a + r + 1);
    int i = 0, j = 0;
    int k = l; 
    while (i < x.size() && j < y.size()) {
        if (x[i] <= y[j]) {
            a[k] = x[i];
            i++;
        }else{
            a[k] = y[j];
            j++;
        }
        k++;
    }
    while (i < x.size()) {
        a[k] = x[i];
        i++;
        k++;
    }
    while (j < y.size()) {
        a[k] = y[j];
        j++;
        k++;
    }
}

void mergeSort(int a[], int l, int r) {
    if(l>=r) return;
	if (l < r) {
        int m = (l+r)/2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    mergeSort(a, 0, n - 1);
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    return 0;
}
