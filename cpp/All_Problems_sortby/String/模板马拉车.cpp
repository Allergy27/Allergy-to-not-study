/* Copyright 2025 Allery
 * @author    Allergy
 * @email     allergy527@gmail.com
 * @workspace 25_6_7/5_3_Manacher_3805.cpp
 * @date      2025-06-07 17:23:51
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
        std::string s;
        std::cin >>s;
        std::string tmp = "#";
        for(auto x : s){
            tmp += x;
            tmp += '#';
        }
        s = std::move(tmp);
        const int n = s.size();
        std::vector<int> qwq(n);
        for(int i = 0, l = 0, r = -1; i < n; ++i){
            int k = (i > r) ? 1 : std::min(qwq[l + r - i], r - i + 1);
            while(0 <= i - k && i + k < n && s[i - k] == s[i + k])++k;
            qwq[i] = k--;
            if(i + k > r){
                l = i - k;
                r = i + k;
            }
        }
        int ans = 0;
        for(auto x : qwq) ans = std::max(ans, x - 1);
        std::cout << ans << '\n';
    };
    while(_--)solve();
    return 0;
}

