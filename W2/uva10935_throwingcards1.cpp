#include <list>
#include <iostream>

std::list<int> list_input, list_cards, list_dis;

int main() {
    int in_put, tmp;

    while (std::cin >> in_put) {
        if (in_put == 0) {
            break;
        }
        list_input.push_back(in_put);
    }
    for (auto x:list_input) {
        for(int i = 1; i <= x; i++) {
            list_cards.push_back(i);
        }
        tmp = list_cards.size();
        for (int j = 0; j < tmp; j++) {
            if (list_cards.size() >= 2) {
                list_dis.push_back(list_cards.front());
                list_cards.pop_front();
                list_cards.push_back(list_cards.front());
                list_cards.pop_front();
            }
            else {
                std::cout << "Discarded cards:";
                for (auto z1:list_dis) {
                    if (z1 != list_dis.back()) {
                        std::cout <<" "<< z1 << ",";
                    }
                    else {
                        std::cout <<" "<< z1;
                    }
                }
                std::cout << std::endl;
                std::cout << "Remaining card:";
                for (auto z2:list_cards) {
                    if (z2 != list_cards.back()) {
                        std::cout <<" "<< z2 << ",";
                    }
                    else {
                        std::cout <<" "<< z2;
                    }
                }
                std::cout << std::endl;
                list_dis.clear();
                list_cards.clear();
            }
        }
    }
    return 0;
}