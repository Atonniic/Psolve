#include<iostream>

char mat[35][35];
int x[35][35];
int n, m, xi[] = {0,0,1,-1}, yj[] = {1,-1,0,0};

void move(int i, int j) {
    int xi2, yj2;

    x[i][j] = 1;
    if(i == n-2) {
        std::cout << "yes" << "\n";
        exit(0);
    }
    for(int k = 0; k < 4; k++) {
        xi2 = i + xi[k]; 
        yj2 = j + yj[k];
        if(xi2 < 0 || xi2 >= n-1) {
            continue;
        }
        if(yj2 < 0 || yj2 >= m-1) {
            continue;
        }
        if(x[xi2][yj2]) {
            continue;
        }
        if(mat[xi2][yj2] == '.' && mat[xi2][yj2+1] == '.' && mat[xi2+1][yj2] == '.' && mat[xi2+1][yj2+1] == '.'){
            move(xi2, yj2);
        }
    }
    x[i][j] = 0;
}
int main() {
    std::cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0 ; j < m; j++) {
            std::cin >> mat[i][j];
        }
    }
    for(int k = 0; k < m; k++) {
        if(mat[0][k]=='.' && mat[0][k+1]=='.' && mat[1][k]=='.' && mat[1][k+1]=='.') {
            move(0, k);
        }
    }
    std::cout << "no" << "\n";
    return 0;
}