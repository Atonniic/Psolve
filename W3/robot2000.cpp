#include <iostream>
#include <cstring>

char move[110];

int main() {
    int len, pos = 0, newpos;

    std::cin >> move;
    len = strlen(move);
    for (int i = 0; i < len; i++) {
        if (move[i] == 'N' || move[i] == 'Z') {
            newpos = 0;
        }
        else if (move[i] == 'E') {
            newpos = 1;
        }
        else if (move[i] == 'S') {
            newpos = 2;
        }
        else if (move[i] == 'W') {
            newpos = 3;
        }
        if (move[i] == 'Z'){
            std::cout << "Z"; 
            pos = newpos; 
            continue;
        }
        for (int j = 0; j < ((newpos+4)-pos)%4; j++){
            std::cout << "R";
        }
        std::cout << "F";
        pos = newpos;
    }
    return 0;
}