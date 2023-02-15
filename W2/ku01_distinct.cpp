#include <set>
#include <vector>
#include <iostream>

std::set<int> set_int;
std::vector<int> vector_int;

int main() {
    int n, in_put;

    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> in_put;
        vector_int.push_back(in_put);
    }
    for (int j = 0; j < n; j++) {
        int sum = 0;
        for (auto x = vector_int.begin() + j; x != vector_int.end(); x++) {
            sum += *x;
            set_int.insert(sum);
        }
    }
    std::cout << set_int.size();
    return 0;
}
/*
4
10 10 5 15

5
1 1 1 1 1
*/