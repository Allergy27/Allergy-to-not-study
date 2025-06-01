#include<bits/stdc++.h>

using ll = int64_t;
using PII = std::pair<int, int>;

int main(){
    std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);
    int _ = 1;
    std::cin >> _;
    auto solve = [&]() -> void{
        int n, m;
        std::cin >> n;
        std::vector<int> v(n) , p(n);
        
        std::unordered_map<int, int> vm,pm;
        int vi = 0, pi = 0;
        for(int i=0 ;i<n; ++i){
            int x, y;
            std::cin >> x >> y;
            if(!vm.contains(x))vm[x] = vi++;
            if(!pm.contains(y))pm[y] = pi++;
            v[i] = vm[x], p[i] = pm[y] + n;
        }
        
        std::vector<int> deg(2 * n);
        std::vector<std::vector<PII>> qwq(2 * n);

        for(int i = 0; i < n ;++i){
            qwq[v[i]].push_back({p[i], i});
            qwq[p[i]].push_back({v[i], i});
            ++deg[v[i]];
            ++deg[p[i]];
        }
        
        std::vector<int> ans;

        int s = 0;
        while(s < 2 * n && deg[s] % 2 == 0)++s;
        if(s == 2 * n){
            s = 0;
            while(!deg[s]) ++s;
        }

        int cnt = 0;
        for(int i = 0; i < 2 * n; ++i)cnt += deg[i] % 2;
        if(cnt > 2){
            std::cout << "No\n";
            return;
        }
        
        std::vector<int> cur(2 * n);
        std::vector<int> vis(n);
        auto dfs = [&](auto &&dfs, int x) -> void{
            for(int &j = cur[x]; j < qwq[x].size() ; ++j){
                auto [y, i] = qwq[x][j];
                if(!vis[i]){
                    vis[i] = true;
                    dfs(dfs, y);
                    ans.emplace_back(i);
                }
            }
        };
        dfs(dfs, s);
        
        if(ans.size() != n){
            std::cout << "No\n";
            return;
        }
        std::cout << "Yes\n";
        for(auto x:ans) std::cout << x + 1 << ' '; std::cout << "\n";
    };
    while(_--)solve();
    return 0;
}


