#include <iostream>
#include <list>

std::list<int> list_int[100100];

int main() {
    int n, x, i, j;
    char order;

    std::cin >> n;
    for (int k = 0; k < n; k++) {
        std::cin >> order; 
        if (order == 'N') {
            std::cin >> x >> i;
            list_int[i].push_back(x);
        }
        else if (order == 'M') {
            std::cin >> i >> j;
            list_int[j].splice(list_int[j].end(), list_int[i]);
            list_int[i].clear();
        }
    }
    for(int l = 1; l <= 100000; l++){
        if (list_int[l].size() == 0) {
            continue;
        }
        for (auto x:list_int[l]){
            std::cout << x << "\n";
        }
    }
    return 0;
}
/*
7
N 1 1
N 2 1
N 3 2
M 1 2
N 4 1
N 5 3
M 3 1
*/