/* Copyright 2025 Allery
 * @author    Allergy
 * @email     allergy527@gmail.com
 * @workspace abc 409/e.cpp
 * @date      2025-06-08 15:37:55
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

    auto solve = [&]() -> void{
        int n, m;
        std::cin >> n;
        std::vector<int> qvq(n);
        for(auto &x : qvq)std::cin >> x;

        std::vector<std::vector<PII>> qwq(n);
        for(int i = 1; i < n; ++i){
            int u, v, w;
            std::cin >> u >> v >> w;
            --u, --v;
            qwq[u].push_back({v, w});
            qwq[v].push_back({u, w});
        }
        
        i64 ans = 0;
        auto dfs = [&](auto &&self, int u, int fa) -> void{
            for(auto [v, w] : qwq[u]){
                if(v == fa)continue;
                self(self, v, u);
                ans += w * std::abs(qvq[v]);
                qvq[u] += qvq[v];
            }
        };

        dfs(dfs, 0, -1);
        std::cout << ans << '\n';
    };
    while(_--)solve();
    return 0;
}

