#include <iostream>
#include <cstring>

char s[110],t[100100];

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int len_t, len_s, res = 0;

    std::cin >> s;
    std::cin >> t;
    len_t = strlen(t);
    len_s = strlen(s);
    int j = 0;
    for (int i = 0; i < len_t; i++) {
        if (s[j] == t[i]) {
            j++;
            if (len_s == j) {
                res++;
                j = 0;
            }
        }
    }
    std::cout << res << "\n";
    return 0;
}