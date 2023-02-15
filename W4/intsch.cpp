#include <iostream>
#include <algorithm>

struct A{
    int start, end;

    bool operator < (const A&o) const{
        if(end != o.end) {
            return end < o.end;
        }
        return start < o.start;
    }
};

A a[100010];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n, s, t, now = 0, cou = 0;

    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i].start >> a[i].end;
    }
    std::sort(a, a+n);
    for (int i = 0; i < n; i++) {
        if (a[i].start >= now) {
            now = a[i].end;
            cou++;
        }
    }
    std::cout << cou << "\n";
    return 0;
}