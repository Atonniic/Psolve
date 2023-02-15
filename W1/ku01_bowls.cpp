#include <iostream>

int a[100100];

int main() {
    int n, in_put, res = 0;
     
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> in_put;
        a[in_put]++;
    }
    for (int j = 0; j < 301; j++) {
        if (a[j] > res) {
            res = a[j];
        }
    }
    std::cout << res << std::endl;
}