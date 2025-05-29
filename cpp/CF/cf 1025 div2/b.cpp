#include<bits/stdc++.h>

using ll = int64_t;
using PII = std::pair<int, int>;

int main(){
    std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);
    int _ = 1;
    std::cin >> _;
    std::vector<int> pow2(32 , 1);
    for(int i = 1; i < 32 ; ++i) pow2[i] = pow2[i - 1] * 2;

    auto solve = [&]() -> void{
        int n, m , a, b;
        std::cin >> n >> m >>  a >> b;
        
        std::vector<PII> qwq;
        qwq.push_back({a, m});
        qwq.push_back({n - a + 1, m}); 
        qwq.push_back({n, b});
        qwq.push_back({n, m - b  + 1});
        
        int ans = n + m;
        for(auto [x, y] : qwq){
            int tmp = 0;
            while(x > 1){
                ++tmp;
                x = x + 1 >> 1;
            }
            while(y > 1){
                ++tmp;
                y = y + 1 >> 1;
            }
            ans = std::min(ans, tmp);
        }

        std::cout << ans + 1 << "\n";
        
    };
    while(_--)solve();
    return 0;
}

