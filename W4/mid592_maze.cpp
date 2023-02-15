#include <iostream>

char a[30][30];

int main() {
    int n, q;

    std::cin >> n >> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> a[i][j];
        }
    }
    for (int i = 0; i < q; i++) {
        int r, c, a, b;
        std::cin >> r >> c >> a >> b;
        
}