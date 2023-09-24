#include <iostream>
#include <vector>
using namespace std;
/*Cho m?ng nh? ph�n nums v� cho s? nguy�n k.

B?n h�y t�m m?ng con c� d? d�i l?n nh?t m� ch? ch?a c�c bit s? 1 sau khi th?c hi?n t?i da k l?n l?t c�c bit s? 0 th�nh bit s? 1 trong m?ng con d�. �?u ra hi?n th? d? d�i c?a m?ng con tho? m�n.*/
int longestOnes(vector<int>& nums, int k) {
    int left = 0, right = 0; // �au v� cuoi cua mang con c?n t�m
    int zeroCount = 0; // S? lu?ng bit s? 0 d� l?t trong m?ng con
    int maxLength = 0; // �? d�i l?n nh?t c?a m?ng con

    while (right < nums.size()) {
        if (nums[right] == 0) {
            zeroCount++;
        }
        
        // N?u s? lu?ng bit s? 0 d� l?t l?n hon k, c?n di chuy?n left sang ph?i
        while (zeroCount > k) {
            if (nums[left] == 0) {
                zeroCount--;
            }
            
            left++;
        }
        
        // Ki?m tra n?u d? d�i c?a m?ng con hi?n t?i l?n hon maxLength
        maxLength = max(maxLength, right - left + 1);
        
        right++;
    }

    return maxLength;
}

int main() {
    int n, k;
    //cout << "Nhap so luong phan tu cua mang: ";
    cin >> n;
    //cout << "Nhap mang nh? ph�n: ";
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


