#include <iostream>
#include <queue>
#include <vector>
struct A {
    int v, dis, c;
};
std::vector<A> g[100100];
int visit[100100][5],magic[100100];
std::queue<A> bfs;

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m, u, v, h, c, k, ans=0, dis;
    std::cin >> n >> m >> k >> h;
    for (int i = 0; i < k; i++) {
        std::cin >> u;
        magic[u] = 1;
    }
    for (int i = 0; i < m; i++) {
        std::cin >> u >> v >> c;
        g[u].push_back({v, 0, c});
        g[v].push_back({u, 0, c});
    }
    bfs.push({1, 0, 0});
    while(!bfs.empty()) {
        u = bfs.front().v;
        dis = bfs.front().dis;
        c = bfs.front().c;
        bfs.pop();
        if (magic[u]) {
            c = 1;
        }
        if (visit[u][c]) {
            continue;
        }
        if (!visit[u][0] && !visit[u][1]) {
            ans++;
        }
        visit[u][c] = 1;
        if (dis == h) {
            continue;
        }
        for (auto x: g[u]) {
            if (visit[x.v][c]) {
                continue;
            }
            if (c == 0 && x.c == 1) {
                continue;
            }
            bfs.push({x.v, dis+1, c});
        }
    }
    std::cout << ans << "\n";
    return 0;
}