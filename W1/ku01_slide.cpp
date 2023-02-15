#include <iostream>

int a[301];

int main() {
    int n, count = 0, tmp, k = 0;

    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int j = 0; j < n; j++) {
        k = j;
        tmp = a[j];
        while (true) {
            if (k == n-1) {
                break;
            }
            if (a[k+1] > tmp) {
                count++;
            }
            k++;
        }
    }
    std::cout << count << std::endl;
}