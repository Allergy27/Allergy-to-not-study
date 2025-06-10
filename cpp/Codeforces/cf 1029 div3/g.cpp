/* Copyright 2025 Allery
 * @author    Allergy
 * @email     allergy527@gmail.com
 * @workspace cf 1029 div3/g.cpp
 * @date      2025-06-09 14:04:11
 *
 *   ▄████████  ▄█        ▄█          ▄████████    ▄████████    ▄██████▄  ▄██   ▄   
 *  ███    ███ ███       ███         ███    ███   ███    ███   ███    ███ ███   ██▄ 
 *  ███    ███ ███       ███         ███    █▀    ███    ███   ███    █▀  ███▄▄▄███ 
 *  ███    ███ ███       ███        ▄███▄▄▄      ▄███▄▄▄▄██▀  ▄███        ▀▀▀▀▀▀███ 
 *▀███████████ ███       ███       ▀▀███▀▀▀     ▀▀███▀▀▀▀▀   ▀▀███ ████▄  ▄██   ███ 
 *  ███    ███ ███       ███         ███    █▄  ▀███████████   ███    ███ ███   ███ 
 *  ███    ███ ███▌    ▄ ███▌    ▄   ███    ███   ███    ███   ███    ███ ███   ███ 
 *  ███    █▀  █████▄▄██ █████▄▄██   ██████████   ███    ███   ████████▀   ▀█████▀  
 *             ▀         ▀                        ███    ███                        
 */
#include<bits/stdc++.h>

#define int int64_t /* R.I.P */
#define ln '\n'
#define judge(x) std::cout << ((x) ? "Yes\n" : "No\n");
#define lowbit(x) ((x)&-(x))
using u32 = uint32_t;
using i64 = int64_t;
using u64 = uint64_t;
using i128 = __int128;
using PII = std::pair<int, int>;
const int inf = 0x3f3f3f3f;
const i64 ll_inf = 0x3f3f3f3f3f3f3f3f;

signed main(){
    std::cin.tie(nullptr) -> std::ios::sync_with_stdio(0);
    int _ = 1;
    std::cin >> _;
    auto solve = [&]() -> void{
        int n, m;
        std::cin >> n >> m;
        std::vector<std::vector<PII>> qwq(n);
        for(int i = 0; i < m; ++i){
            int u, v, w;
            std::cin >> u >> v >> w;
            --u, --v;
            qwq[u].push_back({v, w});
            qwq[v].push_back({u, w});
        }
        /* dijkstra-like */
        auto f = [&](int u){
            std::vector<int> dis(n, ll_inf);
            std::vector<bool> vis(n);
            std::priority_queue<PII> que;
            que.push({0, u});
            while(que.size()){
                auto [w, v] = que.top();
                que.pop();
                w = -w;
                if(vis[v])continue;
                vis[v] = true;
                dis[v] = w;
                for(auto [x, d] : qwq[v]){
                    if(vis[x])continue;
                    que.push({-std::max(w, d), x});
                }
            }
            return dis;
        };
        
        int ans = ll_inf;
        std::vector<int> s = f(0), t = f(n - 1);
        for(int i = 0; i < n; ++i){
            for(auto [v, w] : qwq[i]) ans = std::min(ans, std::max({s[i],t[v],w}) + w);
        }

        std::cout << ans << ln;
    };
    while(_--)solve();
    return 0;
}

