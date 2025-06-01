/* Copyright 2025 Allery
 * @author    Allergy
 * @email     allergy527@gmail.com
 * @workspace 25_5_29/P1162.cpp
 * @date      2025-05-29 20:29:27
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
        int n, m;
        std::cin >> n;
        std::vector qwq(n + 1, std::vector<int>(n + 1, 1));
        for(int i = 1; i <= n; ++i) for(int j = 1; j <= n; ++j) std::cin >> qwq[i][j];
        
        std::queue<PII> que;
        for(int i = 1; i < n; ++i){
            que.push({i, 0});
            que.push({i, n + 1});
            que.push({0, i});
            que.push({n + 1, i});
        }
        
        std::array<int, 5> way = {-1, 0, 1, 0, -1};

        while(!que.empty()){
            auto [x, y] = que.front();
            que.pop();
            for(int i = 0; i < n; ++i){
                int nx = x + way[i], ny = y + way[i + 1];
                if(0 <= nx && nx <= n && 0 <= ny && ny <= n){
                    if(qwq[nx][ny] > 0)continue;
                    else qwq[nx][ny] = 2, que.push({nx,ny});
                }
            }
        }
        
        for(int i = 1; i <= n; ++i){ 
            for(int j = 1; j <= n; ++j)
                std::cout << 2 - qwq[i][j] << ' ';
            std::cout << ln;
        }
    };
    while(_--)solve();
    return 0;
}


