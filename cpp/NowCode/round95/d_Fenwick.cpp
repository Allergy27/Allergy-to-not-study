/* Copyright 2025 Allery
 * @author    Allergy
 * @email     allergy527@gmail.com
 * @workspace round95/d.cpp
 * @date      2025-06-08 19:30:12
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
        const int N = 3e5 + 27;
        std::vector<int> qwq(N);
        auto add = [&](int x, int v){
            for(int i = x + 1; i <= n; i += lowbit(i)){
                qwq[i - 1] += v;
            }
        };
        auto sum = [&](int x) -> i64{
            i64 ans = 0;
            for(int i = x; i > 0 ; i -= lowbit(i)){
                ans += qwq[i - 1];
            }
            return ans;
        };

        auto query = [&](int l, int r){
            return sum(r) - sum(l);
        };

        int ans = 1;
        for(int i = 0; i < n; ++i){
            int l, r;
            std::cin >> l >> r;
            if(query(l, r) == 0){
                add(l, 1), add(r, 1);
                ans = std::max(r - l + 2, ans);
            }
            std::cout << ans << ln;
        }
    };
    while(_--)solve();
    return 0;
}

