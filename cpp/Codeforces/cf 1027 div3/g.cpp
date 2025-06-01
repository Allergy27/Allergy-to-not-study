#include<bits/stdc++.h>

#define ln '\n'
#define lowbit(x) ((x) & -(x))
#define judge(x) std::cout << ((x) ? "Yes\n":"No\n");

using ll = int64_t;
using PII = std::pair<int,int>;

signed main(){
    std::ios::sync_with_stdio(false),std::cin.tie(nullptr);
    int _ = 1;
    std::cin >> _;

    auto solve = [&](){
        int n, m;
        std::cin  >> n  >> m;
        std::vector<int> qwq(n),z(n), res(n);
        for(int i =0 ;i < n; ++i){
            std::cin >> qwq[i];
            z[i] = (qwq[i]) & (-qwq[i]);
            res[i] = qwq[i] / z[i];
        }
        std::vector<ll>pre(n + 1) , suf(n + 1);

        for(int i = 0; i < n; ++i){
            ll tmp;
            if(i <= n - 2 && res[i] == res[i + 1] && qwq[i] > qwq[i + 1])
                tmp = z[i] - (z[i + 1] << 1) + 1;
            else
                tmp = z[i];
            pre[i + 1] = pre[i] + tmp; 
        }
        
        for(int i = n - 1; i >= 0; --i){
            ll tmp;
            if(i - 1 >= 0 && res[i] == res[i - 1] && qwq[i] > qwq[i - 1])
                tmp = z[i] - (z[i - 1] << 1) + 1;
            else
                tmp = z[i];
            suf[i] = suf[i + 1] + tmp; 
        }

        ll ans = std::max(pre[n] , suf[0]);

        for(int i = 0 ;i < n - 1;++i){
            ll tmp = pre[i] + z[i] + suf[i + 1];
            ans = std::max(ans, tmp);
        }

        judge(ans >= m);
    };
    while(_--)solve();
    return 0;
}

