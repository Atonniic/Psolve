#include <iostream>

int a[100100];

int main() {
    int count = 0;
    long long n, k, tmp = 1000000000;
    
    std::cin >> n >> k;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        if (a[i] < tmp) {
            tmp = a[i];
        }
    }
    for (int j = 0; j < n; j++) {
        if (((1.00 * tmp * k)/a[j]) > k-1) {
            count++;
        }
    }
    std::cout << count << std::endl;
}