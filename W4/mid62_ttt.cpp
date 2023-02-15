#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <utility>

std::vector<int> adj[1010];
std::queue<int> q;  
std::pair<int, int> p[3010];
int visited[1010];


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n, m, a, b, tmp;
    memset(visited, -1, sizeof(visited));
    bool bipartite = true;

    std::cin >> n >> m;
    for (int i = 0; i < m; i++) {
        std::cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        p[i] = std::make_pair(a, b);
    }
    for (int k = 0; k < m; k++) {
        memset(visited, -1, sizeof(visited));
        bool bipartite = true;
        for (int i = 1; i <= n; i++) {
            q.push(i);
            visited[i] = 0;
            while (!q.empty() && bipartite) {
                int x = q.front();
                q.pop();
                for (int j = 0; j < adj[x].size(); j++) {
                    if ((x == p[k].first && adj[x][j] == p[k].second)||(x == p[k].second && adj[x][j] == p[k].first)) {
                        continue;
                    }
                    if (visited[adj[x][j]] == -1) {
                        visited[adj[x][j]] = 1 - visited[x];
                        q.push(adj[x][j]);
                    }                         
                    else if (visited[adj[x][j]] == visited[x]) {
                        bipartite = false;
                        break;
                    }
                }
            }
            if (bipartite) {
                std::cout << p[k].first << " " << p[k].second << "\n";
                goto mew;
            } 
            while (!q.empty()) {
                q.pop();
            }
        } 
    }
    mew:;
    return 0;
}