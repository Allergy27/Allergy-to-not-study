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
        std::sort(qwq.begin(), qwq.end());
        int maxodd = -1, minodd = -1 , maxeve = -1 , mineve = -1;
        int ans = n - 1;
        for(int i=0 ;i < n; ++i){
            if(qwq[i] & 1){
                maxodd = i;
                if(minodd == -1)minodd = i;
            }else{
                maxeve = i;
                if(mineve == -1)mineve = i;
            } 
        }
        ans = std::min(ans,n - maxodd + minodd - 1);
        ans = std::min(ans,n - maxeve + mineve - 1);
        std::cout << ans << "\n";
    };
    while(_--)solve();
    return 0;
}


