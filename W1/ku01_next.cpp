#include <iostream>

int num[100100];
int count[100100];

int main() {
    int n, k = 0, res = 0, c = 0;

    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        std::cin >> num[i];
    }
    for (int j = 1; j <= n; j++) {
        k = j;
        if (count[j] == 0) {
            c = 0;
            while (true) {
                if (count[k] == 1) {
                    break;
                }
                if (count[k] == 0) {
                    count[k] = 1;
                    k = num[k];
                }
                c++;
            }
        }
        if (c > res) {
            res = c;
        }
    }
    std::cout << res << std::endl;
}