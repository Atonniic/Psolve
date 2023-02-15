#include <iostream>

int main() {
    int N, K, T, count = 0, current = 0;

    std::cin >> N >> K >> T;
    current += K;
    count++;
    while (true) {
        if (current == 0) {
            break;  
        }
        if (current == T-1) {
            count++;
            break;
        }
        if (current += K > N) {
            current = (current += K) % N;
            count++;
        }
        else {
            current += K;
            count++;
        }
    }
    std::cout << count << std::endl;
}