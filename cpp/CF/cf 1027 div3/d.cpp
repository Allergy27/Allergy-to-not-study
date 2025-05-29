#include<bits/stdc++.h>

#define ln '\n'
#define judge(x) std::cout << ((x) ? "Yes\n":"No\n");

using ll = int64_t;
using PII = std::pair<int,int>;
using PLL = std::pair<int64_t,int64_t>;

int main(){
    std::ios::sync_with_stdio(false),std::cin.tie(nullptr);
    int _ = 1;
    std::cin >> _;
    const ll inf = 0x3f3f3f3f3f3f3f3f;
    auto solve = [&](){
        int n;
        std::cin >> n;
        
        std::vector<PLL> qwq(n);
        for(auto &[x, y]: qwq)std::cin >> x >> y;
        
        auto cal = [&](std::vector<PLL> a) -> ll{
            if(a.size() == 1)return 1LL;
            
            ll max_x = -inf, min_x = inf;
            ll max_y = -inf, min_y = inf;
            for(int i =1;i < n ;++i){
                auto [x, y] = a[i];
                max_x = std::max(max_x,x);
                min_x = std::min(min_x,x);
                max_y = std::max(max_y,y);
                min_y = std::min(min_y,y);
            }
            ll lx = (max_x - min_x + 1);
            ll ly = (max_y - min_y + 1);
            if(lx * ly >= n) return lx * ly;
            else return lx * ly + std::min(lx,ly);
        };
        
        ll ans = inf;

        std::sort(qwq.begin(), qwq.end());
        ans = std::min(ans, cal(qwq));
        std::reverse(qwq.begin(), qwq.end());
        ans = std::min(ans, cal(qwq));
        
        for(auto &[x,y] : qwq)x^=y,y^=x,x^=y;

        std::sort(qwq.begin(), qwq.end());
        ans = std::min(ans, cal(qwq));
        std::reverse(qwq.begin(), qwq.end());
        ans = std::min(ans, cal(qwq));
        
        std::cout <<  ans << ln;
    };
    while(_--)solve();
    return 0;
}

