#include<bits/stdc++.h>

#define ln '\n'
#define judge(x) std::cout << ((x) ? "Yes\n":"No\n");

using ll = int64_t;
using PII = std::pair<int,int>;

#define int int64_t
int32_t main(){
    std::ios::sync_with_stdio(false),std::cin.tie(nullptr);
    int _ = 1;
    std::cin >> _;
    auto solve = [&](){
        int n, m;
        std::cin >> n;
        std::vector<int>deg(n),f(n);
        for(auto &x:deg)std::cin >> x;
        for(int i =0;i<n;++i) f[i] = deg[i];
        std::vector<std::vector<int>> qwq(n);
        for(int i=1;i < n;++i){
            int u, v;
            std::cin >> u >> v;
            --u,--v;
            qwq[u].emplace_back(v);
            qwq[v].emplace_back(u);
        }
        
        std::queue<int>que{{0}};
        std::vector<int> fa(n), ans(n);
        while(!que.empty()){
            int u = que.front();
            que.pop();
            for(auto v:qwq[u]){
                if(v!=fa[u]){
                    fa[v] = u;
                    f[v] = std::max(f[v], deg[v] - deg[u] + f[fa[u]]);
                    que.push(v);
                }
            }
        }
        for(int i=0 ;i<n;++i)std::cout << std::max(f[i] , deg[i]) << ' ';
        std::cout << ln;
    };
    while(_--)solve();
    return 0;
}
