#include <iostream>
#include <vector>
using namespace std;
/*Cho m?ng nh? phân nums và cho s? nguyên k.

B?n hãy tìm m?ng con có d? dài l?n nh?t mà ch? ch?a các bit s? 1 sau khi th?c hi?n t?i da k l?n l?t các bit s? 0 thành bit s? 1 trong m?ng con dó. Ð?u ra hi?n th? d? dài c?a m?ng con tho? mãn.*/
int longestOnes(vector<int>& nums, int k) {
    int left = 0, right = 0; // Ðau và cuoi cua mang con c?n tìm
    int zeroCount = 0; // S? lu?ng bit s? 0 dã l?t trong m?ng con
    int maxLength = 0; // Ð? dài l?n nh?t c?a m?ng con

    while (right < nums.size()) {
        if (nums[right] == 0) {
            zeroCount++;
        }
        
        // N?u s? lu?ng bit s? 0 dã l?t l?n hon k, c?n di chuy?n left sang ph?i
        while (zeroCount > k) {
            if (nums[left] == 0) {
                zeroCount--;
            }
            
            left++;
        }
        
        // Ki?m tra n?u d? dài c?a m?ng con hi?n t?i l?n hon maxLength
        maxLength = max(maxLength, right - left + 1);
        
        right++;
    }

    return maxLength;
}

int main() {
    int n, k;
    //cout << "Nhap so luong phan tu cua mang: ";
    cin >> n;
    //cout << "Nhap mang nh? phân: ";
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Nhap so nguyen k: ";
    cin >> k;

    int result = longestOnes(nums, k);
    cout << "Do dai lon nhat cua mang con chi chua bit 1 sau khi lat " << k << " lan: " << result;
    return 0;
}


