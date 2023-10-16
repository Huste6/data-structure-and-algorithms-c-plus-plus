#include <bits/stdc++.h>
using namespace std;

const int MAX_LEN = 100;

int n, m, f;
int a[MAX_LEN], sum, x[MAX_LEN];

void print() {
    for (int i = 1; i <= n; i++) {
        cout << x[i] << " ";
    }
    cout << endl;
}

void try1(int i,int sum)
{
	if(i>n){
		if(sum==m){
			print();
		}
		return;
	}
	for(int j=1;j<=m-sum;j++){
		x[i]=j;
		try1(i+1,sum+j);
	}
}

int main() {
    cin >> n;
    cin >> m;
    
    try1(1,0);
    return 0;
}
