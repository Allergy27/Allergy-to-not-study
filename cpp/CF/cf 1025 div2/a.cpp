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
        std::vector<int> qwq(n + 2, 1);

        int tmp = 0;
        for(int i = 1; i <= n ;++i){
            std::cin >> qwq[i];
            tmp += qwq[i];
        }
        int flag = false;
        for(int i =1;i<=n;++i)
            if(qwq[i] == 0 && qwq[i + 1] == 0)flag = true;
        if(tmp == n)flag = true;
        std::cout << (flag ? "Yes\n" : "No\n");
    };
    while(_--)solve();
    return 0;
}

