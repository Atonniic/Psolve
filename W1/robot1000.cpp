#include <iostream>
#include <string.h>

int main() {
    char in_put[110];
    int x = 0, y = 0;

    std::cin >> in_put;
    for (int i = 0; i < strlen(in_put); i++) {
        if (in_put[i] == 'N') {
            x = x;
            y += 1;
        }
        else if (in_put[i] == 'S') {
            x = x;
            y -= 1;
        }
        else if (in_put[i] == 'E') {
            x += 1;
            y = y;
        }
        else if (in_put[i] == 'W') {
            x -= 1;
            y = y;
        }
        else if (in_put[i] == 'Z') {
            x = 0;
            y = 0;
        }
    }
    std::cout << x << " " << y << std::endl; 
}