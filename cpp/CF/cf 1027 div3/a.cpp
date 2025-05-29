#include<bits/stdc++.h>

#define ln '\n'
#define judge(x) std::cout << ((x) ? "Yes\n":"No\n");

using ll = int64_t;
using PII = std::pair<int,int>;

int main(){
    std::cin.tie(nullptr)->std::ios::sync_with_stdio(false);
    int _ = 1;
    std::cin >> _;
    auto solve = [&](){
        int n, m;
        std::cin  >> n;
        int tmp = sqrtl(n);
        if(tmp * tmp == n){
            std::cout << tmp << ' ' << 0 << ln;
        }else{
            std::cout << -1 <<ln;
        }
    };
    while(_--)solve();
    return 0;
}
