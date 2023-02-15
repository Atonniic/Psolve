#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

std::vector<int> a[100100];
std::queue<int> q;
int visited[100100], c[100100], cou = 0;

void dfs(int i) {
    c[i] = cou;
    visited[i] = 1 - visited[i];
    for (auto x : a[i]) {
        if (c[x] != cou) {
            dfs(x);
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n, m, u, v, i;
    memset(visited, -1, sizeof(visited));

    std::cin >> n >> m;
    for (i = 0; i < m; i++) {
        std::cin >> u >> v;
        
        if (visited[u] == -1 && visited[v] == -1) {
            visited[u] = 0;
            visited[v] = 1;
        }
        else if (visited[u] == -1) {
            visited[u] = 1 - visited[v];
        }
        else if (visited[v] == -1) {
            visited[v] = 1 - visited[u];
        }
        else {
            if (visited[u] == visited[v]) {
                cou++;
                dfs(v);
                if (visited[u] == visited[v]) {
                    std::cout << i << "\n";
                    return 0;
                }
            }
        }
        a[u].push_back(v);
        a[v].push_back(u);
    }
    std::cout << i << "\n";
    return 0;
}