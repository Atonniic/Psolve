#include <iostream>

int arrey_V[200100];

int main()
{
    int n, count = 0, P, V, tmp = -1;

    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> P >> V;
        arrey_V[i] = V;
    }
    for (int j = 1; j <= n; j++) {
        if (arrey_V[n-j] < tmp) {
            count++;
        }
        tmp = std::max(tmp, arrey_V[n-j]);
    }
    std::cout << count << std::endl;
    return 0;
}
/*
2
100 30
50 40

2
100 45
50 40

4
100 200
90 40
50 41
10 30
*/