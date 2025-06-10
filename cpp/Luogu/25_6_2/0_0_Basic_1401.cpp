/* Copyright 2025 Allery
 * @author    Allergy
 * @email     allergy527@gmail.com
 * @workspace 25_6_2/0_0_Basic_1401.cpp
 * @date      2025-06-02 15:16:25
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

#define ln '\n'
#define judge(x) std::cout << ((x) ? "Yes\n" : "No\n");
#define lowbit(x) ((x)&-(x))
using ll = int64_t;
using PII = std::pair<int, int>;
const int inf = 0x3f3f3f3f;
const ll ll_inf = 0x3f3f3f3f3f3f3f3f;

signed main(){
    std::cin.tie(nullptr) -> std::ios::sync_with_stdio(0);
    int _ = 1;

    auto solve = [&]() -> void{
        int x1, x2, y1, y2;

        std::cin >> x1 >> x2;
        std::cin >> y1 >> y2;
        
        const int L = (1 << 31);
        auto f = [](int x, int y) -> bool{
            ll tmp = 1LL * x * y;
            #pragma GCC diagnostic push
            #pragma GCC diagnostic ignored "-Woverflow"
            return (L <= tmp && tmp <= L - 1);
            #pragma GCC diagnostic pop
        };

        bool flag = true;
        flag = flag and f(x1, y1);
        flag = flag and f(x1, y2);
        flag = flag and f(x2, y1);
        flag = flag and f(x2, y2);
        if(flag)std::cout << "int\n";
        else std::cout << "long long int\n";
    };
    while(_--)solve();
    return 0;
}

