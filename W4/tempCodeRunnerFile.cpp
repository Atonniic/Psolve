#include <iostream>
#include <algorithm>

struct A{
    int d, c;

    bool operator < (const A&o) const{
        if( d!= o.d) {
            return d < o.d;
        }
        return c < o.c;
    }
};

A a[100010];

int main() {
    int n, res, now;

    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i].d >> a[i].c;
        a[i].d += 10;
    }
    std::sort(a, a+n);
    now = 0;
    for (int i = 0; i < n; i++) {
        now += a[i].c;
        if (now >= a[i].d < now) {
            res = std::max(res, (now - a[i].d)*1000);
        }
    }
    std::cout << res << "\n";
    return 0;
}