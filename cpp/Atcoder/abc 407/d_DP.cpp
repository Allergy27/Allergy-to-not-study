/* Copyright 2025 Allery
 * @author    Allergy
 * @email     allergy527@gmail.com
 * @workspace abc 407/d.cpp
 * @date      2025-05-31 16:58:52
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
    auto solve = [&]() -> void{
        int n, m;
        std::cin >> n >> m;
        std::vector qwq(n, std::vector<int>(m));

        for(auto &y : qwq)
            for(auto &x : y)std::cin >> x;
        
        std::vector<int> qvq{{0}};

        const int C = (1 << m) + 1, R = 3;

        for(int i = 0, bit = 0; i < n; ++i){
            for(int j = 0; j < m; ++j, ++bit){
                std::vector<int> tmp;
                for(const auto x : qvq){
                    if(j + 1 < m && !(x & R << bit))tmp.emplace_back(x | R << bit);
                    if(i + 1 < n && !(x & C << bit))tmp.emplace_back(x | C << bit);
                }
                for(auto x : tmp)qvq.emplace_back(std::move(x));
            }
        }
        
        int ans = 0;
        for(auto x : qvq){
            int now = 0;
            for(int i = 0, bit = 0; i < n; ++i)
                for(int j = 0; j < m; ++j, ++bit)
                    if(1 & ~x >> bit)now ^= qwq[i][j];
            ans = std::max(ans, now);
        }
        std::cout << ans << '\n';

    };
    while(_--)solve();
    return 0;
}

