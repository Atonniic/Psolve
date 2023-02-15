#include <list>
#include <iostream>

std::list<int> list_int;

int main() {
    int n, in_put;
    char ID;
    
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> ID >> in_put;
        if (ID == 'I') {
            list_int.push_front(in_put);
        }
        else if (ID == 'A') {
            list_int.push_back(in_put);
        }
        else if (ID == 'D') {
            std::list<int>::iterator ite = list_int.begin();
            advance(ite,in_put-1);
            if (in_put <= list_int.size()) {
                list_int.erase(ite);
            }
        }
    }
    for(auto x:list_int){
        std::cout << x << "\n";
    }
    return 0;
}
/*
6
A 10
I 20
D 2
A 15
I 30
D 2
*/