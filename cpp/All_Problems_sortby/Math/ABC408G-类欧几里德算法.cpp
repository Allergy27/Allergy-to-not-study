/* Copyright 2025 Allery
 * @author    Allergy
 * @email     allergy527@gmail.com
 * @workspace abc 408/g.cpp
 * @date      2025-06-01 12:19:26
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
    
    auto solve = [](auto &&self, int a, int b, int c, int d) -> PII{
        int n = a / b;
        a -= n * b, c -= n * d;
        if(c > d) // u know, if it > 1 1/1 always satisfac
            return {n + 1, 1};
        auto [p, q] = self(self, d, c, b, a);
        return {p * n + q, p};
    };

    while(_--){
        int a, b, c, d;
        std::cin >> a >> b >> c >> d;
        std::cout << solve(solve, a, b, c, d).second << "\n";
    }
    return 0;
}


