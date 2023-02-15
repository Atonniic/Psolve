#include <iostream>
#include <list>
#include <string>

std::string in_put;
std::list<char> s;
std::list<char>::iterator cursor;

int main() {
    while (getline(std::cin, in_put)) {
        cursor = s.begin();
        for (int i = 0; i < in_put.size(); ++i) {
            if (in_put[i] == '[') {
                cursor = s.begin();
            }
            else if (in_put[i] == ']') {
                cursor = s.end();
            }
            else {
                s.insert(cursor, in_put[i]);
            }
        }
        for (auto x : s) {
            std::cout << x;
        }
        printf("\n");
        s.clear();
    }
    return 0;
}