#include <iostream>
#include <queue>
#include <algorithm>

struct A {
    int l, r;
    bool operator < (const A&o) const {
        if (l != o.l) {
            return l < o.l;
        }
        return r < o.r;
    }
};
std::queue<A> res;
A arrey[100100];


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int i, j, q, count, now, m, ll, rr, mx;
    std::cin >> q;
    while(q--) {
        count = 0; 
        now = 0;
        std::cin >> m;
        while(1) {
            std::cin >> arrey[count].l >> arrey[count].r;
            if (arrey[count].l == 0 && arrey[count].r == 0) {
                break;
            }
            if (arrey[count].r < 0) {
                continue;
            }
            count++;
        }
        std::sort(arrey, arrey+count);
        for (i = 0; i < count;) {
            if (now >= m) {
                break;
            }
            mx = -1;
            for (j = i; j < count; j++) {
                if (arrey[j].l > now) {
                    break;
                } 
                if (arrey[j].r > mx) {
                    mx = arrey[j].r;
                    ll = arrey[j].l;
                    rr = arrey[j].r;
                }
            }
            if (mx == -1) {
                std::cout << "0\n";
                goto pass;
            }
            now = mx;
            res.push({ll, rr});
            i = j;
        }
        if (now < m) {
            std::cout << "0\n";
            goto pass;
        }
        std::cout << res.size() << "\n";
        while(!res.empty()) {
            std::cout << res.front().l << " " << res.front().r << "\n";
            res.pop();
        }
        pass:;
        while(!res.empty()) {
            res.pop();
        }
        if (q) {
            std::cout << "\n";
        }
    }
    return 0;
}