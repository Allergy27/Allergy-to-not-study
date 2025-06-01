#include<bits/stdc++.h>

#define judge(x) std::cout << ((x) ? "Yes\n":"No\n");
using ll = int64_t;
using PII = std::pair<int, int>;

int main(){
    std::cin.tie(nullptr) -> std::ios::sync_with_stdio(false);
    int _ = 1;
    std::cin >> _;
    auto solve = [&]() -> void{
        std::string s;
        std::cin >> s;
        int n = s.size();
        std::vector<int> qwq(n);
        qwq[0] = 1;
        int cnt = 0;
        for(int i =1; i < n; ++i){
            if(s[i] == ')')qwq[i] = qwq[i-1] - 1;
            else qwq[i] = qwq[i-1] + 1;
            if(qwq[i] == 0)++cnt; 
        }
        judge(cnt > 1);
    };
    while(_--)solve();
    return 0;
}

