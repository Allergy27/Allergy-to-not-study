/* Copyright 2025 Allery
 * @author    Allergy
 * @email     allergy527@gmail.com
 * @workspace cf 1029 div3/e.cpp
 * @date      2025-06-09 12:59:02
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
        std::cin >> n;
        std::vector<int> a(n), b(n);
        for(auto &x : a)std::cin >> x;
        for(auto &x : b)std::cin >> x;
        
        int ans = (a[n - 1] == b[n - 1] ? n - 1 : -1);
        std::vector<bool> qwq(n + 1);
        for(int i = n - 2; i >= 0; --i){
            if(a[i] == b[i]) ans = std::max(ans, i);
            if(a[i] == a[i + 1] || b[i] == b[i + 1]) ans = std::max(ans, i);
            if(qwq[a[i]] || qwq[b[i]]) ans = std::max(ans, i);
            qwq[a[i + 1]] = qwq[b[i + 1]] = true;
        }
        
        std::cout << ans + 1 << '\n';
    };
    while(_--)solve();
    return 0;
}

