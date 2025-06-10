/* Copyright 2025 Allery
 * @author    Allergy
 * @email     allergy527@gmail.com
 * @workspace cf edu 179/c.cpp
 * @date      2025-06-04 15:41:09
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
        int n;
        std::cin >> n;
        std::vector<int> qvq(n + 1);
        qvq[n] = -1;
        std::vector<std::array<int, 3>> qwq;
        std::array<int, 3> pre = {qvq[0], 0, 0};
        for(int i =0; i <= n; ++i){
            if(i != n)std::cin >> qvq[i]; 
            if(i == 0)pre[0] = qvq[0];
            if(qvq[i] == pre[0]){
                pre[2] = i;
            }
            else {
                qwq.emplace_back(pre);
                pre = {qvq[i], i, i};
            }
        }
        int ans = ll_inf;
        for(auto [v, x, y] : qwq)ans = std::min(ans, v * x + (n - y - 1) * v);
        std::cout << ans << '\n';
    };
    while(_--)solve();
    return 0;
}

