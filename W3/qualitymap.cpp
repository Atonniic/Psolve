#include<iostream>

int n, m, best = 0, normal = 0, tmp = 0, tmp2 = 0, count = 0;
int xi[] = {0, 0, 1, -1}, yj[] = {1, -1, 0, 0};
int x[50][50];
char mat[50][50];

void move(int i,int j) {
    int xi2,yj2;
    
    count++;
    x[i][j] = 1;
    if(mat[i][j] == '*') {
        tmp = 1;
    }
    if(mat[i][j] == '$') {
        tmp2 = 1;
    }
    for(int k = 0; k < 4; k++) {
        xi2 = i + xi[k]; 
        yj2 = j + yj[k];
        if(xi2 < 0 || xi2 >= n) {
            continue;
        }
        if (yj2 < 0 || yj2 >= m) {
            continue;
        }
        if(x[xi2][yj2]) {   
            continue;
        }
        if(mat[xi2][yj2] == '#') {
            continue;
        }
        move(xi2, yj2);
    }
}
int main(){
    std::cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            std::cin >> mat[i][j];
        }
    }
    for(int k = 0; k < n; k++) {
        for(int l = 0; l < m; l++) {
            if(mat[k][l] != '#' && !x[k][l]) {
                tmp = 0;
                tmp2 = 0;
                count = 0;
                move(k,l);
                if(tmp && tmp2) {
                    best += count;
                }
                else if(tmp || tmp2) {
                    normal += count;
                }
            }
        }
    }
    std::cout << best << " " << normal << "\n";
    return 0;
}