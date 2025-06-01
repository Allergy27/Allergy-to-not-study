#include<bits/stdc++.h>

using ll = int64_t;
using PII = std::pair<int, int>;

int main(){
    std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);
    int _ = 1;
    std::cin >> _;
    auto solve = [&]() -> void{
        ll n;
        std::cin >> n;
        auto add = [](ll x) -> int{
            std::cout << "add " << x << std::endl;
            std::cout.flush();
            int tmp;
            std::cin >> tmp;
            return tmp;
        };
        
        auto mul = [](ll x) -> int{
            std::cout << "mul " << x << std::endl;
            std::cout.flush();
            int tmp;
            std::cin >> tmp;
            return tmp;
        };

        auto div = [](ll x) -> int{
            std::cout << "div " << x << std::endl;
            std::cout.flush();
            int tmp;
            std::cin >> tmp;
            return tmp;
        };

        auto digit = []() -> void{
            std::cout << "digit" << std::endl;
            std::cout.flush();
            int tmp;
            std::cin >> tmp;
        };

        auto ans = []() -> void{
            std::cout << "!" << std::endl;
            std::cout.flush();
            int tmp;
            std::cin >> tmp;
        };
        mul(9);
        digit();
        digit();
        add(n - 9);
        ans();
    };
    while(_--)solve();
    return 0;
}

