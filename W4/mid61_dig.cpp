#include <iostream>
#include <queue>

char mat[60][60];
int di[] = {-1, 0, 1, 0}, dj[] = {0, 1, 0, -1}, visited[60][60][5][5];
struct A {
    int i, j, dig, dis, dir; 
};
std::queue<A> bfs;

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int r, c, a, b, x, y, newdir;

    std::cin >> r >> c;
    std::cin >> a >> b >> x >> y;
    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            std::cin >> mat[i][j];
        }
    }
    bfs.push({a, b, 1, 0, 0});
    while (!bfs.empty()) {
        auto now = bfs.front();
        bfs.pop();
        if (visited[now.i][now.j][now.dir][now.dig] == 1) {
            continue;
        }
        else {
            visited[now.i][now.j][now.dir][now.dig] = 1;
        }
        if (now.i == x && now.j == y) {
            std::cout << now.dis << "\n";
            return 0;
        }
        for (int i = 0; i < 4; i++) {
            int ni = now.i+di[i], nj = now.j+dj[i];

            if (ni == now.i) {
                newdir = 2;
            }
            if (ni != now.i) {
                newdir = 1;
            }
            if (mat[ni][nj] == '#') {
                continue;
            }
            if (mat[ni][nj] == '.') {
                bfs.push({ni, nj, now.dig, now.dis+1, newdir});
            }
            if (mat[now.i][now.j] == '*' && now.dir != newdir) {
                continue;
            }
            if (mat[ni][nj]== '*' && now.dig == 1) {
                bfs.push({ni, nj, 0, now.dis+1, newdir});
            }
        }
    }
    std::cout << "-1\n";
    return 0;
}