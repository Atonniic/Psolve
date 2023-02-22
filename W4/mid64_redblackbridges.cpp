#include <iostream>
#include <vector>
#include <queue>

int mark[50100][5];

struct B{
    int v,c,dis;
};
struct A{
    int v, c;    
};
std::vector<A> g[50100];
std::queue<B> bfs;

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n, m, s, t, a, b, c;

    std::cin >> n >> m >> s >> t;
    for(int i = 0; i < m; i++) {
        std::cin >> a >> b >> c;
        g[b].push_back({a,c});
        g[a].push_back({b,c});
    }
    bfs.push({s, 2, 0});
    bfs.push({s, 1, 0});
    while(!bfs.empty()){
        auto now = bfs.front();
        bfs.pop();
        if (mark[now.v][now.c] == 1) {
            continue;
        }
        mark[now.v][now.c] = 1;
        if (now.v == t) {
            std::cout << now.dis << "\n";
            return 0;
        }
        for (auto x: g[now.v]) {
            if (now.c == 2) {
                if (x.c == 1) {
                    continue;
                }
                bfs.push({x.v, 2, now.dis+1});
            }
            else if (now.c == 1) {
                if (x.c == 2) {
                    continue;
                }
                bfs.push({x.v, 1, now.dis+1});
            }
        }
    }
    std::cout << "-1\n";
    return 0;
}