#include <iostream>

int main() {
    int n , m, sum = 0;

    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> m;
        if (m >= 0) {
            sum = sum + m;
        }
        else {
            sum = sum;
        }
    }
    std::cout << sum << std::endl;
}