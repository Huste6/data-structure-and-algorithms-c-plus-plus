#include<bits/stdc++.h>
using namespace std;
//1 2 7 4 3 6
//    j     i
//1
//1 2 --> 2>1 --> loai 1
//2 7 --> 7>2 --> loai 2
//7 4 --> 4<7
//7 4 3 
//7 4 3 6 --> 6>3 && 6>4 --> loai 3 4
//7 6
void solve(int a[],int n){
	stack<int> st;
	for (int i = 1; i <= n; ++i)
	{
	    while (!st.empty() && a[st.top()] <= a[i])
	        st.pop(); 
	    int ans = -1;
	    if (!st.empty())
	        ans = st.top();
	    cout << ans << ' ';
	    st.push(i);
	}
}
int main(){
	int n;cin>>n;
	int a[n];
	for(int &x:a) cin>>x;
	solve(a,n);
	return 0;
}
