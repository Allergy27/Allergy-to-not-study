#include<bits/stdc++.h>

using ll = int64_t;
using PII = std::pair<ll, ll>;

int main(){
    std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);
    int _ = 1;
    std::cin >> _;
    auto solve = [&]() -> void{
        const ll inf = 0x3f3f3f3f3f3f3f3f;
        int n, m, l;
        std::cin >> n >> m >> l;
        ll sum = 0, mi_odd = inf;
        for(int i =0;i < l ;++i){
            ll x;
            std::cin >> x;
            sum += x;
            if(x & 1)mi_odd = std::min(mi_odd, x);
        }
        std::vector<std::vector<int>> qwq(n);
        for(int i = 0;i < m; ++i){
            int u, v;
            std::cin >> u >> v;
            --u, --v;
            qwq[u].emplace_back(v);
            qwq[v].emplace_back(u);
        }
        std::vector<std::array<ll, 2>> dis(n, {inf, inf});
        std::queue<PII> que{{std::make_pair(0,0)}};
        dis[0][0] = 0;
        while(!que.empty()){
            auto [u, w] = que.front();
            que.pop();
            for(auto v : qwq[u]){
                if(dis[v][w ^ 1] > dis[u][w] + 1){
                    dis[v][w ^ 1] = dis[u][w] + 1; 
                    que.push({v, w ^ 1});
                }
            }
        }
        for(int i = 0 ;i < n ;++i){
            ll flag = 0, w = 2;
            while(~--w){
                ll s = sum - (w == sum % 2 ? 0 : mi_odd);
                if(dis[i][w] <= s)flag = 1;
            }
            std::cout << flag;
        }
        std::cout << '\n';
    };
    while(_--)solve();
    return 0;
}

