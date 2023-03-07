#include <iostream>
#include <queue>
#include <vector>

struct A {
    int v, w;
    bool operator<(const A&o) const {
        return w > o.w;
    }
};

std::vector<A> g[100100];
std::priority_queue<A> q;
int dis[100100];

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n, m, a, b, w;
    std::cin >> n >> m;
    for (int i = 0 ; i < m; i++) {
        std::cin >> a >> b >> w;
        g[a].push_back({b, w});
        g[b].push_back({a, w});
    }
    q.push({1, 0});
    while(!q.empty()) {
        a = q.top().v;
        w = q.top().w;
        q.pop();
        if (a == n) {
            std::cout << w << "\n";
            return 0;
        }
        if (dis[a] != 0) {
            continue;
        }
        dis[a] = w;
        for (auto x: g[a]) {
            if (dis[x.v] != 0) {
                continue;
            }
            q.push({x.v, w+x.w});
        }
    }
    return 0;
}