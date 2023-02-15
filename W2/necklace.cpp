#include <iostream>

int be[100100], af[100100];

int ftail(int x) {
    if (af[x] == x) {
        return x;
    }
    return x = ftail(af[x]);
}

int main() {
    int n, start, end, tail, x;

    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        be[i] = af[i] = i;
    }
    for (int j = 1; j <= n-1; j++) {
        std::cin >> start >> end;
        if(af[end] == end) {
            be[start] = end;
            af[end] = start;
        }
        else if (af[end] != end) {
            tail = ftail(start);
            be[af[end]] = af[tail];
            be[start] = end;
            af[tail] = af[end];
            af[end] = start;
        }
    }
    for (int k = 1; k <= n; k++) {
        if (be[k] == k) {
            x = k;
        }
    }
    std::cout << x << " ";
    while (af[x] != x) {
        x = af[x];
        std::cout << x << " ";
    }
    return 0;
}