#include <iostream>

int arrey_int[330];

int main() {
    int l, n, a, b, m;

    std::cin >> l >> n;
    for (int i = 0; i < n; i++){
        std::cin >> a >> b;
        arrey_int[a]++;
        arrey_int[b]--;
    }
    m = arrey_int[0];
    for(int j = 1; j <= l; j++){
        arrey_int[j] += arrey_int[j-1];
        m = std::max(m, arrey_int[j]);
    }
    std::cout << m;
    return 0;
}