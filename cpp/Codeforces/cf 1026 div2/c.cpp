#include<bits/stdc++.h>

using ll = int64_t;
using PII = std::pair<int, int>;

int main(){
    std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);
    int _ = 1;
    std::cin >> _;
    auto solve = [&]() -> void{
        int n, m;
        std::cin >> n ;
        std::vector<int> qwq(n);
        for(auto &x : qwq)std::cin >> x;
        
        std::vector<PII> h(n);
        for(auto &[x,y] : h)std::cin >> x >> y;

        int nl = 0;
        std::stack<int> stk;
        for(int i=0 ;i<n; ++i){
            if(qwq[i] == -1)
                stk.push(i);
            else
                nl += qwq[i];
            

            auto [x, y] = h[i];
            while(nl < x){
                if(stk.empty()){
                    std::cout << -1 << "\n";
                    return;
                }
                qwq[stk.top()] = 1;
                ++nl;
                stk.pop();
            }
            while(nl + (stk.size()) > y){
                if(stk.empty()){
                    std::cout << -1 << "\n";
                    return;
                }
                qwq[stk.top()] = 0;
                stk.pop();
            }
        }
        for(auto x:qwq)std::cout << std::max(x,0) << ' '; std::cout << "\n";
    };
    while(_--)solve();
    return 0;
}


