#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
//ap dung cho set,map hoac cac mang da duoc sap xep
//lower_bound(iter1,iter2,x) - tra ve vi tri cua phan tu dau tien => key
//neu tat ca ca phan tu trong mang deu nho hon key thi tra ve iter2 
//upper_bound(iter1,iter2,x) - tra ve vi tri cua phan tu dau tien > key

// 7 2
// 1 2 2 3 4 5 6


int main(){
	int n,x;cin>>n>>x;
	int a[n];
	for(int &x:a) cin>>x;
	sort(a,a+n);
	auto it=lower_bound(a,a+n,x);
	// tim vi tri dau tien cua phan tu >= x nam tron mang a
	cout<<*it<<endl;
	if(it==(a+n)) cout<<"khong co phan tu nao trong mang >= "<<x<<endl;
	//neu la vector thi chuyen thanh a.begin(), a.end();
	
	return 0;
}
