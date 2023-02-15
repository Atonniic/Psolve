#include <iostream>
#include <math.h>

int main() {
    int n, pos_x, pos_y, point = 0;
    double R;

    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> pos_x >> pos_y;
        R = sqrt(pow(pos_x, 2) + pow(pos_y, 2));
        if (R <= 2) {
            point = point + 5;
        } 
        else if (R > 2 && R <= 4) {
            point = point + 4;
        } 
        else if (R > 4 && R <= 6) {
            point = point + 3;
        } 
        else if (R > 6 && R <= 8) {
            point = point + 2;
        } 
        else if (R > 8 && R <= 10) {
            point = point + 1;
        }
        else {
            point = point;
        }
    }
    std::cout << point << std::endl;
}