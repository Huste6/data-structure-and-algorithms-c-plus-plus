#include<iostream>

using namespace std;

bool b[11];
int x[11];
void printArray(int a[], int n){
	for (int i = 1; i <= n; i++){
		cout << a[i];
	}
	cout <<" ";
}
void dequy(int k, int n){
	for (int i = 1; i <= n; i++){
		if (b[i]){
			x[k] = i;
			if (k == n){
				printArray(x, n);
			} else {
				b[i] = false;
				dequy(k+1, n);
				b[i] = true;
			}
		}
	}
}
int main(){
	int n;
	cin >> n;
	for (int i = 1; i <=n; i++){
		b[i] = true;
	}
	dequy(1, n);
}
