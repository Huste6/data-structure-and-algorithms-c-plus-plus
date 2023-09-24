#include<bits/stdc++.h>
#include<set>
using namespace std;
//find
//count
//erase
//multiset<>
//unordered_set
int main(){
	//set<int> s;
	//s.insert(100);
	//for(int i=0;i<10;i++){
	//	s.insert(i);
	//}
	//set<int>::iterator itr=s.find(val); so sanh itr voi s.end() neu khac thi dung con khong thi sai
	//cout<<s.size()<<endl;
	//s.erase(5);
	//if(s.count(5) != 0) cout<<"found!\n";
	//else cout<<"not found!\n";
	//for(auto x:s){
	//	cout<<x<<" ";
	//}
	//cout<<*s.begin()<<endl;
	//cout<<*s.rbegin()<<endl;//phan tu cuoi cung
	//bai toan dem so luong phan tu khac nhau
	//multiset<int> ms;//thu tu se duoc sap xep tu be den lon
	/*cho mang co n phan tu va so nguyen k, doi voi ot day con lien tiep co chieu dai k . hay in ra duoc phan tu lon nhat trong day con do
	input:10 3
	1 2 3 1 4 5 1 8 9 10
	output: 3 3 4 5 8 9 10
	*/
	/*int n,k;
	cin>>n>>k;
	int a[n];
	for(int &x:a) cin>>x;
	multiset<int> ms;
	for(int i=0;i<k;i++){
		ms.insert(a[i]);
	}
	for(int i=k;i<n;i++){
		cout<<*ms.rbegin()<<" ";
		ms.erase(ms.find(a[i-k]));
		ms.insert(a[i]);
	}*/
	unordered_set<int> s;// thu tu khong thay doi
	
}
