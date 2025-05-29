#include<bits/stdc++.h>

using ll = int64_t;
using PII = std::pair<int, int>;

int main(){
    std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);
    int _ = 1;
    std::cin >> _;
    const int INF = 0x3f3f3f3f;
    auto solve = [&]() -> void{
        int n, m;
        std::cin >> n >> m;
        std::vector<int> qvq(n);
        for(auto &x:qvq)std::cin >> x;
        std::vector<std::vector<PII>> qwq(n);
        for(int i= 0;i<m; ++i){
            int s, t, w;
            std::cin >> s >> t >> w;
            --s,--t;
            qwq[s].push_back({t , w});
        }
        
        auto check = [&](int x) -> bool{
            std::vector<int> dis(n);
            for(int i = 0;i<n;++i){
                if(i > 0 && dis[i] == 0)continue;
                dis[i] += qvq[i];
                dis[i] = std::min(dis[i] , x);
                for(auto [v,w]: qwq[i]){
                    if(w <= dis[i])dis[v] = std::max(dis[v] , dis[i]);
                }
            }
            return (dis.back() > 0);
        };

        if(!check(INF)){
            std::cout << -1 << '\n';
            return;
        }
        int l = 0 , r = INF;
        while(l < r){
            int m = l + r >> 1;
            if(check(m)){
                r = m ;
            }else{
                l = m + 1 ;
            }
        }
        std::cout << l << "\n";
    };
    while(_--)solve();
    return 0;
}


