#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
struct A{
    int v,w,s;
    bool operator<(const A&o)const{
        return w>o.w;
    }
};
std::priority_queue<A> q;
std::vector<A> v[1010];
int dis[1010][5];

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n,m,ai,bi,ci,si;

    std::cin >> n >> m;
    for (int i = 0; i < m; i++) {
        std::cin >> ai >> bi >> ci >> si;
        v[ai].push_back({bi,ci,si});
        v[bi].push_back({ai,ci,si});
    }
    memset(dis,-1,sizeof dis);
    q.push({1,0,0});
    while (!q.empty()) {
        bi = q.top().v;
        ci = q.top().w;
        si = q.top().s;
        q.pop();
        if (dis[bi][si] != - 1) {
            continue;
        }
        dis[bi][si] = ci;
        if (bi == n) {
            std::cout << ci << "\n";
            return 0;
        }
        for (auto x: v[bi]) {
            if (dis[x.v][x.s+si] != -1) {
                continue;
            }
            if (x.s == 1 && si == 1) {
                continue;
            }
            q.push({x.v,ci+x.w,x.s+si});
        }
    }
    std::cout << "-1\n";
    return 0;
}