/* Copyright 2025 Allery
 * @author    Allergy
 * @email     allergy527@gmail.com
 * @workspace 25_5_29/P1101.cpp
 * @date      2025-05-29 20:58:10
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
//    std::cin >> _;
    auto solve = [&]() -> void{
        int n, m;
        std::cin >> n;
        std::vector<std::string> qwq(n);
        for(int i =0;i<n;++i)std::cin >> qwq[i];
        
        std::array<char, 7> target = {'y', 'i', 'z', 'h', 'o', 'n', 'g'};
        

        // 7 * 8 * 100 * 100  < 1e6 ，无论怎么搜不会TLE
        auto find = [&](int x, int y, PII to){
            int cnt = 1, flag = 0;
            auto [dx, dy] = to;
            int nx = x + dx, ny = y + dy;
            while(cnt < 7){
                if(0 <= nx && nx < n && 0 <= ny && ny < n){
                    if(qwq[nx][ny] == target[cnt])++cnt;
                    else break;
                }else{
                    break;
                }
                nx += dx, ny += dy;
            }
            return cnt == 7;
        };
        
        const std::array<int,9> WAY = {-1,-1,0,1,-1,1,1,0,-1};

        std::vector vis(n, std::vector<int>(n));
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                if(qwq[i][j] == 'y'){                     //  开始找
                    for(int d = 0; d < 8; ++d){
                        if(find(i,j,{WAY[d], WAY[d+1]})){ //  如果能找到
                            for(int p = 0 ; p < 7;++p)    //  全标记上
                                vis[i + p * WAY[d]][j + p * WAY[d + 1]] = 1;
                        }
                    }
                }
        for(int i = 0; i < n;++i){
            for(int j = 0 ; j < n; ++j)std::cout << (vis[i][j] ? qwq[i][j] : '*');
            std::cout << ln;
        }
        
    };
    while(_--)solve();
    return 0;
}


