#include<bits/stdc++.h>
using namespace std;
//heapify
//cay nhi phan lá n/2-1 tro ve sau
//xay dung max heap
//thuat toan heap sort la sau khi xay dung max heap thi hoan doi phan tu dau tien voi phan tu cuoi cung
/*The basic steps of the heap sort algorithm are as follows:
1.Build a max heap from the input array.
2.Swap the root (largest element) of the heap with the last element of the heap and decrement the size of the heap by 1.
3.Heapify the root of the heap to restore the heap property.
4.Repeat steps 2 and 3 until the heap is empty.
5.The sorted array will be obtained after the above steps.
*/
void heaptify(int a[],int n,int i){
	int l=2*i+1;
	int r=2*i+2;
	int largest=i;
	if(l<n && a[l]>a[largest]) largest=l;
	if(r<n && a[r]>a[largest]) largest=r;
	//neu node goc chua lon nhat thi swap
	if(largest!=i){
		swap(a[i],a[largest]);
		heaptify(a,n,largest);
	}
}
void heapsort(int a[],int n){
	//xay dung max heap
	for(int i=n/2-1;i>=0;i--){
		heaptify(a,n,i);
	}
	for(int i=n-1;i>=0;i--){
		swap(a[i],a[0]);
		heaptify(a,i,0);
	}
}

int main(){
	int n;cin>>n;
	int a[100];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	heapsort(a,n);
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}
