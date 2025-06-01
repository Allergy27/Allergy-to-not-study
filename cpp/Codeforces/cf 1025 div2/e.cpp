/* Copyright 2025 Allery
 * @author    Allergy
 * @email     allergy527@gmail.com
 * @workspace cf 1025 div2/e.cpp
 * @date      2025-05-29 14:50:58
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
    std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);
    int _ = 1;
    std::cin >> _;
    const int MOD = 998'244'353;
    
    auto qpow = [&](int a, int b) -> int{
        int r = 1;
        for(;b;b>>=1, a = 1LL * a * a % MOD)
            if(b & 1)r = 1LL * r * a % MOD;
        return r;
    };


    const int N = 527;
    std::vector<int> fac(N + 1,1), inv_fac(N + 1,1);
    for(int i = 1 ;i <= N ; ++ i)fac[i] = 1LL * fac[i - 1] * i % MOD;

    inv_fac[N] = qpow(fac[N], MOD - 2) % MOD;

    for(int i = N - 1; i > 0 ; --i) inv_fac[i] = 1LL * inv_fac[i + 1] * (i + 1) % MOD;

    auto comb = [&](int a, int b) -> int{
        if(a < b || b < 0) return 0;
        return 1LL * fac[a] * inv_fac[b] % MOD * inv_fac[a - b] % MOD;
    };

    auto solve = [&]() -> void{
        int n, m;
        std::cin >> n >> m;

        std::string s;
        std::cin >> s;

        std::vector<int> f(m + 1);
        f[0] = 1;
        for(int i = n - 1; i >= 0; --i){
            std::vector<int> nf(m + 1);
            for(int x = 0 ; x <= m ; ++x)
                for(int y = 0; y <= m - x ; ++y){
                    int tmp = (x + y + (s[i] == '0')) >> 1;
                    (nf[x + y] += 1LL * f[x] * comb(tmp, y) % MOD) %= MOD;
                }
            f = std::move(nf);
        }

        std::cout << f[m] << ln;
    };
    while(_--)solve();
    return 0;
}


