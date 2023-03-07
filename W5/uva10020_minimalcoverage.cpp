#include <iostream>
#include <algorithm>
#include <queue>

struct A {
    int l,r;
    bool operator < (const A&o) const {
        if (l != o.l) {
            return l < o.l;
        }
        return r < o.r;
    }
};
A a[100100];
std::queue<A> res;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int j, q, m, ll, rr, Mx;
    std::cin >> q;
    while(q--) {
        int cou = 0, now = 0;
        std::cin >> m;
        while(1) {
            std::cin >> a[cou].l >> a[cou].r;
            if (a[cou].r==0 && a[cou].l==0) {
                break;
            }
            if (a[cou].r < 0) {
                continue;
            }
            cou++;
        }
        std::sort(a, a+cou);
        for (int i = 0; i < cou;) {
            if (now >= m) {
                break;
            }
            Mx = -1;
            for (j = i; j < cou; j++) {
                if (a[j].l > now) {
                    break;
                }
                if (a[j].r > Mx) {
                    ll = a[j].l;
                    rr = a[j].r;
                    Mx = a[j].r;
                }
            }
            if (Mx == -1) {
                std::cout << "0\n";
                goto Next;
            }
            now = Mx;
            res.push({ll, rr});
            i = j;
        }
        if (now < m) {
            std::cout << "0\n";
            goto Next;
        }
        std::cout << res.size() << "\n";
        
        while(!res.empty()) {
            std::cout << res.front().l << " " << res.front().r << "\n";
            res.pop();
        }
        Next:;
        while(!res.empty()) {
            res.pop();
        }
        if (q) {
            std::cout << "\n";
        }
    }
    return 0;
}