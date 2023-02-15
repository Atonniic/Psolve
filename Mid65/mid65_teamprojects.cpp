#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

std::vector<int> v[100100];
int visited[100100], blacklist[100100];
std::queue<int> q;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n, m, k, a, b;
    memset(visited, -1, sizeof(visited));
    bool bipartite = true;

    std::cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        std::cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
        if (v[a].size() >= k) {
            v[a].erase(v[a].begin(), v[a].end());
            blacklist[a] = 2;
        }
        if (v[b].size() >= k) {
            v[b].erase(v[b].begin(), v[b].end());
            blacklist[a] = 2;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (v[i].size() != 0 && visited[i] == -1) {
            q.push(i);
            visited[i] = 0;
            while (!q.empty() && bipartite) {
                int x = q.front();
                q.pop();

                for (int j = 0; j < v[x].size(); j++) {
                    if (visited[v[x][j]] == -1 && blacklist[v[x][j]] != 2) {
                        visited[v[x][j]] = 1 - visited[x];
                        q.push(v[x][j]);
                    } 
                    else if (visited[v[x][j]] == visited[x] && blacklist[v[x][j]] != 2) {
                        bipartite = false;
                        goto mew;
                    }
                }
            }
            while (!q.empty()) {
            q.pop();
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
    return 0;
}
/*
5 6 4
1 2
1 3
1 4
1 5
2 3
4 5

5 8 3
1 2
1 3
1 4
1 5
2 3
4 5
2 5
4 3

6 10 4
1 2
1 3
1 4
1 5
1 6
2 3
3 4
4 5
5 6
6 2
*/