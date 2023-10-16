#include<bits/stdc++.h>
using namespace std;
double limit;
bool check(double k, vector<int>& dist) {
    double t = 0;
    for (double d: dist) {
        t = ceil(t);
        t += d / k;
    }
    return t <= limit;
}
int minSpeedOnTime(vector<int>& dist, double hour) {
    if (dist.size() > ceil(hour)) {
        return -1;
	}
        
    limit = hour;
    int left = 1;
    int right = pow(10, 7);
        
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (check(mid, dist)) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
        
    return left;
}
    

int main(){
	vector<int> dist={11,5,8};
	cout<<minSpeedOnTime(dist,3.9);
	return 0;
}
