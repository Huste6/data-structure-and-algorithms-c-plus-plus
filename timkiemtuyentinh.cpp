#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
//linear search o(n)
//10 3
//1 2 8 9 0 7 6 5 3 4
bool ls(int a[],int n,int x){
	for(int i=0;i<n;i++){
		if(a[i]==x) return true;
	}
	return false;
}
//binary search o(log(n))
//cac phan tu trong mang phai duoc sap xep tang dan hoac giam dan
//10 3
//1 2 3 4 5 6 7 8 9 10
bool bs(int a[],int n,int x){
	int l=0,r=n-1;
	while(l<=r){
		int mid=(l+r)/2;
		if(a[mid]==x){
			return true;
		}else if(a[mid]<x){
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	return false;
}
bool binary_search1(int a[], int l, int r, int x) {
    if (l > r)
        return false;
    int mid = (l + r) / 2;
    if (a[mid] == x)
        return true;
    else if (a[mid] < x)
        return binary_search1(a, mid + 1, r, x);
    else
        return binary_search1(a, l, mid - 1, x);
}
//tim vi tri dau tien xuat hien x
int binary_search2(int a[],int n,int x){
	int res=-1;
	int l=0,r=n-1;
	while(l<=r){
		int mid=(l+r)/2;
		if(a[mid]==x){
			res=mid;
			r=mid-1;//tim them o ben trai con khong
		}else if(a[mid]<x){
			l=mid+1;
		}else{
			r=mid-1;
		}
	}return res;
}
//vi tri xuat hien phan tu x cuoi cung
int binary_search3(int a[],int n,int x){
	int res=-1;
	int l=0,r=n-1;
	while(l<=r){
		int m=(l+r)/2;
		if(a[m]==x){
			res=m;
			l=m+1;//tim them o ben phai coi con khong
		}else if(a[m]<x) l=m+1;
		else r=m-1;
	}return res;
}
int main(){
	int n,x;cin>>n>>x;
	//int a[n];
	//for(int i=0;i<n;i++){
	//	cin>>a[i];
	//}
	//sort(a,a+n);
	//if(bs(a,n,x)) cout<<"found\n";
	//else cout<<"not found\n";
	//if(binary_search(a,a+n,x)) cout<<"found\n";
	//else cout<<"not found\n";
	/*vector<int> v(n);
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	sort(v.begin(),v.end());
	if(binary_search(v.begin(),v.end(),x)) cout<<"found\n";
	else cout<<"not found\n";
	*/
	int a[n];
	for(int &i:a) cin>>i;
	cout<<binary_search2(a,n,3)<<endl;
	cout<<binary_search3(a,n,3)<<endl;
	return 0;
}
