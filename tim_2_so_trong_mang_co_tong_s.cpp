#include <iostream>
#include <unordered_map>
#include <algorithm>

int main() {
    int n, s;
    std::cin >> n >> s;

    int a[n + 1];
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }

    std::unordered_map<int, int> mp;
    for (int i = 1; i <= n; i++) {
        mp[a[i]] = i;
    }

    std::sort(a + 1, a + n + 1);

    int l = 1, r = n;
    while (l < r) {
        if (a[l] + a[r] == s) {
            if(mp[a[l]]<mp[a[r]]){
            	std::cout << mp[a[l]] << " " << mp[a[r]];
            	break;
			}else{
				std::cout << mp[a[r]] << " " << mp[a[l]];
            	break;
			}
        } else if (a[l] + a[r] > s) {
            r--;
        } else {
            l++;
        }
    }

    return 0;
}
