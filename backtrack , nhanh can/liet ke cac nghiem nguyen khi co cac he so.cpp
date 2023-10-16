/*#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;
int n, x[MAX], sum, m, a[MAX];

void print() {
    for(int i = 0; i < n; i++) {
        cout << x[i] << " ";
    }
    cout << endl;
}

void try1(int k, int sum) {
    for(int i = 0; i <= (m - sum) / a[k]; i++) {
        if(sum + i * a[k] <= m) {
            sum+=i*a[k];
            x[k] = i;
            if(k == n - 1 && sum + i * a[k] == m) {
                print();
            } else {
                try1(k + 1, sum + i * a[k]);
            }
            sum-=i*a[k];
        }
    }
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    try1(0, 0);
    return 0;
}*/

#include<bits/stdc++.h>
using namespace std;
const int MAXN=100;
int a[MAXN],x[MAXN];
int n,M;
void backtrack(int i,int sum)
{
    if(i>n)
    {
        if(sum==M)
        {
            for(int j=1;j<=n;j++){
                cout<<x[j]<<" ";
            }
            cout<<endl;
        }
        return;
    }
    for(int j=0;j<=M-sum;j++){
        x[i]=j;
        backtrack(i+1,sum+j*a[i]);
    }
}
int main(){
    cin>>n>>M;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    backtrack(1,0);
    return 0;
}

