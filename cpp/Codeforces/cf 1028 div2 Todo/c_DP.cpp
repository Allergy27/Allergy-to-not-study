/* Copyright 2025 Allery
 * @author    Allergy
 * @email     allergy527@gmail.com
 * @workspace cf 1028 div2/c.cpp
 * @date      2025-06-01 16:08:49
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
    const int N = 5270;
    
    std::vector GCD(N, std::vector<int>(N));
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            GCD[i][j] = std::gcd(i, j);
        }
    }

    auto solve = [&]() -> void{
        int n, m;
        std::cin >> n;
        std::vector<int> qwq(n);
        for(auto &x : qwq)std::cin >> x;
        int gcd = qwq[0];
        for(int i = 1; i < n; ++i){
            gcd = std::gcd(gcd, qwq[i]);
        }

        int cnt = std::count(qwq.begin(), qwq.end(), gcd);
        if(cnt){
            std::cout << n - cnt << "\n";return;
        }

        std::vector<int> dp(N, inf);

        dp[0] = 0;
        for(int i = 0; i < n; ++i){
            for(int x = 0; x < N; ++x){
                int y = GCD[qwq[i]][x];
                dp[y] = std::min(dp[y], dp[x] + 1);
            }
        }

        std::cout << dp[gcd] + n - 2 << "\n";
    };
    while(_--)solve();
    return 0;
}


