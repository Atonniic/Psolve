#include <iostream>
#include <vector>

struct mask {
    int perf;
    int num;
};

std::vector<int> all_player;
std::vector<mask> player1_4;

int main() {
    int n, count = 0;
    mask max, new_player, tmp;

    std::cin >> n;
    max.perf = -1;
    for (int i = 1; i <= 4*n; i++) {
        std::cin >> new_player.perf;
        new_player.num = i;
        if (new_player.perf > max.perf){
            max = new_player;
        }
        count++;
        if (count==n) {
            count = 0;
            player1_4.push_back(max);
            max = *(new mask);
            max.perf = -1;
        }
    }
    if (player1_4[0].perf < player1_4[1].perf) {
        tmp = player1_4[0];
        player1_4[0] = player1_4[1];
        player1_4[1] = tmp;

    }
    if (player1_4[2].perf < player1_4[3].perf) {
        tmp = player1_4[2];
        player1_4[2] = player1_4[3];
        player1_4[3] = tmp;
    }
    if (player1_4[0].perf < player1_4[2].perf) {
        tmp = player1_4[0];
        player1_4[0] = player1_4[2];
        player1_4[2] = tmp;
    }
    tmp = player1_4[1];
    player1_4[1] = player1_4[2];
    player1_4[2] = tmp;
    for (auto x: player1_4) {
        std::cout << x.num << " ";
    }
    return 0;
}