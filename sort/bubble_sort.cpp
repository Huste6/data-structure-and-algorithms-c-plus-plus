#include <iostream>

void BubbleSort(int a[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (a[j] > a[j + 1]) {
                std::swap(a[j], a[j + 1]);
            }
        }
    }
}

int main() {
    int size;
    std::cin >> size;

    int a[size];
    for (int i = 0; i < size; ++i) {
        std::cin >> a[i];
    }

    BubbleSort(a, size);

    for (int i = 0; i < size; i++) {
        std::cout << a[i] << " ";
    }

    return 0;
}
