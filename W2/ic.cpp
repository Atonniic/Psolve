#include <list>
#include <iostream>
#include <string.h>

std::list<int> list_int;
char order[3];

int main() {
    int n, in_put;
    
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> order;
        if (!strcmp(order,"li")) {
            std::cin >> in_put;
            list_int.push_front(in_put);
        }
        else if (!strcmp(order,"ri")) {
            std::cin >> in_put;
            list_int.push_back(in_put);
        }
        else if (!strcmp(order,"lr")) {
            list_int.push_back(list_int.front());
            list_int.pop_front();
        }
        else if (!strcmp(order,"rr")) {
            list_int.push_front(list_int.back());
            list_int.pop_back();
        }
    }
    for(auto x:list_int) {
        std::cout << x << "\n";
    }
    return 0;
}
/*
8
ri 1
ri 2
ri 3
li 20
ri 100
lr
ri 1000
rr
*/