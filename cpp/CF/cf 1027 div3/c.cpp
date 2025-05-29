#include<bits/stdc++.h>

#define ln '\n'
#define judge(x) std::cout << ((x) ? "Yes\n":"No\n");

using ll = int64_t;
using PII = std::pair<int,int>;
int main(){
    std::ios::sync_with_stdio(false),std::cin.tie(nullptr);
    int _ = 1;
    std::cin >> _;
    auto solve = [&](){
        int n, m;
        std::cin >> n;
        std::vector<int> qwq(n);
        for(auto &x : qwq)std::cin >> x;
        int ans = 1, pre = qwq[0];
        for(int i = 0;i < n; ++i){
            if(qwq[i] > pre + 1)++ans, pre = qwq[i];
        }
        std::cout << ans << ln;
    };
    while(_--)solve();
    return 0;
}
