/* Copyright 2025 Allery
 * @author    Allergy
 * @email     allergy527@gmail.com
 * @workspace abc 404/b.cpp
 * @date      2025-06-05 19:22:38
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
        int n;
        std::cin >> n;
        std::vector<std::string> s(n);
        std::vector<std::string> t(n);
        for(auto &x : s)std::cin >> x;
        for(auto &x : t)std::cin >> x;
        auto trans = [&](std::vector<std::string> pre){
            auto tmp = pre;
            for(int i =0; i<n;++i) for(int j =0 ;j < n; ++j) tmp[i][j] = pre[n - 1 - j][i];
            return tmp;
        };

        auto count = [&](std::vector<std::string> a, std::vector<std::string> b) -> int{
            int ans = 0;
            for(int i = 0; i < n; ++i)
                for(int j = 0; j < n; ++j)
                    ans += a[i][j] != b[i][j];
            return ans;
        };
        
        int ans = ll_inf;
        for(int i = 0; i < 4; ++i){
            ans = std::min(ans, count(s, t) + i);
            s = trans(s);
        }
        std::cout << ans << '\n';
    };
    while(_--)solve();
    return 0;
}

