#include<iostream>
#include<cstring>

char move[110];

int main() {
    int res, len, n, s, w, e;

    std::cin >> move;
    std::cin >> res;
    len = strlen(move);
    n = s = w = e = 0;
    for (int i = 0; i < len; i++) {
        if (move[i] == 'N') {
            n++;
        }
        else if (move[i] == 'S') {
            s++;
        }
        else if (move[i] == 'W') {
            w++;
        }
        else if (move[i] == 'E') {
            e++;
        }
    }
    if (n > s) {
        while (1) {
            if (s <= 0 || res <= 0) {
                break;
            }
            s--; 
            res--;
        }
    }
    else if (s > n) {
        while(1){
            if (n <= 0 || res <= 0) {
                break;
            }
            n--; 
            res--;
        }
    }
    if (e > w) {
        while(1){
            if (w <= 0 || res <= 0) {
                break;
            }
            w--; 
            res--;
        } 
    }
    else if (w > e) {
        while(1){
            if (e <= 0 || res <= 0) {
                break;
            }
            e--; 
            res--;
        }
    }
    while (res > 0) {
        if (n > 0 && res > 0) {
            n--; 
            res--;
        }
        if (s > 0 && res > 0) {
            s--; 
            res--;
        }
        if (e > 0 && res > 0) {
            e--; 
            res--;
        }
        if (w > 0 && res > 0) {  
            w--; 
            res--;
        }
    }
    res = abs(n-s) + abs(e-w);
    std::cout << res * 2;
    return 0;
}