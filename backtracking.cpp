
#include <iostream>
using namespace std;

int n = 4;  // s? lu?ng bi?n
int target = 60; // giá tr? c?n d?t du?c
int count = 0; // s? lu?ng nghi?m
int constant[] = {2, 4, 3, 5}; // h? s? tuong ?ng v?i t?ng bi?n
int sum[4] = {0}; // m?ng giá tr? hi?n t?i c?a các bi?n

void backtracking(int index, int current_sum) {
    if (current_sum == target && sum[0] + sum[1] == 6 && sum[0] > 0 && sum[1] > 0) {
        count++;
        return;
    }
    if (index == n || current_sum >= target) {
        return;
    }
    for (int i = 0; i <= target; i++) {
        sum[index] = i;
        backtracking(index + 1, current_sum + constant[index] * i);
        sum[index] = 0;
    }
}

int main() {
    backtracking(0, 0);
    cout << "Number of positive integer solutions: " << count << endl;
    return 0;
}

