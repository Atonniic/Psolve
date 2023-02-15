#include <iostream>
#include <vector>
#include <stack>

std::stack<int> stack_rail;
std::vector<int> vector_1,vector_2;

int check (int *input, int n) {
    int i = 1, j = 0;
    stack_rail.push(0);

    while(1) {
        if (i <= n && stack_rail.top() != input[j]) {
            stack_rail.push(i); 
            i++;
            continue;
        }
        if (stack_rail.top() == input[j]) {
            stack_rail.pop();
            j++;
        }
        if (j >= n) return 1;
        if (i > n && stack_rail.top() != input[j]) return 0;
    }
    return 1;
}

int main() {
    int n, j = 0, l = 0;

    while (std::cin >> n) {
        int value, k = 0;
        if (n == 0) break;
        while(1) {
            int array[n];
            for (int i = 0; i < n; i++) {
                std::cin >> array[i];
                if (array[0] == 0) break;
            }
            if (array[0] == 0) {
                vector_2.push_back(k);
                break;
            }
            if (array[0] != 0) {
                value = check(array, n) ;
                vector_1.push_back(value);
                k++;
            }
        }        
    }
    std::vector<int>::iterator ite1,ite2;
    ite2 = vector_2.begin();

    for (ite1 = vector_1.begin(); ite1 != vector_1.end(); ite1++) {
        if (*ite1) {
            std::cout << "Yes" << "\n";
        }
        else {
            std::cout << "No" << "\n";
        }
        l++;
        if (*(ite2+j) == l) {
            l = 0;
            std::cout << "\n";
            j++;  
        }
    }
    return 0;
}