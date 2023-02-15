#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

std::vector<int> a[100100];
std::queue<int> q;
int visited[100100];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int k, n, m, u, v;
    
    std::cin >> k;
    for (int i = 0; i < k; i++) {
        memset(visited, -1, sizeof(visited));
        bool bipartite = true;
        std::cin >> n >> m;
        for (int j = 0; j < m; j++) {
            std::cin >> u >> v;
            a[u].push_back(v);
            a[v].push_back(u);
        }
        q.push(1);
        visited[1] = 0;
        while (!q.empty() && bipartite) {
            int x = q.front();
            q.pop();

            for (int j = 0; j < a[x].size(); j++) {
                if (visited[a[x][j]] == -1) {
                    visited[a[x][j]] = 1 - visited[x];
                    q.push(a[x][j]);
                } 
                else if (visited[a[x][j]] == visited[x]) {
                    bipartite = false;
                    goto mew;
                }
            }
        }
        mew:;
        if (bipartite) {
                std::cout << "yes" << "\n";
        } 
        else {
                std::cout << "no" << "\n";
        }
        while (!q.empty()) {
            q.pop();
        }
        for(int i = 1; i <= n; i++) {
            a[i].clear();
        }
    }
    return 0;
}