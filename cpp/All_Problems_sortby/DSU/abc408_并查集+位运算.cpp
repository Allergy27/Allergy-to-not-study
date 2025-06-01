/* Copyright 2025 Allery
 * @author    Allergy
 * @email     allergy527@gmail.com
 * @workspace abc 408/e.cpp
 * @date      2025-06-01 12:00:49
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
using ll = int64_t;
using PII = std::pair<int, int>;
const int inf = 0x3f3f3f3f;
const int ll_inf = 0x3f3f3f3f3f3f3f3f;

struct DSU{
    std::vector<int> fa;
    explicit DSU(int n) : fa(n) { std::iota(fa.begin(), fa.end(), 0); }
    int find(int x) {
        return fa[x] == x? x : fa[x] = find(fa[x]);
    }
    bool merge(int x, int y){
        x = find(x), y =find(y);
        if(x == y)return false;
        fa[y] = x;
        return true;
    }
    bool same(int x, int y){
        return find(x) == find(y);
    }
};


signed main(){
    std::cin.tie(nullptr) -> std::ios::sync_with_stdio(0);
    int _ = 1;

    auto solve = [&]() -> void{
        int n, m;
        std::cin >> n >> m;
        std::vector<std::tuple<int, int, int>> qwq(m);
        for(auto &[u, v, w] : qwq)std::cin >> u >> v >> w;
        int ans = (1 << 30) - 1;
        for(int i = 29; i >= 0; --i){
            ans ^= 1 << i;
            DSU qvq(n);
            for(auto [u, v, w] : qwq)
                if((ans | w) == ans)qvq.merge(u - 1, v - 1);
            if(!qvq.same(0, n - 1))ans |= 1 << i;
        }
        std::cout << ans << "\n";
    };
    while(_--)solve();
    return 0;
}


