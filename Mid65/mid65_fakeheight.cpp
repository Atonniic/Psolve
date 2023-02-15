#include <iostream>

long long height[100100], res = 0 , ans[100100], max = -1;
std::pair<long long, long long> a; 

int main() {
    int n;
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        std::cin >> height[i];
        ans[i] = abs(height[i] - height[i-1]);
        if (i > 1) {
            if (ans[i]  > max) {
                max = ans[i]; 
                a.first = i;
                a.second = i-1;
            }
        }
    }
    for (int i = 2; i <= n; i++) {  
        if (ans[i] == max) {
            long long min = 1000000000000000000;
            for (int j = 1; j <= n; j++) {
                if (min == 1) {
                    break;
                }
                if (abs(j - a.second) == 1 || a.second == j) {
                    continue;
                }
                if (abs(height[j] - height[a.first]) < min) {
                    min = abs(height[j] - height[a.first]);
                    height[a.second] = height[j];
                }
            }
            break;
        }
    }
    /*
    for (int i = 1; i <= n; i++) {
        std::cout << height[i] << " ";
    }
    std::cout << "\n";
    */
    for (int i = 2; i <= n; i++) {
        res += abs(height[i] - height[i-1]);
    }
    std::cout << res << "\n";
    return 0;
}
/*
5
10 15 20 12 19

6
2 5 6 3 1 4

5
4 3 1 5 2
*/  