#include<bits/stdc++.h>

using ll = int64_t;
using PII = std::pair<int, int>;

int main(){
    std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);
    int _ = 1;
    std::cin >> _;
    auto solve = [&]() -> void{
        int n, m;
        std::cin >> n;
        std::vector<int> qwq(n);
        for(auto &x:qwq)std::cin >> x;

        auto f = [](int x, int y){
            return x%y + y%x;
        };

        int mx = 0,ans = 0;
        for(int i = 0 ;i < n; ++i){
            int x = qwq[i];
            if (x <= mx ) ans = std::max(ans, f(x, mx));
            else if(x < 2 * mx) ans = std::max(ans, x);
            else for(int j = 0 ; j < i; ++j)ans = std::max(ans, f(x, qwq[j]));
            mx = std::max(mx, x);
            std::cout << ans << ' ';
        }
        std::cout << "\n";
    };
    while(_--)solve();
    return 0;
}


