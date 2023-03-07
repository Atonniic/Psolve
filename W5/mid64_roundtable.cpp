#include <iostream>

int a[200100], dp[200100];
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n,dis,Mx = -1;

    std::cin >> n;
    for(int i = 1; i <= n; i++) {
        std::cin >> a[i];
        dis = ((i + n) - a[i]) % n;
        dp[dis]++;
        //Mx = std::max(Mx,dp[dis]);
        if (Mx < dp[dis]) {
            Mx = dp[dis];
        }
    }
    std::cout << Mx;
    return 0;
}