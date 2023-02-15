#include <iostream>
#include <vector>

std::vector<int> vec[100100];
int mark[100100];

void DFS(int i) {
    if(mark[i]) {
        return;
    }
    mark[i] = 1;
    for(auto x: vec[i]){
        DFS(x);
    }
}

int main() {
    int n, m, a, b, count = 0;

    std::cin >> n >> m;
    for(int i = 0; i < m; i++) {
        std::cin >> a >> b;
        vec[b].push_back(a);
        vec[a].push_back(b);
        
    }
    for(int j = 1; j <= n; j++) {
        if(!mark[j]) {
            count++;
            DFS(j); 
        }
    }
    std::cout << count << "\n";
    return 0;
}