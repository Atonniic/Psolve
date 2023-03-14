#include<iostream>
#include<queue>
#include<vector>

struct A{
    int v,dis,t;
};
std::queue<A> bfs;
std::vector<int> g[100100];
std::queue<int> q;
int visited[100100][5];

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n, m, k, h, u, v, dis, t, res=0;

    std::cin >> n >> m >> k >> h;
    h = h*2;
    for (int i = 0; i < k; i++) {
        std::cin >> u;
        q.push(u);
    }
    for (int i = 0; i < k; i++) {
        std::cin >> u;
        v = q.front();
        q.pop();
        if (u == 0) {
            u = 2;
        }
        bfs.push({v, 0, u});
    }
    
    for(int i = 0; i < m; i++) {
        std::cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    while(!bfs.empty()){
        u = bfs.front().v;
        dis = bfs.front().dis;
        t = bfs.front().t;
        bfs.pop();

        if(visited[u][t]) {
            continue;
        }
        if (!visited[u][2] && !visited[u][1]) {
            res++;
        }
        visited[u][t] = 1;
        if (dis == h) {
            continue;
        }
        for (auto x: g[u]) {
            bfs.push({x, dis+t, t});
        }
    }
    std::cout << res << "\n";
    return 0;
}