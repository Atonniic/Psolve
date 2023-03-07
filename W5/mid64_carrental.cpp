#include <iostream>

struct A {
    int c, p, w;
};
A contract[110];
int parcel[1010];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int k, n, max_parcel = -1, min_cost = 2e9;

    std::cin >> k >> n;
    for (int i = 0; i < k; i++) {
        std::cin >> contract[i].c >> contract[i].p >> contract[i].w;
    }
    for (int i = 0; i < n; i++) {
        std::cin >> parcel[i];
        max_parcel = std::max(max_parcel, parcel[i]);
    }
    for (int i = 0; i < k; i++) {
        if (max_parcel > contract[i].w) {
            continue;
        }
        int sum = 0, count = 0;
        for (int j = 0; j < n; j++) {
            sum += parcel[j];
            if (sum > contract[i].w) {
                count++;
                sum = parcel[j];
            }
        }
        count++;
        min_cost = std::min(min_cost,contract[i].c + count * contract[i].p);
    }
    std::cout << min_cost << "\n";
    return 0;
}
