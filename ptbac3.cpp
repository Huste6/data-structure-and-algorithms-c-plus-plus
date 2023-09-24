#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define REP(i,a,b) for(int i = a; i <= b; ++i)
#define DREP(i,a,b) for(int i = a; i >= b; --i)
using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

int a, b, c;
int polynomial(int x)
{
    return x*x*x + x*x*a + b*x + c;
}
int main()
{
    cin >> a >> b >> c;
    vector<int> x;
    REP(i, min({a,b,c}), max({a,b,c}))
        if(polynomial(i) == 0)
            x.push_back(i);
    if(x.empty())
    {
        cout << "NO SOLUTION" << endl;
        return 0;
    }
    else if(x.size() == 3)
    {
        sort(all(x));
        for(int i : x)
            cout << i << ' ' << 1 << endl;
    }
    else
    {
        sort(all(x));
        if(x[0]*x[0]*x[1] == -c)
        {
            cout << x[0] << ' ' << 2 << endl;
            cout << x[1] << ' ' << 1 << endl;
        }
        if(x[1]*x[1]*x[0] == -c)
        {
            cout << x[0] << ' ' << 1 << endl;
            cout << x[1] << ' ' << 2 << endl;
        }
    }
}
