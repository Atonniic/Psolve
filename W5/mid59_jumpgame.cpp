#include <iostream>
#include <queue>

std::queue<std::pair<int,int>> bfs;
int a[30][30], visit[30][30], di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, k, i, j, l, u, v;
    std::cin >> n >> k;
    for (i = 0; i < n; i++) {
        for (j = 0;j < n; j++) {
            std::cin >> a[i][j];
        }
    }

    bfs.push({0, 0});

    while(!bfs.empty()) {
        i = bfs.front().first;
        j = bfs.front().second;
        bfs.pop();
        visit[i][j] = 1;
        if (j == n-1 && i == n-1) {
            std::cout << "yes\n";
            return 0;
        }
        for (l = 1; l <= 4; l++) {
            u = i + di[l-1]; 
            v = j + dj[l-1];
            if (u < 0 || u >= n || v < 0 || v >= n) {
                continue;
            }
            if(visit[u][v]) {
                continue;
            }
            if(a[u][v] - a[i][j] > k) {
                continue;
            }
            bfs.push({u,v});
        }
    }
    std::cout << "no\n";
    return 0;
}