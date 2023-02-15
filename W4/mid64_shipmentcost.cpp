#include <iostream>
#include <vector>
#include <queue>

std::vector<int> g[100100], fact;
std::queue<int> st, fc;
int mark[100100], storage[100100], factory[100100], ans[100100];
struct A{
    int v,d;
};
std::queue<A> bfs;

int main() {
    int n, m, s, t, u,tmp, v, i, dis, k;
    std::cin >> n >> m >> s >> t;
    for (i = 0; i < m; i++) {
        std::cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (i = 0; i < s; i++) {
        std::cin >> tmp;
        storage[tmp] = 1;
        st.push(tmp);
    }
    for (i = 0; i < t; i++) {
        std::cin >> tmp;
        factory[tmp] = 1;
        fc.push(tmp);
        fact.push_back(tmp);
    }
    if (s <= t) {
        for(i = 0; i < s; i++) {
            tmp = st.front();
            st.pop();
            bfs.push({tmp, 0});
        }
        while(!bfs.empty()) {
            tmp = bfs.front().v;
            dis = bfs.front().d;
            bfs.pop();
            if(mark[tmp]) {
                continue;
            }
            mark[tmp] = 1;
            if(factory[tmp]) {
                for(i=0;i<fact.size();i++) {
                    if(fact[i]==tmp){
                        ans[i] = dis;
                        break;
                    } 
                }
            } 
            for(auto x:g[tmp]) {
                if(mark[x]) {
                    continue;
                }
                bfs.push({x,dis+1});
            }
        }
    }
    else {
        for(k = 0; k < t; k++) {
            tmp = fc.front();
            fc.pop();
            bfs.push({tmp, 0});
            while(!bfs.empty()) {
                tmp = bfs.front().v;
                dis = bfs.front().d;
                bfs.pop();
                if(mark[tmp]) {
                    continue;
                }
                mark[tmp] = 1;
                if(storage[tmp]) {
                    ans[k] = dis;
                    break;
                }
                for(auto x:g[tmp]) {
                    if(mark[x]) continue;
                    bfs.push({x,dis+1});
                }
            }
            while(!bfs.empty()) {
                bfs.pop();
            }
        }
    }
    for(i = 0; i < t; i++) {
        std::cout << ans[i] << "\n";
    }
    return 0;
}