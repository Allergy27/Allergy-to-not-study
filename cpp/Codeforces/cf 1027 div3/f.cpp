#include<bits/stdc++.h>

#define ln '\n'
#define judge(x) std::cout << ((x) ? "Yes\n":"No\n");

using ll = int64_t;
using PII = std::pair<int,int>;

int main(){
    std::ios::sync_with_stdio(false),std::cin.tie(nullptr);
    int _ = 1;
    std::cin >> _;
    
    const int N = 1e6 + 5;
    std::vector<std::vector<ll>> FAC(N);
    for(int i =1;i<N;++i)for(int j = i;j < N;j += i)FAC[j].emplace_back(i);
    
    const ll ll_inf = 1e18;

    auto solve = [&](){
        ll x, y, k;
        std::cin  >> x  >> y >> k;
        ll lcm = x * y / std::__gcd(x,y);
        auto f = [&](ll n) -> ll{
            ll len = FAC[n].size();
            std::vector<ll> dp(len,ll_inf);
            dp[0] = 0;
            for(int i=1;i<len;++i){
                for(int j=0; j < i ; ++j){
                    if(FAC[n][i] % FAC[n][j] == 0 && FAC[n][i] <= FAC[n][j] * k){
                        dp[i] = std::min(dp[i] , dp[j] + 1);
                    }
                }
            }
            return dp.back();
        };
        ll ans = f(lcm/x) + f(lcm/y);
        if(ans > ll_inf/10)std::cout << -1 <<ln;
        else std::cout << ans << ln;
    };
    while(_--)solve();
    return 0;
}
