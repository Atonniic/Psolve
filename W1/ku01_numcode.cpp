#include <iostream>

int in_put[55], ans[55], y[55];

int main()
{
    int N, T, tmp;
    
    std::cin >> N >> T;
    for (int i = 0; i < N; i++) {
        std::cin >> in_put[i];
    }
    tmp = N;
    if (T == 1) {
        for (int j = 0; j < N; j++) {
            if (in_put[j] < tmp) {
                ans[j] = 0;
                tmp = in_put[j];
            }
            else if (in_put[j] > tmp) {
                ans[j] = 1;
                tmp = in_put[j];
            }
        }
    }
    else if (T == 2) {
        if (in_put[0] < tmp) {
                ans[0] = 0;
                tmp = in_put[0];
        }
        else if (in_put[0] > tmp) {
                ans[0] = 1;
                tmp = in_put[0];
        }
        for (int j = 1; j < N; j++) {
            if (tmp - (in_put[j] - tmp) == 1 || tmp - (in_put[j] - tmp) == -1) {
                if (tmp - (in_put[j] - tmp) == 1) {
                    ans[j] = 0;
                    tmp = in_put[j] - tmp;
                }
                else if (tmp - (in_put[j] - tmp) == -1) {
                    ans[j] = 1;
                    tmp = in_put[j] - tmp;
                }
            }
            else if (tmp - (in_put[j] - (2 * tmp)) == 1 || tmp - (in_put[j] - (2 * tmp)) == -1) {
                if (tmp - (in_put[j] - (2 * tmp)) == 1) {
                    ans[j] = 0;
                    tmp = in_put[j] - (2 * tmp);
                }
                else if (tmp - (in_put[j] - (2 * tmp)) == -1) {
                    ans[j] = 1;
                    tmp = in_put[j] - (2 * tmp);
                }
            }
        }
    }
    for (int k = 0; k < N; k++) {
        std::cout << ans[k] << std::endl;
    }
}