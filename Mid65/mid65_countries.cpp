#include <iostream>

int mat[35][35] ,now[35][35];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int r, c, a, b, x, y, now = 0;

    std::cin >> r >> c >> a >> b >> x >> y;
    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            std::cin >> mat[i][j];
        }
    }   
    
    return 0;
}