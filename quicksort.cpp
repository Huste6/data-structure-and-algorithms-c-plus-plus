#include <bits/stdc++.h>
using namespace std;

// phan hoach lomuto
int partition(int a[], int l, int r) {
    int pivot = a[r];
    int i = l - 1;// bat dau tu tru -1
    for(int j = l; j < r; j++) {
        if(a[j] <= pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i+1], a[r]);
    return i + 1;
}

void quicksort(int a[], int l, int r) {
    if(l >= r) return;
    int p = partition(a, l, r);
    quicksort(a, l, p-1);
    quicksort(a, p+1, r);
}
//phan hoach hoare
int partition1(int a[],int l,int r){
	int pivot=a[l];
	int i=l-1,j=r+1;
	while(1){
		do{
			++i;
		}while(a[i]<pivot);
		do{
			--j;
		}
		while(a[j]>pivot);
		if(i<j){
			swap(a[i],a[j]);
		}
		else return j;
	}
}
void quicksort1(int a[],int l,int r){
	if(l>=r) return;
	int p=partition1(a,l,r);
	quicksort1(a,l,p);
	quicksort1(a,p+1,r);
}
int main() {
    int arr[] = { 10, 7, 8, 9, 1, 5 };
    int N = sizeof(arr) / sizeof(arr[0]);
    quicksort1(arr, 0, N - 1);
    cout << "Sorted array: " << endl;
    for(int i = 0; i < N; i++)
        cout << arr[i] << " ";
    return 0;
}
