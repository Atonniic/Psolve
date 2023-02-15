#include <iostream>
#include <vector>
#include <queue>

std::vector<int> vec_int[1010];
std::queue<int> queue_int;
std::pair<int, int> pos[1010];
int distance[1010];

int main() {
    int n, r, first, second, top;

    std::cin >> n >> r;
    pos[n].first = 0; 
    pos[n].second = 0;
    distance[n] = 0;
    pos[n+1].first = 100; pos[n+1].second = 100;
    distance[n+1] = -1;
    for(int i = 0; i < n; i++) {
        std::cin >> pos[i].first >> pos[i].second;
    }
    for(int j = 0; j < n+2; j++) {
        for(int k = j + 1; k < n+2; k++) {
            first = (pos[j].first-pos[k].first)*(pos[j].first-pos[k].first);
            second = (pos[j].second-pos[k].second)*(pos[j].second-pos[k].second);
            if(r*r >= first + second) {
                vec_int[j].push_back(k);
                vec_int[k].push_back(j);
            }
        }
    }
    queue_int.push(n);
    while(!queue_int.empty()) {
        top = queue_int.front();
        queue_int.pop();
        for(auto x:vec_int[top]) {
            if(distance[x] && distance[x] != -1) {
                continue;
            }
            distance[x] = distance[top] + 1;
            queue_int.push(x);
        }
    }
    std::cout << distance[n+1] << "\n";
    return 0;
}