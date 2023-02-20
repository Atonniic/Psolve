#include <iostream>
#include <vector>
#include <queue>

std::vector<int> v[100100], fact;
std::queue<int> st, fc;
int visited[100100], storave[100100], factory[100100], ans[100100];
struct A{
    int v, d;
};
std::queue<A> bfs;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n, m, s, t, a, b, tmp, dis, k;

    std::cin >> n >> m >> s >> t;
    for (int i = 0; i < m; i++) {
        std::cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for (int i = 0; i < s; i++) {
        std::cin >> tmp;
        storave[tmp] = 1;
        st.push(tmp);
    }
    for (int i = 0; i < t; i++) {
        std::cin >> tmp;
        factory[tmp] = 1;
        fc.push(tmp);
        fact.push_back(tmp);
    }
    if (s <= t) {
        for(int i = 0; i < s; i++) {
            tmp = st.front();
            st.pop();
            bfs.push({tmp, 0});
        }
        while(!bfs.empty()) {
            tmp = bfs.front().v;
            dis = bfs.front().d;
            bfs.pop();
            if (visited[tmp]) {
                continue;
            }
            visited[tmp] = 1;
            if (factory[tmp]) {
                for (int i = 0; i < fact.size(); i++) {
                    if (fact[i]==tmp){
                        ans[i] = dis;
                        break;
                    } 
                }
            } 
            for (auto x: v[tmp]) {
                if (visited[x]) {
                    continue;
                }
                bfs.push({x, dis+1});
            }
        }
    }
    else {
        for (k = 0; k < t; k++) {
            tmp = fc.front();
            fc.pop();
            bfs.push({tmp, 0});
            while (!bfs.empty()) {
                tmp = bfs.front().v;
                dis = bfs.front().d;
                bfs.pop();
                if (visited[tmp]) {
                    continue;
                }
                visited[tmp] = 1;
                if (storave[tmp]) {
                    ans[k] = dis;
                    break;
                }
                for (auto x: v[tmp]) {
                    if (visited[x]) {
                        continue;
                    }
                    bfs.push({x,dis+1});
                }
            }
            while (!bfs.empty()) {
                bfs.pop();
            }
        }
    }
    for (int i = 0; i < t; i++) {
        std::cout << ans[i] << "\n";
    }
    return 0;
}