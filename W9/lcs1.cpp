#include <iostream>
#include <cstring>

char S[210], T[210];
int res[210][210];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> S >> T;
    int ls = strlen(S), lt = strlen(T);
    for (int i = 0; i < ls; i++) {
        for (int j = 0; j < lt; j++) {
            if (S[i] == T[j]) {
                res[i+1][j+1] = res[i][j] + 1;
                res[i+1][j+1] = std::max(res[i+1][j+1], res[i][j+1], res[i+1][j]);
            } 
            else {
                res[i+1][j+1] = std::max(res[i][j+1], res[i+1][j]);
            }
        }
    }
    std::cout << res[ls][lt] << "\n";
}