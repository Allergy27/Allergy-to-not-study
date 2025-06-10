/* Copyright 2025 Allery
 * @author    Allergy
 * @email     allergy527@gmail.com
 * @workspace cf 1028 div2/b.cpp
 * @date      2025-06-01 15:39:08
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
    const int N = 1e5 + 27;
    const int MOD = 998'244'353;
    std::vector<int> qpow(N, 1);
    
    for(int i = 1; i < N; ++i)qpow[i] = (qpow[i - 1] << 1) % MOD;

    auto solve = [&]() -> void{
        int n, m;
        std::cin >> n;
        std::vector<int> qwq(n), qvq(n);

        for(auto &x : qwq)std::cin >> x;
        for(auto &x : qvq)std::cin >> x;

        std::vector<int> mxw(n), mxv(n);

        for(int i = 1; i < n; ++i){
            mxw[i] = qwq[i] > qwq[mxw[i - 1]] ? i : mxw[i - 1];
            mxv[i] = qvq[i] > qvq[mxv[i - 1]] ? i : mxv[i - 1];
        }

        for(int i = 0; i < n; ++i){
            int tmpa = qwq[mxw[i]], tmpb = qvq[mxv[i]];
            int tmpw = qvq[i - mxw[i]], tmpv = qwq[i - mxv[i]];
            if(tmpa != tmpb){
                if(tmpa > tmpb){
                    std::cout << (qpow[tmpa] + qpow[tmpw]) % MOD << " ";
                }else{
                    std::cout << (qpow[tmpb] + qpow[tmpv]) % MOD << " ";
                }
            }else{
                if(tmpa + tmpw > tmpb + tmpv){
                    std::cout << (qpow[tmpa] + qpow[tmpw]) % MOD << " ";
                }else{
                    std::cout << (qpow[tmpb] + qpow[tmpv]) % MOD << " ";
                }
            }

        }
        std::cout << '\n';

    };
    while(_--)solve();
    return 0;
}


