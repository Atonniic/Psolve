#include <iostream>
#include <vector>
#include <queue>

std::vector<int> a[100100];
std::queue<int> q, res;
int deg[100100];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n, m;

    while (1) {
        std::cin >> n >> m;
        if (n == 0 && m == 0) {
            break;
        }
        for (int i = 0; i < m; i++) {
            int u, v;

            std::cin >> u >> v;
            a[u].push_back(v);
            deg[v]++;
        }
        for (int i = 1; i <= n; i++) {
            if (deg[i] == 0) {
            q.push(i);
            }
        }
        while(!q.empty()) {
            int x = q.front();
            q.pop();
            res.push(x);
        
            for (int i = 0; i < a[x].size(); i++) {
                deg[a[x][i]]--;
                if (deg[a[x][i]] == 0) {
                q.push(a[x][i]);
                }
            }
        }  
        while (!res.empty()) {
            std::cout << res.front() << " ";
            res.pop();
        }
        std::cout << "\n";
        for(int i = 1; i <= n; i++) {
            a[i].clear();
        }
    }
    return 0;
}