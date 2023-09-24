/*cach 1:#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;cin>>n;
	int a[n];
	for(int &x:a) cin>>x;
	for(int i=0;i<n;i++){
		int x=a[i],pos=i-1;
		while(pos>=0 &&a[pos]>x){
			a[pos+1]=a[pos];
			--pos;
		}
		a[pos+1]=x;
		cout<<"Buoc "<<i<<": ";
		for(int j=0;j<=i;j++){
			cout<<a[j]<<" ";
		}  
		cout<<endl;
	}
}*/

#include <bits/stdc++.h> 
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int &x : a)
        cin >> x;
    deque<int> dq;
    dq.push_back(a[0]);
    cout << "buoc 0: " << a[0] << endl;

    for(int i=1; i<n; i++){
        if(a[i] < dq.front())
            dq.push_front(a[i]);
        else{
            int pos = 0;
            while(pos < i && dq[pos] <= a[i])
                pos++;
            dq.insert(dq.begin() + pos, a[i]);
        }
        cout << "buoc " << i << ": ";
        for(int j=0; j<=i; j++){
            cout << dq[j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}


