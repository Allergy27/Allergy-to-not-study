/* Copyright 2025 Allery
 * @author    Allergy
 * @email     allergy527@gmail.com
 * @workspace cf 1028 div2/d.cpp
 * @date      2025-06-01 16:51:55
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

signed main(){
    std::cin.tie(nullptr) -> std::ios::sync_with_stdio(0);
    int _ = 1;
    std::cin >> _;
    auto solve = [&]() -> void{
        int n, m;
        std::cin >> n >> m;
        std::vector<int> qwq(n);
        for(auto &x : qwq)std::cin >> x;

        std::vector<int> p(n);
        std::iota(p.begin(), p.end(), 0);
        std::vector<std::array<int, 3>> op(m);
        std::vector<int> u(m), v(m);
        for(int i = 0; i < m; ++i){
            int x, y, z;
            std::cin >> x >> y >> z;
            --x, --y, --z;
            op[i] = {x, y, z};
            u[i] = p[x];
            v[i] = p[y];
            p[z] = n + i;
        }

        std::vector<int> ans(n + m);
        for(int i = 0; i < n; ++i) ans[p[i]] = qwq[i];
        
        for(int i = n + m - 1; i >= n; --i){
            ans[u[i - n]] = std::max(ans[u[i - n]], ans[i]);
            ans[v[i - n]] = std::max(ans[v[i - n]], ans[i]);
        }
        ans.resize(n);
        auto tmp = ans;
        for(auto [x, y, z] : op) tmp[z] = std::min(tmp[x], tmp[y]);
        
        if(tmp != qwq){ // not same
            std::cout << -1 << "\n";
            return;
        }
        for(int i = 0; i < n; ++i)std::cout << ans[i] << " \n"[i == n - 1];
    };
    while(_--)solve();
    return 0;
}

