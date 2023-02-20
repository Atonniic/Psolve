#include <iostream>
#include <queue>

char mat[30][30];
int visited[30][30], di[] = {-1,0,1,0}, dj[] = {0,1,0,-1};
struct A{
    int i, j, key;
};
std::queue<A> bfs;

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n, q, r, c, a, b, count = 0;

    std::cin >> n >> q;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            std::cin >> mat[i][j];
        }   
    }
    while(q--){
        std::cin >> r >> c >> a >> b;
        
        count++;
        bfs.push({r, c, 1});
        while(!bfs.empty()){
            auto tmp = bfs.front();
            bfs.pop();
            if (visited[tmp.i][tmp.j] == count) {
                continue;
            } 
            visited[tmp.i][tmp.j] = count;
            if (tmp.i == a && tmp.j == b) {
                std::cout << "yes\n";
                goto x;
            }
            for (int i = 0; i < 4; i++) {
                int tmp_i = tmp.i + di[i];
                int tmp_j = tmp.j + dj[i];

                if (tmp_i <= 0 || tmp_j <= 0) {
                    continue;
                }
                if (tmp_i > n || tmp_j > n) {
                    continue;
                }
                if (mat[tmp_i][tmp_j] == '#') {
                    continue;
                }
                if (mat[tmp_i][tmp_j] == '.') {
                    bfs.push({tmp_i, tmp_j, tmp.key});
                }
                if (mat[tmp_i][tmp_j] == 'O' && tmp.key == 1) {
                    bfs.push({tmp_i, tmp_j, 0});
                }
            }
        }
        std::cout << "no\n";
        x:;
        while(!bfs.empty()) {
            bfs.pop();
        }
    }
    return 0;
}