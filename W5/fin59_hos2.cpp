#include <iostream>
#include <queue>
#include <vector>

struct A{
    int u, v, dis;
};
std::queue<A> bfs;
std::vector<int> g[1010];
int mark[1010][1010], safe[1010];

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n, m, h, a, b, dis, Mx = -1;

    std::cin >> n >> m >> h;
    for (int i = 0; i < m; i++) {
        std::cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        bfs.push({i, i, 0});
    }
    while(!bfs.empty()){
        a = bfs.front().u;
        b = bfs.front().v;
        dis = bfs.front().dis;
        bfs.pop();
        if (mark[a][b]) {
            continue;
        }
        safe[a]++;
        mark[a][b] = 1;
        if (dis == h) {
            continue;
        }
        for (auto x: g[b]) {
            if (mark[a][x]) {
                continue;
            }
            bfs.push({a, x, dis+1});
        }
    }
    int i = 1;
    while (i<=n) {
        Mx = std::max(Mx, safe[i]);
        i++;
    }
    std::cout << Mx << "\n";
    return 0;
}