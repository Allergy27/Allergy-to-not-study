/* Copyright 2025 Allery
 * @author    Allergy
 * @email     allergy527@gmail.com
 * @workspace cf 1029 div3/f.cpp
 * @date      2025-06-09 13:48:02
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

    const int N = 2e5 + 27;
    const int MOD = 1e9 + 7;
    std::vector<int> qpow(N, 1);
    for(int i = 1; i < N; ++i)qpow[i] = qpow[i - 1] * 2 % MOD;

    auto solve = [&]() -> void{
        int n, m;
        std::cin >> n;
        std::vector<std::vector<int>> qwq(n);
        for(int i = 1; i < n; ++i){
            int u, v;
            std::cin >> u >> v;
            --u, --v;
            qwq[u].emplace_back(v);
            qwq[v].emplace_back(u);
        }

        qwq[0].emplace_back(-1);
        int lca = -1;
        std::vector<int> cnt;
        auto dfs = [&](auto &&self, int u, int fa, int dep) -> void{
            if(qwq[u].size() > 2)  lca = dep;
            bool flag = true;
            for(auto v : qwq[u]){
                if(v == fa)continue;
                self(self, v, u, dep + 1);
                flag = false;
            }
            if(flag) cnt.emplace_back(dep);
        };
        dfs(dfs, 0, -1, 1);
        if(cnt.size() > 2){
            std::cout << 0 << '\n';
        }
        else if(cnt.size() == 1){
            std::cout << qpow[n] << '\n';
        }
        else{
            int tmp = std::abs(cnt[0] - cnt[1]) + lca;
            if(tmp - lca > 0) std::cout << (qpow[tmp] + qpow[tmp - 1]) % MOD << '\n';
            else std::cout << (qpow[tmp] << 1) % MOD << '\n';
        }

    };
    while(_--)solve();
    return 0;
}

