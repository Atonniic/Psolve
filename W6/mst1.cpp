#include <iostream>
#include <algorithm>

int p[100100];
struct A {
    int u,v,w;
    bool operator<(const A&o) const {
        return w < o.w;
    }
};
A input[200100];

int find_root(int i) {  
    if (p[i] == i) {
        return i;
    }
    else {
        return p[i] = find_root(p[i]);
    }       
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m, a, b, w, res = 0;

    std::cin >> n >> m;
    for (int i = 0; i < n; i++) {
        p[i] = i;
    }
    for (int i = 0; i < m; i++){
        std::cin >> a >> b >> w;
        input[i].u = a;
        input[i].v = b;
        input[i].w = w;
    }
    std::sort(input, input + m);
    for (int i = 0; i < m; i++) {
        if (find_root(input[i].u) != find_root(input[i].v)){
            p[find_root(input[i].u)] = find_root(input[i].v);
            res += input[i].w;
        }
    }
    std::cout << res << "\n";
    return 0;
}