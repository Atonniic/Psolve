#include<bits/stdc++.h>

struct A{
    int v,dis,c;
};
std::vector<A> g[100100];
int mark[100100][5],magic[100100];
std::queue<A> bfs;
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n,m,u,v,h,c,i,k,ans=0,dis;
    std::cin >> n >> m >> k >> h;
    for(i=0;i<k;i++){
        cin >> u;
        magic[u] = 1;
    }
    for(i=0;i<m;i++){
        cin >> u >> v >> c;
        g[u].push_back({v,0,c});
        g[v].push_back({u,0,c});
    }
    bfs.push({1,0,0});
    while(!bfs.empty()){
        u = bfs.front().v;
        dis = bfs.front().dis;
        c = bfs.front().c;
        bfs.pop();
        if(magic[u]) c = 1;
        if(mark[u][c]) continue;
        if(!mark[u][0] && !mark[u][1]) ans++;//cout << "\t" << u << " " << dis << " " << c << "\n";
        mark[u][c] = 1;
        if(dis == h) continue;
        for(auto x:g[u]){
            if(mark[x.v][c]) continue;
            if(c == 0 && x.c == 1) continue;
            //cout << "\t" << x.v << " " << dis+1 << " " << c << " " << x.c << "\n";
            bfs.push({x.v,dis+1,c});
        }
    }
    cout << ans << "\n";
    return 0;
}