/* Copyright 2025 Allery
 * @author    Allergy
 * @email     allergy527@gmail.com
 * @workspace 25_5_31/8_5_TopSort_P1113.cpp
 * @date      2025-05-31 19:55:44
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

    auto solve = [&]() -> void{
        int n;
        std::cin >> n;
        std::vector qwq(n, std::vector<int>());
        
        std::vector<int> qvq(n), in(n);
        for(int i = 0; i < n; ++i){
            int x;
            std::cin >> x;
            std::cin >> x;
            qvq[i] = x;
            while(std::cin >> x){
                if(x == 0)break;
                ++in[i];
                qwq[x - 1].emplace_back(i);
            }
        }
        std::queue<int> que;
        for(int i = 0; i < n; ++i){
            if(in[i] == 0) que.push(i);
        }

        std::vector<int> cnt(n);
        cnt[0] = qvq[0];
        int ans = 0;
        while(!que.empty()){
            int u = que.front();
            que.pop();
            for(auto v : qwq[u]){
                cnt[v] = std::max(cnt[v], cnt[u] + qvq[v]);
                ans = std::max(ans, cnt[v]);
                if(--in[v] == 0)que.push(v);
            }
        }
        std::cout << ans << "\n";
    };
    while(_--)solve();
    return 0;
}

